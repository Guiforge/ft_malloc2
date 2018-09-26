/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:08:44 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 18:22:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

static t_block		*reduce_block(t_block *block, size_t new_size)
{
	t_block		*new;

	if (block->size - new_size >= (BLOCK_SIZE)) // maybe block_size + 16
	{
		new = split_block(block, new_size);
		if (new)
		{
			fusion(new);
			return (block);
		}
	}
	return (NULL);
}

static t_block	*grow_up_block(t_block *block, size_t new_size)
{
	if (!block->next || !block->next->free ||
		!((block->size + BLOCK_SIZE + block->next->size) >= new_size))
		return (NULL);
	fusion(block);
	if (block->size - new_size >= (BLOCK_SIZE)) // maybe block_size + 16
		split_block(block, new_size);
	return (block);
}

t_block		*resize_block(t_block *block, size_t new_size)
{
	check_align(new_size);
	if (new_size < block->size)
		return (reduce_block(block, new_size));
	else if (new_size > block->size)
		return (grow_up_block(block, new_size - block->size));
	else
		return (block);
	return (NULL);
}