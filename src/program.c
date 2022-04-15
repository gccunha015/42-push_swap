#include "push_swap.h"

static void	program_delete(t_program *p);
static void	program_create(t_program *p, size_t n_elements);

void	initialize_program(t_program *p, int argc)
{
	if (argc < 2)
		exit_program(NULL, ERROR_ARGUMENT_QUANTITY);
	program_create(p, argc - 1);
}

void	exit_program(t_program *p, char *error_message)
{
	if (p)
		program_delete(p);
	if (error_message)
	{
		ft_printf("Error:\n\t%s\n", error_message);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

static void	program_delete(t_program *p)
{
	stack_delete(&p->stack_a);
	stack_delete(&p->stack_b);
}

static void	program_create(t_program *p, size_t n_elements)
{
	stack_create(&p->stack_a, n_elements, p);
	stack_create(&p->stack_b, n_elements, p);
}
