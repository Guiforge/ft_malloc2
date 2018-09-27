/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:16:09 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 16:16:35 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define PCHAR_DATA 1
# define PHEX_DATA 2

# include <stddef.h>

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	*reallocf(void *ptr, size_t size);
void	*calloc(size_t nmemb, size_t size);
void	show_alloc_mem(void);
int		show_alloc_data(void *ptr, int print_char);

#endif
