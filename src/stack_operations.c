#include "push_swap.h"

int	is_empty(t_stack *s)
{
	return (s->top == -1);
}

int	has_at_least_2_elements(t_stack *s)
{
	return (s->top > 0);
}

int	is_full(t_stack *s)
{
	return (s->top == s->size - 1);
}

void	push(t_stack *s, t_node n)
{
	if (is_full(s))
		return ;
	s->nodes[++s->top] = n;
}

t_node	*pop(t_stack *s)
{
	if (is_empty(s))
		return (NULL);
	return (&s->nodes[s->top--]);
}
