/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:11:26 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 18:07:56 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

t_block	*split_block(t_block *block, size_t size)
{
	t_block		*new;

	check_align(size);
	if (!block || block->size <= size + BLOCK_SIZE)
		return(NULL);
	new = get_data(block) + size;
	set_extra(new, block->size - size - BLOCK_SIZE, block->next, block, 1);
	block->next = new;
	block->size = size;
	return (new);
}