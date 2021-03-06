/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:08:07 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/21 13:49:21 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h>

typedef struct s_array {
	void	**data;
	size_t	len;
	size_t	cap;
}	t_array;

int		hx_array_secure(t_array *array, size_t new_cap);
int		hx_array_push(t_array *array, void *value);
void	hx_array_cleanup(t_array *array);
void	*hx_array_pop_index(t_array *array, size_t i);

#endif
