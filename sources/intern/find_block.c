/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:45:48 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 15:25:45 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"
#include "../../includes/malloc_error.h"

t_block		*find_block_free(t_block *zone, size_t size)
{
	t_block		*b;

	b = zone;
	check_align(size);
	while (b && !(b->free && b->size >= size))
	{
		b = b->next;
	}
	return (b);
}

t_block		*find_block(t_block *zone, t_block *block, int free)
{
	t_block		*b;

	b = zone;
	while (b && b <= block)
	{
		if (b == block && b->free == free)
			return (b);
		b = b->next;
	}
	return (NULL);
}