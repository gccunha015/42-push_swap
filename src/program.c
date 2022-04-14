#include "push_swap.h"

static void	t_program_delete(t_program *p);
static void	t_program_create(t_program *p, size_t n_elements);

void	initialize_program(t_program *p, int argc)
{
	if (argc < 2)
		exit_program(NULL, ERROR_ARGUMENT_QUANTITY);
	t_program_create(p, argc - 1);
}

void	exit_program(t_program *p, char *error_message)
{
	t_program_delete(p);
	if (error_message)
	{
		ft_printf("Error:\n\t%s\n", error_message);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

static void	t_program_delete(t_program *p)
{
	int	idx;

	if (!p)
		return ;
	idx = -1;
	while (++idx < N_STACKS)
		t_stack_delete(&p->stacks[idx]);
}

static void	t_program_create(t_program *p, size_t n_elements)
{
	int	idx;

	if (!p)
		return ;
	p->n_elements = n_elements;
	idx = -1;
	while (++idx < N_STACKS)
		t_stack_create(&p->stacks[idx], p);
}
