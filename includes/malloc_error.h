/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:18:48 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 13:47:45 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_MALLOC_ERROR_H
# define INTERN_MALLOC_ERROR_H

typedef enum e_intern_malloc_error	t_intern_malloc_error;

enum	e_intern_malloc_error
{
	E_INTERN_MALLOC_INIT_FAIL = 0,
	E_INTERN_MALLOC_CANT_ALLOC = 1,
	E_INTERN_MALLOC_INVALID_FREE = 2,
	E_INTERN_MALLOC_MUNMAP_FAIL = 3,
	E_INTERN_MALLOC_SEARCH_FAIL = 4,
	E_INTERN_MALLOC_INVALID_SIZE_MALLOC = 5,
	E_INTERN_MALLOC_PTHREAD_LOCK = 6,
	E_INTERN_MALLOC_PTHREAD_UNLOCK = 7,
	E_INTERN_MALLOC_INTERNAL_ERROR = 8,
	E_INTERN_MALLOC_ALLIGN = 9
};

void	malloc_error(t_intern_malloc_error error);

#endif
