/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_malloc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:26:26 by gpouyat           #+#    #+#             */
/*   Updated: 2018/09/26 20:05:04 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_MALLOC_H
#define INTERN_MALLOC_H

#include "../libft/includes/libft.h"
#include <sys/mman.h>

typedef struct			s_block
{
	size_t				size;
	struct	s_block		*next;
	struct	s_block		*previous;
	int					free;
}						t_block;

typedef struct		s_malloc_global
{
	t_block			*tiny;
	void			*tiny_end;
	t_block			*medium;
	void			*medium_end;
	t_block			*large;
	int				error;
}					t_malloc_global;

# define MALLOC_FLAG_MMAP_RW PROT_READ | PROT_WRITE
# define MALLOC_FLAG_MMAP_MAP MAP_PRIVATE | MAP_ANON
# define TINY_MAX 1024
# define MEDIUM_MAX TINY_MAX * 3
# define TINY_SIZE TINY_MAX * 1000
# define MEDIUM_SIZE MEDIUM_MAX * 1000

# define BLOCK_SIZE sizeof(struct s_block)

t_block		*create_zone(size_t size);
t_block		*create_alloc(t_block *zone, size_t size);
void		init_zones(void);
t_block		*find_block_free(t_block *zone, size_t size);
t_block		*find_block(t_block *zone, t_block *block, int free);
void		check_align(size_t size);
void		*get_data(void *block);
t_block		*get_block(void *data);
t_block		*split_block(t_block *block, size_t size);
void		defrag(t_block *zone);
void		fusion(t_block *b);
void		set_extra(t_block *block, size_t size, t_block *next,
				t_block *previous, int free);
t_block		*resize_block(t_block *block, size_t new_size);
t_block		*link_destoy_zone(t_block **zone, t_block *block);
t_block		*link_new_zone(t_block **zone, size_t size);

#endif