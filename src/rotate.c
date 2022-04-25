#include "push_swap.h"

static int	r(t_stack *s);

int	rotate(char *operation, t_program *p)
{
	int	rotated;

	if (!ft_strncmp(operation, RA, ft_strlen(operation)))
		rotated = r(&p->stack_a);
	else if (!ft_strncmp(operation, RB, ft_strlen(operation)))
		rotated = r(&p->stack_b);
	else if (!ft_strncmp(operation, RR, ft_strlen(operation)))
		rotated = r(&p->stack_a) && r(&p->stack_b);
	else
		rotated = 0;
	return (rotated);
}

static int	r(t_stack *s)
{
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (0);
	i = 0;
	while (++i <= s->top)
		swap_nodes(&s->nodes[0], &s->nodes[i]);
	return (1);
}
