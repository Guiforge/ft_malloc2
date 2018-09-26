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
	printf("%lu\n", BLOCK_SIZE);
	t_block *toto = create_zone(32);
	printf("%lu, %d\n", toto->size + BLOCK_SIZE, getpagesize());
	// printf("%lu, %lu\n", g_malloc.tiny->size, g_malloc.medium->size);
	init_zones();
	printf("%lu, %lu\n", g_malloc.tiny->size, g_malloc.medium->size);
	t_block *fit = find_block_free(g_malloc.tiny, 48);
	printf("BEFORE\n");
	printf("%lx = %lx\n", (long)g_malloc.tiny, (long)fit);
	print_one(fit);

	void *new = split_block(fit, 16);
	split_block(fit, 16);
	fit = find_block_free(g_malloc.tiny, 16);
	printf("AFTER\n");
	print_one(fit);
	printf("%lx = %lx\n", (long)g_malloc.tiny, (long)fit);
}