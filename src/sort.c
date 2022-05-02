#include "push_swap.h"

void	divide(t_stack *a, t_stack *b);
int	stack_is_sorted(t_stack *s, int order);
int	get_element_to_push_to_b(t_stack *a);
int	get_min(t_stack *s);
int	get_max(t_stack *s);
void	sort_2_or_3(t_stack *a);

void	merge_sort(t_stack *s, int l, int r);
void	merge(t_stack *s, int start, int mid, int end);

void	sort(t_stack *a, t_stack *b)
{
	t_node	*n[2];
	int	min[2];
	int	max[2];
	int	i[2];

	if (stack_is_sorted(a, ASCENDING))
		return ;
	if (a->size < 4)
		return (sort_2_or_3(a));
	divide(a, b);
	while (!stack_is_sorted(a, ASCENDING))
	{
		merge(a, 0, a->top / 2, a->top);
		merge(b, 0, b->top / 2, b->top);
	}
	while (!stack_is_empty(b))
		execute(PA, a, b);
	/*
	n[A]= a->nodes;
	n[B] = b->nodes;
	while (!stack_is_sorted(a, ASCENDING) || !stack_is_empty(b))
	{
		return ;
	}
	*/
	(void) b;
	(void) n;
	(void) min;
	(void) max;
	(void) i;
}

void	merge_sort(t_stack *s, int l, int r)
{
	int	m;

	m = (l + r) / 2;
	if (m >= r)
		return ;
	merge_sort(s, l, m);
	merge_sort(s, m + 1, r);
	merge(s, l, m, r);
}

void	merge(t_stack *s, int start, int mid, int end)
{
	t_node	*n = s->nodes;
	int	start2 = mid + 1;

	if (n[mid].index < n[start2].index)
		return ;
	while (start <= mid && start2 <= end)
	{
		if (n[start].index < n[start2].index)
		{
			start++;
			continue ;
		}

		t_node	v = n[start2];
		int	i = start2 + 1;
		while (--i != start)
			n[i] = n[i - 1];
		n[start] = v;
		start++;
		mid++;
		start2++;
	}
}

void	sort_2_or_3(t_stack *a)
{
	int	operation;

	while (!stack_is_sorted(a, ASCENDING))
	{
		if (get_max(a) == a->top)
			operation = RA;
		else if (get_min(a) == 0)
			operation = RRA;
		else
			operation = SA;
		execute(operation, a, NULL);
	}
}

void	divide(t_stack *a, t_stack *b)
{
	int	element;
	int	operation;

	while (a->top > b->top + 1 && !stack_is_sorted(a, ASCENDING))
	{
		element = get_element_to_push_to_b(a);
		if (element == a->top)
			operation = PB;
		else if (element >= a->top / 2)
			operation = RA;
		else
			operation = RRA;
		execute(operation, a, b);
	}
}

int	get_element_to_push_to_b(t_stack *a)
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
	return (a->top);
}

int	get_min(t_stack *s)
{
	int	min;
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (-1);
	min = 0;
	i = 0;
	while (++i <= s->top)
		if (s->nodes[i].value < s->nodes[min].value)
			min = i;
	return (min);
}

int	get_max(t_stack *s)
{
	int	max;
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (-1);
	max = 0;
	i = 0;
	while (++i <= s->top)
		if (s->nodes[i].value > s->nodes[max].value)
			max = i;
	return (max);
}

int	stack_is_sorted(t_stack *s, int order)
{
	t_node	*n;
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (1);
	n = s->nodes;
	i = -1;
	while (++i <= s->top)
	{
		if ((order == ASCENDING && n[i].index != i)
			|| (order == DESCENDING
			&& n[i].index != s->size - 1 - i))
			return (0);
	}
	return (1);
}
