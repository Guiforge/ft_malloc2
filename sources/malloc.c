/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:56:29 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 15:58:53 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global		g_malloc;

void		*malloc(size_t size)
{
	t_block	*ptr_alloc;
	size_t	s;

	ptr_alloc = NULL;
	init_zones();
	s = ft_align(size, 16);
	malloc_pthread_lock(g_malloc.mutex);
	if (s <= TINY_MAX)
		ptr_alloc = create_alloc(g_malloc.tiny, s);
	if (s <= MEDIUM_MAX && ptr_alloc == NULL)
		ptr_alloc = create_alloc(g_malloc.medium, s);
	if (ptr_alloc == NULL)
		ptr_alloc = link_new_zone(&(g_malloc.large), s);
	if (ptr_alloc)
		ptr_alloc->free = 0;
	malloc_pthread_unlock(g_malloc.mutex);
	return (get_data(ptr_alloc));
}
