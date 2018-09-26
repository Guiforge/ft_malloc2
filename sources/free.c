/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:19:26 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 20:42:03 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global		g_malloc;

static void			invalid_free(void *ptr)
{
	ft_putstr_fd("*** Error in `./a.out': free(): invalid pointer: 0X",
			STDERR_FILENO);
	ft_putnbr_base_fd((size_t)ptr, 16, STDERR_FILENO);
	ft_putendl_fd(" ***", STDERR_FILENO);
	kill(0, SIGABRT);
}

void				free(void *ptr)
{
	t_block		*block;

	if (!ptr)
		return ;
	block = get_block(ptr);
	if ((block >= g_malloc.tiny && (void *)block <= g_malloc.tiny_end))
	{
		if (!find_block(g_malloc.tiny, block, 0))
			invalid_free(ptr);
		block->free = 1;
		defrag(g_malloc.tiny);
	}
	else if ((block >= g_malloc.medium && (void *)block <= g_malloc.medium_end))
	{
		if (!find_block(g_malloc.medium, block, 0))
			invalid_free(ptr);
		block->free = 1;
		defrag(g_malloc.medium);
	}
	else
	{
		if (!find_block(g_malloc.large, block, 0))
			invalid_free(ptr);
		link_destroy_zone(&g_malloc.large, block);
	}
}