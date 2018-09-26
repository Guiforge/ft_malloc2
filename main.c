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
	int nb = MEDIUM_MAX + 1;
	ft_putnbr_base_fd(nb, 10, 1);
	ft_putnbr_base_fd(getpagesize(), 10, 1);
	ft_putchar(' ');
	void *toto = malloc(nb);
	ft_putnbr_base_fd(get_block(toto)->size, 10, 1);
	bzero(toto, nb);
}