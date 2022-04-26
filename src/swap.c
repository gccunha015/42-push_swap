#include "push_swap.h"

static void	_swap(t_stack *s);

void	swap(char *operation, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(operation, SA, ft_strlen(operation)))
		_swap(a);
	else if (!ft_strncmp(operation, SB, ft_strlen(operation)))
		_swap(b);
	else if (!ft_strncmp(operation, SS, ft_strlen(operation)))
	{
		_swap(a);
		_swap(b);
	}
}

static void	_swap(t_stack *s)
{
	if (!stack_has_at_least_2_elements(s))
		return ;
	swap_nodes(&s->nodes[s->top], &s->nodes[s->top - 1]);
}

void	swap_nodes(t_node *x, t_node *y)
{
	t_node aux;

	aux = *x;
	*x = *y;
	*y = aux;
}
