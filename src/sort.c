#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b);
void	count_sort(t_stack *a, t_stack *b, int decimal_place);
int	stack_is_sorted(t_stack *s, int last, int order);
int	get_min(t_stack *s);

void	sort(t_stack *a, t_stack *b)
{
	t_node	*na;
	t_node	*nb;
	int	i;

	print_stacks(*a, *b);

	if (stack_is_sorted(a, 0, ASCENDING))
		return ;
	na = a->nodes;
	nb = b->nodes;
	i = -1;
	while (++i < a->top / 2 && na[a->top].index > na[i].index)
		operate(RRA, a, b);
	if (!get_min(a))
		operate(RRA, a, b);
	/*
	radix_sort(a, b);	
	print_stacks(*a, *b);
	*/
	(void) nb;
}

int	get_min(t_stack *s)
{
	int	min;
	int	i;

	if (stack_is_empty(s))
		return (-1);
	min = 0;
	i = 0;
	while (++i < s->top)
		if (s->nodes[i].index < s->nodes[min].index)
			min = i;
	return (min);
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
	int	count[10];
	int	i;
	int	digit;

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
		digit = (a->nodes[i].index / decimal_place) % 10;
		b->nodes[count[digit] - 1] = a->nodes[i];
		count[digit]--;
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
