#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b);
void	count_sort(t_stack *a, t_stack *b, int decimal_place);
int	stack_is_sorted(t_stack *s, int last, int order);
int	stack_get_max(t_stack *s);

void	sort(t_program *p)
{
	print_stacks(*p);

	radix_sort(&p->stack_a, &p->stack_b);
	
	print_stacks(*p);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	decimal_place;

	decimal_place = 1;
	while (a->size / decimal_place > 0)
	{
		count_sort(a, b, decimal_place);
		decimal_place *= 10;
	}
}

void	count_sort(t_stack *a, t_stack *b, int decimal_place)
{
	int	i;
	int	count[10];

	ft_bzero(count, sizeof(count));
	i = -1;
	while (++i < a->size)
		count[(a->nodes[i].index / decimal_place) % 10]++;
	i = 0;
	while (++i < 10)
		count[i] += count[i - 1];
	i = a->size;
	while (--i >= 0)
	{
		b->nodes[count[(a->nodes[i].index / decimal_place) % 10] - 1]
			= a->nodes[i];
		count[(a->nodes[i].index / decimal_place) % 10]--;
	}
	i = a->size;
	while (--i > -1)
		a->nodes[i] = b->nodes[a->size - 1 - i];
}

int	stack_is_sorted(t_stack *s, int last, int order)
{
	t_node	*n;
	int	i;
	int	j;

	if (stack_is_empty(s))
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

int	stack_get_max(t_stack *s)
{
	t_node	*n;
	int	max;
	int	i;

	if (stack_is_empty(s))
		return (-1);
	n = s->nodes;
	max = 0;
	i = 0;
	while (++i <= s->top)
		if (n[i].value > n[max].value)
		       max = i;
	return (max);
}

int	stack_get_min(t_stack *s)
{
	t_node	*n;
	int	min;
	int	i;

	if (stack_is_empty(s))
		return (-1);
	n = s->nodes;
	min = s->top;
	i = s->top;
	while (--i > -1)
		if (n[i].value < n[min].value)
		       min = i;
	return (min);
}
