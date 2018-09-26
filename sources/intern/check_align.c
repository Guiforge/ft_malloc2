/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_align.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:14:00 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 16:52:41 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"
#include "../../includes/malloc_error.h"

void	check_align(size_t size)
{
	if (size % 16)
		malloc_error(E_INTERN_MALLOC_ALLIGN); // CODE ERROR TO DO
}