#include "push_swap.h"

int	stack_is_sorted(t_stack *s, int last, int order);
int	get_min(t_stack *s);
int	get_max(t_stack *s);

void	sort(t_stack *a, t_stack *b)
{
	t_node	*n[2];
	int	min[2];
	int	max[2];

	//print_stacks(*a, *b);

	if (stack_is_sorted(a, 0, ASCENDING))
		return ;
	n[0] = a->nodes;
	n[1] = b->nodes;
	if (a->size == 2)
		operate(SA, a, b);
	else if (a->size == 3)
	{
		if (get_min(a) == a->top)
			operate(RA, a, b);
		if (get_max(a) == a->top)
			operate(SA, a, b);
		if (get_min(a) == 0)
			operate(RRA, a, b);
	}
	/*
		Find half of the elements wich are the smaller ones
			and push it to b, order them there
		The half with the bigger elements, order in a
	*/
	while (a->top > b->top + 1)
	{
		min[0] = get_min(a);
		max[0] = get_max(a);
		if (n[0][a->top].index < a->size / 2)
			operate(PB, a, b);
		else if (n[0][a->top - 1].index < a->size / 2)
			operate(RA, a, b);
		else
			operate(RRA, a, b);
	}
	while (!stack_is_sorted(a, 0, ASCENDING))
	{
		return ;
	}
	while (!stack_is_empty(b))
		operate(PA, a, b);
	(void) n;
	(void) min;
	(void) max;
}

int	get_min(t_stack *s)
{
	int	min;
	int	i;

	if (stack_is_empty(s))
		return (-1);
	min = 0;
	i = 0;
	while (++i <= s->top)
		if (s->nodes[i].index < s->nodes[min].index)
			min = i;
	return (min);
}

int	get_max(t_stack *s)
{
	int	max;
	int	i;

	if (stack_is_empty(s))
		return (-1);
	max = 0;
	i = 0;
	while (++i <= s->top)
		if (s->nodes[i].index > s->nodes[max].index)
			max = i;
	return (max);
}

int	stack_is_sorted(t_stack *s, int last, int order)
{
	t_node	*n;
	int	i;
	int	j;

	if (!stack_has_at_least_2_elements(s))
		return (1);
	n = s->nodes;
	i = s->top + 1;
	while (--i > last)
	{
		j = i;
		while (--j > last - 1)
			if ((order == ASCENDING && n[i].value > n[j].value)
				|| (order == DESCENDING
				&& n[i].value < n[j].value))
				return (0);
	}
	return (1);
}
