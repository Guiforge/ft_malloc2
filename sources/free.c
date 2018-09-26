/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:19:26 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 23:00:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global		g_malloc;

static void			invalid_free(void *ptr)
{
	ft_putstr_fd("*** Error in `./a.out': free(): invalid pointer: 0X",
			STDERR_FILENO);
	ft_putendl_fd(" ***", STDERR_FILENO);
	ft_putnbr_base_fd(get_block(ptr)->size, 10, 1);
	kill(0, SIGABRT);
}

static	void		intern_free(t_block *zone, t_block *block)
{
		block->free = 1;
		defrag(zone);
}

void				free(void *ptr)
{
	t_block		*block;

	if (!ptr)
		return ;
	block = get_block(ptr);

	if (find_block(g_malloc.tiny, block, 0))
		intern_free(g_malloc.tiny, block);
	else if (find_block(g_malloc.medium, block, 0))
		intern_free(g_malloc.medium, block);
	else if (find_block(g_malloc.large, block, 0))
		link_destroy_zone(&g_malloc.large, block);
	else
		invalid_free(ptr);
}