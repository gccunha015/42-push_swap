#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b);
void	count_sort(t_stack *a, t_stack *b, int decimal_place);
int	stack_is_sorted(t_stack *s, int last, int order);

void	sort(t_stack *a, t_stack *b)
{
	print_stacks(*a, *b);

	radix_sort(a, b);
	
	print_stacks(*a, *b);
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
	int	pos;

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
		pos = (a->nodes[i].index / decimal_place) % 10;
		b->nodes[count[pos] - 1] = a->nodes[i];
		count[pos]--;
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
