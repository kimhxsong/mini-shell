/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:53:53 by gpaeng            #+#    #+#             */
/*   Updated: 2021/11/11 15:30:09 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define UNUSED(x) (void)(x)
#include <stddef.h>
#include <stdlib.h>

/*
**utils
*/
size_t ft_strlen(const char *str);
void *ft_memcpy(void *dest, const void *src, size_t n);
char **ft_split(char const *s, char c);
char *ft_strdup(const char *str);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcpy(char *dest, const char *src, size_t size);

/*
**ft_echo.c
*/
void ft_echo(char *args[]);

/*
**ft_pwd.c
*/
void ft_pwd(char *args[]);

/*
**ft_cd.c
*/
void ft_cd(char *args[]);

#endif