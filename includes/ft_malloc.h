/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:16:09 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 19:11:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft/includes/libft.h"
# include "./intern_malloc.h"

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	*reallocf(void *ptr, size_t size);
void	*calloc(size_t nmemb, size_t size);
void	show_alloc_mem(void);
bool	show_alloc_data(void *ptr, int print_char);

#endif
