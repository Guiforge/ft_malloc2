/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:11:26 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 16:57:44 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

t_block	*split_block(t_block *block, size_t size)
{
	t_block		*new;

	check_align(size);
	if (!block || block->free == 0 || block->size <= size + BLOCK_SIZE)
		return(NULL);
	new = get_data(block) + size;
	new->next = block->next;
	new->size = block->size - size - BLOCK_SIZE;
	new->previous = block;
	new->free = 1;
	block->next = new;
	block->size = size;
	return (new);
}