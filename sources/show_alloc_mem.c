/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:13:51 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 14:20:24 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global		g_malloc;

static void		show_alloc_mem_print(void *ptr, size_t size)
{
	ft_putstr("0x");
	ft_putnbr_base_fd((size_t)ptr, 16, STDOUT_FILENO);
	ft_putstr(" - 0x");
	ft_putnbr_base_fd((size_t)ptr + size, 16, STDOUT_FILENO);
	ft_putstr(" : ");
	ft_putnbr_base_fd(size, 10, STDOUT_FILENO);
	ft_putchar('\n');
}

static void		show_alloc_mem_zone(t_block *first)
{
	t_block *b;

	b = first;
	while (b)
	{
		if (!b->free)
			show_alloc_mem_print(get_data(b), b->size);
		b = b->next;
	}
}

void			show_alloc_mem(void)
{
	malloc_pthread_lock(g_malloc.mutex);
	ft_putstr("TINY : 0x");
	ft_putnbr_base_fd((unsigned int)g_malloc.tiny, 16, 1);
	ft_putchar('\n');
	show_alloc_mem_zone(g_malloc.tiny);
	ft_putstr("SMALL : 0x");
	ft_putnbr_base_fd((unsigned int)g_malloc.medium, 16, 1);
	ft_putchar('\n');
	show_alloc_mem_zone(g_malloc.medium);
	ft_putstr("LARGE : 0x");
	ft_putnbr_base_fd((unsigned int)g_malloc.large, 16, 1);
	ft_putchar('\n');
	show_alloc_mem_zone(g_malloc.large);
	malloc_pthread_unlock(g_malloc.mutex);
}
