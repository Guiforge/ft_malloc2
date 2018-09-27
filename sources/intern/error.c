/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 21:24:00 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/27 16:07:03 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intern_malloc.h"
#include "../../includes/malloc_error.h"

extern t_malloc_global	g_malloc;

static void		intern_malloc_error_over(char *msg, int quit)
{
	if (getenv("MALLOC_DEBUG_INTERN"))
	{
		ft_putstr_fd("Malloc: Error: ", STDERR_FILENO);
		if (msg)
			ft_putendl_fd(msg, STDERR_FILENO);
		else
			ft_putchar_fd('\n', STDERR_FILENO);
	}
	if (quit)
		exit(EXIT_FAILURE);
}

void			malloc_error(t_intern_malloc_error error)
{
	if (error == E_INTERN_MALLOC_INIT_FAIL)
		intern_malloc_error_over("init intern fail", 1);
	if (error == E_INTERN_MALLOC_CANT_ALLOC)
	{
		errno = ENOMEM;
		intern_malloc_error_over("Cannot allocate memory", 0);
	}
	if (error == E_INTERN_MALLOC_INVALID_FREE)
		intern_malloc_error_over("Invalid Free", 1);
	if (error == E_INTERN_MALLOC_MUNMAP_FAIL)
		intern_malloc_error_over("MUNMAP: Fail", 1);
	if (error == E_INTERN_MALLOC_SEARCH_FAIL)
		intern_malloc_error_over("Intern error search:", 1);
	if (error == E_INTERN_MALLOC_INVALID_SIZE_MALLOC)
		intern_malloc_error_over("Invalid size Malloc", 1);
	if (error == E_INTERN_MALLOC_ALLIGN)
		intern_malloc_error_over("intern error, Size not align", 1);
	g_malloc.error = error;
}
