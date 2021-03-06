/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:32:39 by gpaeng            #+#    #+#             */
/*   Updated: 2022/02/21 16:57:23 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "mush/builtin.h"

int	builtin_pwd(t_state *state, int argc, char *argv[])
{
	char	*pwd;

	(void)state;
	(void)argv;
	if (argc > 1)
	{
		ft_dputs(2, "pwd: too many arguments\n");
		return (1);
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		mush_fatal("getcwd");
	ft_putendl(pwd);
	free(pwd);
	return (0);
}
