/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 01:10:22 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/21 03:29:21 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/string.h"
#include "libft/io.h"

int	ft_putendl(const char *s)
{
	return (write(1, s, ft_strlen(s)) + write(1, "\n", 1));
}
