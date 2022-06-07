#include "push_swap.h"

void	count_sort(int bit, t_program *p);

void	radix_sort(t_program *p)
{
	int	bit_count;
	int	bit;

	bit_count = 0;
	while (p->a.top >> bit_count)
		bit_count++;
	bit = -1;
	while (++bit < bit_count)
		count_sort(bit, p);
}

void	count_sort(int bit, t_program *p)
{
	int	i;

	i = -1;
	while (++i < p->a.size)
	{
		if ((p->a.nodes[p->a.top].index >> bit) & 1)
			execute(PB, p);
		else
			execute(RA, p);
	}
	while (!is_empty(&p->b))
		execute(PA, p);
}
