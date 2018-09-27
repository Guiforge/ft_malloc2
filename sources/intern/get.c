/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:20:40 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 16:07:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

void		*get_data(void *block)
{
	void *data;

	data = block + BLOCK_SIZE;
	return (data);
}

t_block		*get_block(void *data)
{
	return ((void *)data - BLOCK_SIZE);
}
