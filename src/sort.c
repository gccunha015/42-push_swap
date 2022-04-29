#include "push_swap.h"

void	divide(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
void	counting_sort(t_stack *a, t_stack *b, int decimal_place);


int	stack_is_sorted(t_stack *s, int last, int order);
int	get_element_to_push_to_b(t_stack *a);
int	get_min(t_stack *s);
int	get_max(t_stack *s);

void	sort(t_stack *a, t_stack *b)
{
	divide(a, b);
	radix_sort(a, b);
	while (!stack_is_empty(b))
		operate(PA, a, b);
}

/*
	Find half of the elements wich are the smaller ones
		and push it to b, order them there
	The half with the bigger elements, order in a
*/
void	divide(t_stack *a, t_stack *b)
{
	int	element;

	if (a->size < 4)
		return ;
	while (a->top > b->top + 1 && !stack_is_sorted(a, 0, ASCENDING))
	{
		element = get_element_to_push_to_b(a);
		if (element == a->top)
			operate(PB, a, b);
		else if (element >= a->top / 2)
			operate(RA, a, b);
		else
			operate(RRA, a, b);
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	decimal_place;

	decimal_place = 1;
	while (a->size / decimal_place > 0)
	{
		counting_sort(a, b, decimal_place);
		decimal_place *= 10;
	}
}

void	counting_sort(t_stack *a, t_stack *b, int decimal_place)
{
	int	i;
	int	count[2][10];
	int	*aux[2];

	aux[A] = malloc(sizeof(**aux) * (a->top + 1));
	if (!stack_is_empty(b))
		aux[B] = malloc(sizeof(**aux) * (b->top + 1));
	else
		aux[B] = NULL;
	i = -1;
	while (++i <= b->top)
	{
		aux[A][i] = a->nodes[i].index;
		aux[B][i] = b->nodes[i].index;
	}
	--i;
	while (++i <= a->top)
		aux[A][i] = a->nodes[i].index;
	printf("a : ");
	for (int w = 0; w <= a->top; w++)
		printf("%i ", aux[A][w]);
	printf("\nb : ");
	for (int w = 0; w <= b->top; w++)
		printf("%i ", aux[B][w]);
	printf("\n");

	(void) b;
	(void) i;
	(void) count;
	(void) aux;
	(void) decimal_place;
	free(aux[A]);
	if (aux[B])
		free(aux[B]);
}

/*
void	sort(t_stack *a, t_stack *b)
{
	t_node	*n[2];
	int	min[2];
	int	max[2];

	if (stack_is_sorted(a, 0, ASCENDING))
		return ;
	n[A]= a->nodes;
	n[B] = b->nodes;
	if (a->size < 4)
	{
		while (!stack_is_sorted(a, 0, ASCENDING))
		{
			if (get_max(a) == a->top)
				operate(RA, a, b);
			else if (get_min(a) == 0)
				operate(RRA, a, b);
			else
				operate(SA, a, b);
		}
	}
	else
	{
		divide(a, b);
		while (!stack_is_sorted(a, 0, ASCENDING) || !stack_is_empty(b))
		{
			if (!stack_is_sorted(a, 0, ASCENDING)
				&& !stack_is_sorted(b, 0, DESCENDING))
			{
				min[A] = get_min(a);
				max[A] = get_max(a);
				min[B] = get_min(b);
				max[B] = get_max(b);
				if (max[A] == a->top && min[B] == b->top)
					operate(RR, a, b);
				else if (min[A] == 0 && max[B] == 0)
					operate(RRR, a, b);
				else
					operate(SS, a, b);
			}
			if (!stack_is_sorted(a, 0, ASCENDING))
			{
				min[A] = get_min(a);
				max[A] = get_max(a);
				if (max[A] == a->top)
					operate(RA, a, b);
				else if (min[A] == 0)
					operate(RRA, a, b);
				else
					operate(SA, a, b);
			}
			if (!stack_is_sorted(b, 0, DESCENDING))
			{
				min[B] = get_min(b);
				max[B] = get_max(b);
				if (min[B] == b->top)
					operate(RB, a, b);
				else if (max[B] == 0)
					operate(RRB, a, b);
				else
					operate(SB, a, b);
			}
			if (stack_is_sorted(a, 0, ASCENDING)
				&& stack_is_sorted(b, 0, DESCENDING)
				&& !stack_is_empty(b))
				operate(PA, a, b);
		}
	}
	(void) n;
}
*/

int	get_element_to_push_to_b(t_stack *a)
{
	int	i;
	int	j;

	i = a->top + 1;
	while (--i >= a->top / 2)
	{
		if (a->nodes[i].index < a->size / 2)
			return (i);
		j = a->top - i;
		if (a->nodes[j].index < a->size / 2)
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
		if (s->nodes[i].index < s->nodes[min].index)
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
