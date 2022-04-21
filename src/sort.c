#include "push_swap.h"

int	should_swap(t_stack *s);
int	should_push(t_stack *s);
int	should_rotate(t_stack *s);
int	should_reverse_rotate(t_stack *s);
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
	while (!stack_is_sorted(a, 0, ASCENDING) || !stack_is_empty(b))
	{
		if (stack_is_empty(b) || stack_is_sorted(b, 0, DESCENDING))
			while (should_push(a))
				push(PB, p);
		if (stack_is_empty(a) || stack_is_sorted(a, 0, ASCENDING))
			while (should_push(b))
				push(PA, p);
		if (should_rotate(a) && should_rotate(b))
			rotate(RR, p);
		else if (should_rotate(a))
			rotate(RA, p);
		else if (should_rotate(b))
			rotate(RB, p);
		if (should_reverse_rotate(a) && should_reverse_rotate(b))
			reverse_rotate(RRR, p);
		else if (should_reverse_rotate(a))
			reverse_rotate(RRA, p);
		else if (should_reverse_rotate(b))
			reverse_rotate(RRB, p);
		if (should_swap(a) && should_swap(b))
			swap(SS, p);
		else if (should_swap(a))
			swap(SA, p);
		else if (should_swap(b))
			swap(SB, p);
	}
}

int	should_swap(t_stack *s)
{
	if (!stack_has_at_least_2_elements(s))
		return (0);
	if (s->name == 'b')
		return (stack_is_sorted(s, s->top - 1, ASCENDING));
	return (stack_is_sorted(s, s->top - 1, DESCENDING));
}

int	should_push(t_stack *s)
{
	if (stack_is_empty(s))
		return (0);
	if (s->name == 'b')
		return (stack_get_max(s) == s->top);
	return (stack_get_min(s) == s->top);
}

int	should_rotate(t_stack *s)
{
	if (!stack_has_at_least_2_elements(s))
		return (0);
	if (s->name == 'b')
		return (stack_get_min(s) == s->top);
	return (stack_get_max(s) == s->top);
}

int	should_reverse_rotate(t_stack *s)
{
	if (!stack_has_at_least_2_elements(s))
		return (0);
	if (s->name == 'b')
		return (stack_get_max(s) == 0);
	return (stack_get_min(s) == 0);
}

int	stack_is_sorted(t_stack *s, int last, int order)
{
	int	*v;
	int	i;
	int	j;

	if (stack_is_empty(s))
		return (0);
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

	v = s->values;
	min = s->top;
	i = s->top;
	while (--i > -1)
		if (v[i] < v[min])
		       min = i;
	return (min);
}
