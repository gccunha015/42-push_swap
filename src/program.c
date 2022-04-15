#include "push_swap.h"

static void	program_delete(t_program *p);
static void	program_create(t_program *p, int n_elements);

void	initialize_program(t_program *p, int argc)
{
	if (argc < 2)
		exit_program(NULL, EXIT_SUCCESS);
	program_create(p, argc - 1);
}

void	exit_program(t_program *p, int exit_code)
{
	if (p)
		program_delete(p);
	if (exit_code)
		ft_printf("Error\n");
	exit(exit_code);
}

static void	program_delete(t_program *p)
{
	stack_delete(&p->stack_a);
	stack_delete(&p->stack_b);
}

static void	program_create(t_program *p, int n_elements)
{
	stack_create(&p->stack_a, n_elements, p);
	stack_create(&p->stack_b, n_elements, p);
}
