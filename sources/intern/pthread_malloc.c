/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 18:24:59 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 13:39:35 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"
#include "../../includes/malloc_error.h"

void	malloc_pthread_lock(pthread_mutex_t mutex)
{
	if (pthread_mutex_lock(&mutex))
		malloc_error(E_INTERN_MALLOC_PTHREAD_LOCK);
}

void	malloc_pthread_unlock(pthread_mutex_t mutex)
{
	if (pthread_mutex_unlock(&mutex))
		malloc_error(E_INTERN_MALLOC_PTHREAD_UNLOCK);
}
