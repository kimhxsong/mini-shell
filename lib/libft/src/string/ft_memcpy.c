/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:50:14 by SSONG             #+#    #+#             */
/*   Updated: 2022/02/21 03:25:25 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (dst);
}
