/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:31:28 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/22 00:03:50 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/errno.h>
#include <string.h>
#include "libfthx.h"
#include "mush/front.h"
#include "mush/builtin.h"
#include "mush/exec.h"

static void	exec_proc_pipe_init(t_proc **procs, int pipe_fd[2])
{
	if (pipe(pipe_fd) < 0)
		mush_fatal("pipe");
	procs[0]->stdout = pipe_fd[1];
	procs[1]->stdin = pipe_fd[0];
	return ;
}

static void	exec_proc_pipe_redirection(t_proc *proc, int toclose)
{
	if (proc->stdin != STDIN_FILENO)
	{
		dup2(proc->stdin, STDIN_FILENO);
		close(proc->stdin);
	}
	if (proc->stdout != STDOUT_FILENO)
	{
		dup2(proc->stdout, STDOUT_FILENO);
		close(proc->stdout);
	}
	close(toclose);
	return ;
}

static void	exec_run_on_child(t_state *state, t_proc *proc, int toclose)
{
	mush_signal_restored();
	exec_proc_pipe_redirection(proc, toclose);
	if (exec_proc_iofile_redirect(state, &proc->io_files) < 0)
		exit(1);
	if (proc->fn_builtin != NULL)
		exit(proc->fn_builtin(state, proc->argv.len, \
			(char **)proc->argv.data));
	proc->name = exec_expn_cmd(state, (char *)proc->argv.data[0]);
	if (proc->name == NULL)
	{
		mush_error((char *)proc->argv.data[0], "command not found");
		exit(127);
	}
	execve(proc->name, (char **)proc->argv.data, \
		(char **)state->envlist.data);
	mush_error(proc->name, strerror(errno));
	if (errno == ENOEXEC || errno == EACCES)
		exit(126);
	exit(127);
	return ;
}

static void	exec_run_simple_command(t_state *state, t_proc *proc, \
	int toclose)
{
	size_t	len;
	pid_t	pid;

	len = state->job.pipeline.len;
	exec_expn_argv(state, &proc->argv);
	if (builtin_search(proc) == 1 && len == 1)
	{
		mush_exec_builtin(state);
		free(state->last_status);
		state->last_status = ft_itoa(state->job.status);
		if (state->last_status == NULL)
			mush_fatal("malloc");
		state->job.is_completed = 1;
		return ;
	}
	else
	{
		pid = fork();
		if (pid < 0)
			mush_fatal("fork");
		if (pid == 0)
			exec_run_on_child(state, proc, toclose);
		proc->pid = pid;
	}
	return ;
}

void	mush_execute(t_state *state)
{
	t_proc		**procs;
	int			pipe_fd[2];
	size_t		len;
	size_t		i;

	procs = (t_proc **)state->job.pipeline.data;
	pipe_fd[0] = -1;
	len = state->job.pipeline.len;
	i = 0;
	while (i < len - 1)
	{
		exec_proc_pipe_init(&procs[i], pipe_fd);
		exec_run_simple_command(state, procs[i], pipe_fd[0]);
		if (procs[i]->stdin != STDIN_FILENO)
			close(procs[i]->stdin);
		close(procs[i++]->stdout);
	}
	exec_run_simple_command(state, procs[i], pipe_fd[0]);
	if (pipe_fd[0] != -1)
		close(procs[i]->stdin);
	while (state->job.is_completed == 0)
		continue ;
	mush_cleanup_pipeline(&state->job.pipeline);
	state->job.is_completed = 0;
	return ;
}
