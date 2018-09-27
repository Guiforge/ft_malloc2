/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:33:45 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 16:09:13 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

extern t_malloc_global g_malloc;

t_block		*is_valid_addr(void *ptr)
{
	if (!g_malloc.tiny || !g_malloc.medium)
		return (NULL);
	else if (ptr >= (void *)g_malloc.tiny && ptr <= g_malloc.tiny_end && \
			find_block(g_malloc.tiny, get_block(ptr), 0))
		return (g_malloc.tiny);
	else if (ptr >= (void *)g_malloc.medium && ptr <= g_malloc.medium_end && \
			find_block(g_malloc.medium, get_block(ptr), 0))
		return (g_malloc.medium);
	else if (find_block(g_malloc.large, get_block(ptr), 0))
		return (g_malloc.large);
	return (NULL);
}
