/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:22:44 by SSONG             #+#    #+#             */
/*   Updated: 2022/02/21 03:27:51 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/is.h"

int	ft_isprint(int c)
{
	return ((unsigned char)c >= 0x20 && (unsigned char)c <= 0x7e);
}
