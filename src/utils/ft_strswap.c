/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:31:07 by gpaeng            #+#    #+#             */
/*   Updated: 2022/02/15 20:57:46 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strswap(char **str1, char **str2)
{
	char *tmp;

	if (!str1 || !str2)
		return ;
	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}