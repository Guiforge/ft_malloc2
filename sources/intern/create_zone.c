/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:17:10 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 16:13:50 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/malloc_error.h"
#include "../../includes/intern_malloc.h"

t_block			*create_zone(size_t size)
{
	t_block		*zone;
	size_t		size_zone;

	size_zone = ft_align(size, getpagesize());
	zone = mmap(NULL, size_zone, MALLOC_FLAG_MMAP_RW,
			MALLOC_FLAG_MMAP_MAP, -1, 0);
	if (zone == (void *)-1)
	{
		malloc_error(E_INTERN_MALLOC_CANT_ALLOC);
		return (NULL);
	}
	set_extra(zone, size_zone - BLOCK_SIZE, NULL, NULL);
	zone->free = 1;
	return (zone);
}
