/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:56:29 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/03 14:43:05 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

// extern t_malloc_global		g_malloc;

t_malloc_global		g_malloc = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	0,
	PTHREAD_MUTEX_INITIALIZER
};

void		*malloc(size_t size)
{
	t_block	*ptr_alloc;
	size_t	s;

	ptr_alloc = NULL;
	s = ft_align(size, 16);
	malloc_pthread_lock(g_malloc.mutex);
	init_zones();
	if (s <= TINY_MAX)
		ptr_alloc = create_alloc(g_malloc.tiny, s);
	if (s <= MEDIUM_MAX && ptr_alloc == NULL)
		ptr_alloc = create_alloc(g_malloc.medium, s);
	if (ptr_alloc == NULL)
		ptr_alloc = link_new_zone(&(g_malloc.large), s + BLOCK_SIZE);
	if (ptr_alloc)
		ptr_alloc->free = 0;
	malloc_pthread_unlock(g_malloc.mutex);
	return (get_data(ptr_alloc));
}
