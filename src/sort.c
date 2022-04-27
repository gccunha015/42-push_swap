#include "push_swap.h"

int	stack_is_sorted(t_stack *s, int last, int order);
int	get_min(t_stack *s);
int	get_max(t_stack *s);

void	sort(t_stack *a, t_stack *b)
{
	t_node	*na;
	t_node	*nb;
	int	min;
	int	max;

	print_stacks(*a, *b);

	if (stack_is_sorted(a, 0, ASCENDING))
		return ;
	na = a->nodes;
	nb = b->nodes;
	while (!stack_is_sorted(a, 0, ASCENDING))
	{
		min = get_min(a);
		max = get_max(a);
		return ;
	}
	while (!stack_is_empty(b))
		operate(PA, a, b);
	(void) na;
	(void) nb;
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
