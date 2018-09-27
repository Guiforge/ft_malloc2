/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:35:45 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 15:57:10 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"
#include "../includes/ft_malloc.h"

void	*calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = 1;
	}
	ptr = malloc(nelem * elsize);
	if (ptr)
		ft_bzero(ptr, nelem * elsize);
	return (ptr);
}
