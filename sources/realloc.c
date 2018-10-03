/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:30:22 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/03 14:51:06 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global g_malloc;

void		*realloc(void *ptr, size_t size)
{
	t_block	*block;
	t_block	*zone;

	if (!ptr)
		return (malloc(size));
	malloc_pthread_lock(g_malloc.mutex);
	zone = is_valid_addr(ptr);
	malloc_pthread_unlock(g_malloc.mutex);
	if (!zone)
	{
		return (NULL);
	}
	malloc_pthread_lock(g_malloc.mutex);
	block = resize_block(get_block(ptr), ft_align(size, 16));
	malloc_pthread_unlock(g_malloc.mutex);
	if (block)
	{
		return (get_data(block));
	}
	if ((block = malloc(size)))
	{
		malloc_pthread_lock(g_malloc.mutex);
		block = get_block(block);
		copy_block(get_block(ptr), block);
		malloc_pthread_unlock(g_malloc.mutex);
		free(ptr);
		block = get_data(block);
	}
	return (block);
}

void		*reallocf(void *p, size_t size)
{
	void	*newp;

	newp = realloc(p, size);
	if (!newp)
		free(p);
	return (newp);
}
