/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:58:51 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 16:02:33 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

void		copy_block(t_block *src, t_block *dst)
{
	size_t	min;

	if (!src || !dst)
		return ;
	min = src->size <= dst->size ? src->size : dst->size;
	ft_memcpy(get_data(dst), get_data(src), min);
}
