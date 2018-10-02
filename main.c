/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:00:56 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/02 12:08:54 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_malloc.h"

int		main(void)
{
	char	*toto;

	toto = malloc(42);
	malloc(500 * 2);
	malloc(500 * 2);
	malloc(500 * 2);
	malloc(500 * 12);
	free(toto);
	show_alloc_mem();
	return (0);
}
