/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:19:26 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 13:36:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global g_malloc;

// static void			invalid_free(void *ptr)
// {
// 	ft_putstr_fd("*** Error in `./a.out': free(): invalid pointer: 0X",
// 			STDERR_FILENO);
// 	ft_putnbr_base_fd((long)ptr, 16, 1);
// 	ft_putendl_fd(" ***", STDERR_FILENO);	
// 	kill(0, SIGABRT);

// 	(void)ptr;
// }


void				free(void *ptr)
{
	t_block		*zone;

	if (!ptr)
		return ;
	if ((zone = is_valid_addr(ptr)))
	{
		get_block(ptr)->free = 1;
		malloc_pthread_lock(g_malloc.mutex);
		defrag(zone);
		malloc_pthread_unlock(g_malloc.mutex);
	}
	// else
	// 	invalid_free(ptr);
}