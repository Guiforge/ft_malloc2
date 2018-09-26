/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:36:53 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 20:42:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"
#include "../../includes/malloc_error.h"

t_block		*link_new_zone(t_block **zone, size_t size)
{
	t_block		*b;
	t_block		*new;

	b = *zone;
	while (b && b->next)
		b = b->next;
	new = create_zone(size);
	if (!b)
		*zone = new;
	else
	{
		b->next = new;
		new->previous = b;
	}
	return (new);
}

t_block		*link_destroy_zone(t_block **zone, t_block *block)
{
	t_block		*b;

	b = *zone;
	while (b && b != block)
		b = b->next;
	if (b != block)
		return (NULL);
	if (b->next)
		b->next->previous = b->previous;
	if (b->previous)
		b->previous->next = b->next;
	if (*zone == b)
		*zone = b->next;
	if (munmap(block, block->size + BLOCK_SIZE) == -1)
		malloc_error(E_INTERN_MALLOC_MUNMAP_FAIL);
	return (*zone);
}