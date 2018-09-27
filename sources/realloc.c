/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:30:22 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 13:37:59 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/intern_malloc.h"

extern t_malloc_global g_malloc;

void    *realloc(void *ptr, size_t size)
{
    t_block *block;

    if (!ptr)
        return (malloc(size));
	malloc_pthread_lock(g_malloc.mutex);    
    if (!is_valid_addr(ptr))
        return (NULL); // DO ERROR
    size = ft_align(size, 16);
    block = resize_block(get_block(ptr), size);
	malloc_pthread_unlock(g_malloc.mutex);
    if (block)
        return (get_data(block));
    
    if ((block = malloc(size)))
    {
        block = get_block(block);
        copy_block(get_block(ptr), block);
        free(ptr);
        block = get_data(block);
    }
    return(block);
}

void *reallocf(void *p, size_t size)
{
    void *newp;

    newp = realloc(p,size);
    if (!newp)
        free(p);
    return (newp);
}