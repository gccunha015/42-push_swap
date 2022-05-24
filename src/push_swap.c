#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_program	program;

	initialize_program(&program, argc, argv);
	execute(RA, &program);
	exit_program(&program, EXIT_SUCCESS);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*n[2];
	int	top[2] = {a->top, -1};
	char	*separator = "-------------------";

	if (b)
		top[B] = b->top;
	printf("|%s|%s|\n", separator, separator);
	for (int i = a->size - 1; i > -1; i--)
	{
		if (b && top[A] == i && top[B] == i)
		{
			n[A] = &a->nodes[top[A]--];
			n[B] = &b->nodes[top[B]--];
			printf("| [%3i] %11i ", n[A]->index, n[A]->value);
			printf("| [%3i] %11i ", n[B]->index, n[B]->value);
		}
		else if (top[A] == i)
		{
			n[A] = &a->nodes[top[A]--];
			printf("| [%3i] %11i ", n[A]->index, n[A]->value);
			printf("| %17c ",  ' ');
		}
		else if (b && top[B] == i)
		{
			n[B] = &b->nodes[top[B]--];
			printf("| %17c ",  ' ');
			printf("| [%3i] %11i ", n[B]->index, n[B]->value);
		}
		else
		{
			n[A] = NULL;
			n[B] = NULL;
		}
		if (n[A] || n[B])
			printf("|\n");
	}
	printf("|%s|%s|\n", separator, separator);
	printf("| %17c | %17c |\n", 'a', 'b');
	printf("|%s|%s|\n", separator, separator);
}
