/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:13:51 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/02 12:11:33 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global		g_malloc;

static void			show_alloc_mem_print(void *ptr, size_t size)
{
	ft_putstr("0x");
	ft_putnbr_base_fd((size_t)ptr, 16, STDOUT_FILENO);
	ft_putstr(" - 0x");
	ft_putnbr_base_fd((size_t)ptr + size, 16, STDOUT_FILENO);
	ft_putstr(" : ");
	ft_putnbr_base_fd(size, 10, STDOUT_FILENO);
	ft_putendl(" octets");
}

static size_t		show_alloc_mem_zone(t_block *first)
{
	t_block	*b;
	size_t	size_tot;

	size_tot = 0;
	b = first;
	while (b)
	{
		if (!b->free)
		{
			show_alloc_mem_print(get_data(b), b->size);
			size_tot += b->size;
		}
		b = b->next;
	}
	return (size_tot);
}

void				show_alloc_mem(void)
{
	size_t		size_tot;

	size_tot = 0;
	malloc_pthread_lock(g_malloc.mutex);
	ft_putstr("TINY : 0x");
	ft_putnbr_base_fd((unsigned int)g_malloc.tiny, 16, 1);
	ft_putchar('\n');
	size_tot += show_alloc_mem_zone(g_malloc.tiny);
	ft_putstr("SMALL : 0x");
	ft_putnbr_base_fd((unsigned int)g_malloc.medium, 16, 1);
	ft_putchar('\n');
	size_tot += show_alloc_mem_zone(g_malloc.medium);
	ft_putstr("LARGE : 0x");
	ft_putnbr_base_fd((unsigned int)g_malloc.large, 16, 1);
	ft_putchar('\n');
	size_tot += show_alloc_mem_zone(g_malloc.large);
	ft_putstr("Total : ");
	ft_putnbr_base_fd(size_tot, 10, STDOUT_FILENO);
	ft_putendl(" octets");
	malloc_pthread_unlock(g_malloc.mutex);
}
