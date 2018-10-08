/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defrag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:36:30 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/08 11:48:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

void			fusion(t_block *b)
{
	if (b->next && b->next->free)
	{
		b->size += BLOCK_SIZE + b->next->size;
		b->next = b->next->next;
		if (b->next)
			b->next->previous = b;
	}
}

void			defrag(t_block *zone)
{
	t_block		*b;

	b = zone;
	while (b)
	{
		if (b->free)
			fusion(b);
		b = b->next;
	}
}

void			defrag_next(t_block *b)
{
	t_block		*last;

	last = b;
	if (!b)
		return ;
	while (last->next && last->next->free)
		last = last->next;
	if (last == b)
		return ;
	b->size = last - b + BLOCK_SIZE;
	b->next = last->next;
	if (last->next)
		last->next->previous = b;
}
