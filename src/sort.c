#include "push_swap.h"

int	stack_is_sorted(t_stack s, int order);
int	array_is_sorted(int a[], int last, int order);

void	sort(t_program *p)
{
	t_stack	*a;
	t_stack	*b;

	print_stacks(*p);

	a = &p->stack_a;
	b = &p->stack_b;
	while (!stack_is_sorted(*a, ASCENDING) || !stack_is_empty(b))
	{
		if (array_is_sorted(a->values, 1, DESCENDING)
			&& array_is_sorted(b->values, 1, ASCENDING))
			swap(SS, p);
		else if (array_is_sorted(a->values, 1, DESCENDING))
			swap(SA, p);
		else if (array_is_sorted(b->values, 1, ASCENDING))
			swap(SB, p);
	}
}

int	stack_is_sorted(t_stack s, int order)
{
	return (array_is_sorted(s.values, s.top, order));
}

int	array_is_sorted(int a[], int last, int order)
{
	int	i;
	int	j;

	i = last + 1;
	while (--i > 0)
	{
		j = i;
		while (--j > -1)
			if ((order == ASCENDING && a[i] > a[j])
				|| (order == DESCENDING	&& a[i] < a[j]))
				return (0);
	}
	return (1);
}
