#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc, argv);
	sort(&program);
	exit_program(&program, EXIT_SUCCESS);
}
