#include "push_swap.h"

static void	_rotate(t_stack *s);

void	rotate(char *operation, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(operation, RA, ft_strlen(operation)))
		_rotate(a);
	else if (!ft_strncmp(operation, RB, ft_strlen(operation)))
		_rotate(b);
	else if (!ft_strncmp(operation, RR, ft_strlen(operation)))
	{
		_rotate(a);
		_rotate(b);
	}
}

static void	_rotate(t_stack *s)
{
	int	i;

	i = 0;
	while (++i <= s->top)
		swap_nodes(&s->nodes[0], &s->nodes[i]);
}
