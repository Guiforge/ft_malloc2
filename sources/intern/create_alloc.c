/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:02:19 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 16:02:48 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

t_block			*create_alloc(t_block *zone, size_t size)
{
	t_block		*fit;

	fit = find_block_free(zone, size);
	if (fit)
	{
		split_block(fit, size);
		fit->free = 0;
	}
	return (fit);
}
