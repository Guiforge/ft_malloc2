/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:19:26 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/03 14:43:10 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global g_malloc;

void			free(void *ptr)
{
	t_block		*zone;

	if (!ptr)
		return ;

	malloc_pthread_lock(g_malloc.mutex);
	if ((zone = is_valid_addr(ptr)))
	{
		get_block(ptr)->free = 1;
		defrag_next(get_block(ptr));
	}
	malloc_pthread_unlock(g_malloc.mutex);
}
