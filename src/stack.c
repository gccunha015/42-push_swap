#include "push_swap.h"

void	stack_create(t_stack *s, char name, int size, t_program *p)
{
	s->nodes = malloc(size * sizeof(*s->nodes));
	if (!s->nodes)
		exit_program(p, EXIT_FAILURE);
	s->name = name;
	s->size = size;
	s->top = -1;
}

void	stack_delete(t_stack *s)
{
	free(s->nodes);
	s->nodes = NULL;
	s->name = '\0';
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

int	stack_push(t_stack *s, t_node node)
{
	if (stack_is_full(s))
		return (0);
	s->nodes[++s->top] = node;
	return (1);
}

t_node	*stack_pop(t_stack *s)
{
	if (stack_is_empty(s))
		return (NULL);
	return (&s->nodes[s->top--]);
}
