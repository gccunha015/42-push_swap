#include "push_swap.h"

void	t_stack_create(t_stack *s, t_program *p)
{
	s->values = ft_calloc(p->n_elements, sizeof(*s->values));
	if (!s->values)
		exit_program(p, ERROR_MALLOC);
	s->top = -1;
}

void	t_stack_delete(t_stack *s)
{
	free(s->values);
	s->values = NULL;
}
