#include "push_swap.h"

static int	get_element_to_sort_in_b(t_stack *a);

void	divide(t_program *p)
{
	int	element;

	if (p->a.size < 4)
		return ;
	while (p->a.top > p->b.top + 1)
	{
		element = get_element_to_sort_in_b(&p->a);
		if (element == p->a.top)
			execute(PB, p);
		else if (element >= p->a.top / 2)
			execute(RA, p);
		else if (element != -1)
			execute(RRA, p);
		else
			break ;
	}
}

static int	get_element_to_sort_in_b(t_stack *a)
{
	int	i;
	int	j;

	i = a->top + 1;
	while (--i >= a->top / 2)
	{
		if (a->nodes[i].index >= a->size / 2)
			return (i);
		j = a->top - i;
		if (a->nodes[j].index >= a->size / 2)
			return (j);
	}
	return (-1);
}
