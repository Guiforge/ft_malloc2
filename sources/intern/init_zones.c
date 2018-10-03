/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zones.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 00:16:43 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/03 14:18:05 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"
#include "../../includes/malloc_error.h"

extern t_malloc_global g_malloc;

void	init_zones(void)
{
	if (g_malloc.tiny != NULL)
		return ;
	g_malloc.tiny = create_zone(TINY_SIZE);
	if (g_malloc.tiny)
		g_malloc.tiny_end = g_malloc.tiny + g_malloc.tiny->size + BLOCK_SIZE;
	g_malloc.medium = create_zone(MEDIUM_SIZE);
	if (g_malloc.medium)
		g_malloc.medium_end = g_malloc.medium + g_malloc.medium->size + \
			BLOCK_SIZE;
	if (!g_malloc.medium || !g_malloc.tiny)
		malloc_error(E_INTERN_MALLOC_INIT_FAIL);
}
