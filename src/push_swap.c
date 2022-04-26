#include "push_swap.h"

void	print_stacks(t_stack a, t_stack b);

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc);
	fill_stack_a(&program, argv);
	sort(&program.a, &program.b);
	exit_program(&program, EXIT_SUCCESS);
}

void	print_stacks(t_stack a, t_stack b)
{
	t_node	*na, *nb;
	char	*separator = "-------------------";

	printf("|%s|%s|\n", separator, separator);
	for (int i = a.size - 1; i > -1; i--)
	{
		na = NULL;
		nb = NULL;
		if (a.top == i)
			na = stack_pop(&a);
		if (b.top == i)
			nb = stack_pop(&b);
		if (na && nb)
		{
			printf("| [%3i] %11i ", na->index, na->value);
			printf("| [%3i] %11i ", nb->index, nb->value);
		}
		else if (na)
		{
			printf("| [%3i] %11i ", na->index, na->value);
			printf("| %17c ", ' ');
		}
		else if (nb)
		{
			printf("| %17c ", ' ');
			printf("| [%3i] %11i ", nb->index, nb->value);
		}
		if (na || nb)
			printf("|\n");
	}
	printf("|%s|%s|\n", separator, separator);
	printf("| %17c | %17c |\n", 'a', 'b');
	printf("|%s|%s|\n", separator, separator);
}
