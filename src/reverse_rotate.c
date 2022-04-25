#include "push_swap.h"

static int	rr(t_stack *s);

int	reverse_rotate(char *operation, t_program *p)
{
	int	rotated;

	if (!ft_strncmp(operation, RRA, ft_strlen(operation)))
		rotated = rr(&p->stack_a);
	else if (!ft_strncmp(operation, RRB, ft_strlen(operation)))
		rotated = rr(&p->stack_b);
	else if (!ft_strncmp(operation, RRR, ft_strlen(operation)))
		rotated = rr(&p->stack_a) && rr(&p->stack_b);
	else
		rotated = 0;
	return (rotated);
}

static int	rr(t_stack *s)
{
	int	i;

	if (!stack_has_at_least_2_elements(s))
		return (0);
	i = s->top + 1;
	while (--i >= 0)
		swap_nodes(&s->nodes[0], &s->nodes[i]);
	return (1);
}
