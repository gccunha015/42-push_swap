#include "push_swap.h"

static int	s(t_stack *s);

int	swap(char *operation, t_program *p)
{
	int	swapped;

	if (!ft_strncmp(operation, SA, ft_strlen(operation)))
		swapped = s(&p->stack_a);
	else if (!ft_strncmp(operation, SB, ft_strlen(operation)))
		swapped = s(&p->stack_b);
	else if (!ft_strncmp(operation, SS, ft_strlen(operation)))
		swapped = s(&p->stack_a) && s(&p->stack_b);
	else
		swapped = 0;
	return (swapped);
}

static int	s(t_stack *s)
{
	if (!stack_has_at_least_2_elements(s))
		return (0);
	swap_nodes(&s->nodes[s->top], &s->nodes[s->top - 1]);
	return (1);
}

void	swap_nodes(t_node *x, t_node *y)
{
	t_node aux;

	aux = *x;
	*x = *y;
	*y = aux;
}
