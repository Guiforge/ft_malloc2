/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:21:03 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 14:31:37 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"
#include "../includes/ft_malloc.h"

extern t_malloc_global		g_malloc;

static void		print_head(t_block *header)
{
	ft_putstr("********* SHOW DATA *********\n");
	ft_printf("*** Header: %#x, size of header: %d, [(size_t)size: %zu,"
			"prev: %#x, next: %#x]", (unsigned int)header, BLOCK_SIZE,
			header->size, header->previous, header->next);
	ft_putstr("\n******************************\n");
}

static void			print_data_char(unsigned char *data, size_t size)
{
	size_t		count;

	count = 0;
	ft_putstr("             ");
	while (count < 8)
		ft_printf(" %d |", count++);
	ft_putstr("\n            ---------------------------------");
	count = 0;
	while (size > count)
	{
		if (count % 8 == 0)
			ft_printf("\n %#10zu| ", count);
		if (ft_isprint((int)*data))
			ft_printf(" %c |", (unsigned int)*data);
		else
			ft_printf(" %c |", '*');
		data++;
		count++;
	}
	ft_putendl("\n");
}

static void			print_data_hex(unsigned char *data, size_t size)
{
	size_t		count;

	count = 0;
	ft_putstr("             ");
	while (count < 8)
		ft_printf(" %#4d |", count++);
	ft_putstr("\n            ");
	ft_putstr("---------------------------------------------------------");
	count = 0;
	while (size > count)
	{
		if (count % 8 == 0)
			ft_printf("\n %#10zu| ", count);
		ft_printf(" %#4x |", (unsigned int)*data);
		data++;
		count++;
	}
	ft_putendl("\n");
}

int				show_alloc_data(void *ptr, int print_char)
{
	t_block		*block;


	if (!ptr || !is_valid_addr(ptr))
		return (-1);
	block = get_block(ptr);
	malloc_pthread_lock(g_malloc.mutex);
	print_head(get_block(ptr));
	if (print_char & PHEX_DATA)
		print_data_hex(ptr, block->size);
	if (print_char & PCHAR_DATA)
		print_data_char(ptr, block->size);
	malloc_pthread_unlock(g_malloc.mutex);
	return (0);
}
