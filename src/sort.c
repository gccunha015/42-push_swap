#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b);
void	count_sort(t_stack *a, t_stack *b, int decimal_place);
int	stack_is_sorted(t_stack *s, int last, int order);
int	stack_get_max(t_stack *s);
int	stack_get_min(t_stack *s);

void	sort(t_program *p)
{
	t_stack	*a;
	t_stack	*b;

	print_stacks(*p);

	a = &p->stack_a;
	b = &p->stack_b;
	radix_sort(a, b);
	
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
		count[(a->values[i] / decimal_place) % 10]++;
	i = 0;
	while (++i < 10)
		count[i] += count[i - 1];
	i = a->size;
	while (--i >= 0)
	{
		b->values[count[(a->values[i] / decimal_place) % 10] - 1]
			= a->values[i];
		count[(a->values[i] / decimal_place) % 10]--;
	}
	i = -1;
	while (++i < a->size)
		a->values[i] = b->values[i];
}

int	stack_is_sorted(t_stack *s, int last, int order)
{
	int	*v;
	int	i;
	int	j;

	if (stack_is_empty(s))
		return (1);
	v = s->values;
	i = s->top + 1;
	while (--i > last)
	{
		j = i;
		while (--j > last - 1)
			if ((order == ASCENDING && v[i] > v[j])
				|| (order == DESCENDING	&& v[i] < v[j]))
				return (0);
	}
	return (1);
}

int	stack_get_max(t_stack *s)
{
	int	*v;
	int	max;
	int	i;

	if (stack_is_empty(s))
		return (-1);
	v = s->values;
	max = 0;
	i = 0;
	while (++i <= s->top)
		if (v[i] > v[max])
		       max = i;
	return (max);
}

int	stack_get_min(t_stack *s)
{
	int	*v;
	int	min;
	int	i;

	if (stack_is_empty(s))
		return (-1);
	v = s->values;
	min = s->top;
	i = s->top;
	while (--i > -1)
		if (v[i] < v[min])
		       min = i;
	return (min);
}
