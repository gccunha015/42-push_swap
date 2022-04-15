#include "push_swap.h"

void	stack_create(t_stack *s, int size, t_program *p)
{
	s->values = ft_calloc(size, sizeof(*s->values));
	if (!s->values)
		exit_program(p, ERROR_MALLOC);
	s->size = size;
	s->top = -1;
}

void	stack_delete(t_stack *s)
{
	free(s->values);
	s->values = NULL;
	s->size = 0;
	s->top = -1;
}

int	stack_is_empty(t_stack *s)
{
	return (s->top == -1);
}

int	stack_has_at_least_2_elements(t_stack *s)
{
	return (!stack_is_empty(s) && s->top >= 1);
}

int	stack_is_full(t_stack *s)
{
	return (s->top == s->size - 1);
}

int	stack_push(t_stack *s, int value)
{
	if (stack_is_full(s))
		return (0);
	s->values[++s->top] = value;
	return (1);
}

int	*stack_pop(t_stack *s)
{
	if (stack_is_empty(s))
		return (NULL);
	return (&s->values[s->top--]);
}
