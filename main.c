#include "./includes/intern_malloc.h"

extern t_malloc_global	g_malloc;

void	print_one(t_block *block)
{
	if (block)
		printf("size = %lu, next = %lx, free = %d\n", block->size, (long)block->next, block->free);
	else
		printf("NO blocks\n");
}
 #include <assert.h>
int		main()
{
	char *toto = malloc(42);
	bzero(toto, 42);
	free(toto);
}