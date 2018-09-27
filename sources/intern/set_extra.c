/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:25:49 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 16:14:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

void	set_extra(t_block *block, size_t size, t_block *next, t_block *previous)
{
	check_align((size_t)block);
	block->size = size;
	block->next = next;
	block->previous = previous;
	block->free = 1;
}
