#include "push_swap.h"

t_stack	stack_create(char name, int size, t_program *p)
{
	t_stack	s;

	s.nodes = malloc(size * sizeof(s.nodes));
	if (!s.nodes)
		exit_program(p, EXIT_FAILURE);
	s.name = name;
	s.size = size;
	s.top = -1;
	return (s);
}

void	stack_delete(t_stack *s)
{
	free(s->nodes);
	s->nodes = NULL;
}
