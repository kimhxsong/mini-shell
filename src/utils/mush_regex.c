/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mush_regex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:17:49 by gpaeng            #+#    #+#             */
/*   Updated: 2022/02/17 01:55:58 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mush/builtin.h"
#include "libft.h"

int	ft_str_digit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_key_value_form(int i, int j, char *args[])
{
	if (j == 0 || j > (int)ft_strlen(args[i]) - 1)
	{
		if (!ft_str_digit_check(args[i]))
		{
			printf("minishell: export: \'%s\': not a valid identifier\n", args[i]);
		}
		return (1);
	}
	return (0);
}

int	ft_check_key_form(int i, int j, char *args[])
{
	char	*path_name;

	path_name = (char *)ft_calloc(sizeof(char), j + 1);
	ft_strlcpy(path_name, args[i], j + 1);
	if (!ft_str_digit_check(path_name))
	{
		printf("minishell: export: \'%s\': not a valid identifier\n", args[i]);
		return (1);
	}
	free(path_name);
	return (0);
}

int	mush_regex(char *args[])
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = ft_chrspn(args[i], '=');
		if (ft_check_key_value_form(i, j, args))
			return (0);
		if (ft_check_key_form(i, j, args))
			return (0);
		i++;
	}
	return (1);
}