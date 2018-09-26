/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:56:29 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 20:05:58 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global		g_malloc;


void	*malloc(size_t size)
{
	t_block	*ptr_alloc;
	size_t	s;

	ptr_alloc = NULL;
	init_zones();
	s = ft_align(size, 16);
	if (s <= TINY_MAX)
		ptr_alloc = create_alloc(g_malloc.tiny, s);
	if (s <= MEDIUM_MAX && ptr_alloc == NULL)
		ptr_alloc = create_alloc(g_malloc.medium, s);
	if (ptr_alloc == NULL)
	{
		ptr_alloc = link_new_zone(&(g_malloc.large), s);
	}
	#include <assert.h>	
	assert(!((long)get_data(ptr_alloc) % 16));
	return (get_data(ptr_alloc));
}