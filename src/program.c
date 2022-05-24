#include "push_swap.h"

static void	_delete(t_program *p);
void	exit_program(t_program *p, int exit_code);

void	initialize_program(t_program *p, int argc, char **argv)
{
	int	stack_size;

	if (argc < 3)
	       exit_program(NULL, EXIT_SUCCESS);
	stack_size = argc - 1;
	p->a = stack_create('a', stack_size, p);
	fill_stack_a(p, ++argv);
	p->b = stack_create('b', stack_size, p);
}

void	exit_program(t_program *p, int exit_code)
{
	if (p)
		_delete(p);
	if (exit_code)
		write(STDOUT_FILENO, "Error\n", 6);
	exit(exit_code);
}

static void	_delete(t_program *p)
{
	stack_delete(&p->a);
	stack_delete(&p->b);
}
