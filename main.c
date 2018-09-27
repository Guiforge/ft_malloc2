#include "./includes/ft_malloc.h"

// extern t_malloc_global	g_malloc;

// void	print_one(t_block *block)
// {
// 	if (block)
// 		printf("size = %lu, next = %lx, free = %d\n", block->size, (long)block->next, block->free);
// 	else
// 		printf("NO blocks\n");
// }
 #include <assert.h>
int		main()
{
	malloc(1024);
	malloc(1024 * 2);
	malloc(1024 * 16);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}