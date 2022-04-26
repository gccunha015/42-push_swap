#include "push_swap.h"

static void	_reverse_rotate(t_stack *s);

void	reverse_rotate(char *operation, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(operation, RRA, ft_strlen(operation)))
		_reverse_rotate(a);
	else if (!ft_strncmp(operation, RRB, ft_strlen(operation)))
		_reverse_rotate(b);
	else if (!ft_strncmp(operation, RRR, ft_strlen(operation)))
	{
		_reverse_rotate(a);
		_reverse_rotate(b);
	}
}

static void	_reverse_rotate(t_stack *s)
{
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return ;
	i = s->top + 1;
	while (--i > -1)
		swap_nodes(&s->nodes[0], &s->nodes[i]);
}
