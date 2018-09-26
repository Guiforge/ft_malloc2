/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:20:40 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 15:22:12 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"

void	*get_data(t_block *block)
{
	return (block + sizeof(t_block));
}

t_block		*get_block(void *data)
{
	return (data - sizeof(t_block));
}