#include "push_swap.h"

void	print_operation(int o, t_program p)
{
	char	*operation;

	if (o == SA)
		operation = "sa";
	else if (o == SB)
		operation = "sb";
	else if (o == SS)
		operation = "ss";
	else if (o == PA)
		operation = "pa";
	else if (o == PB)
		operation = "pb";
	else if (o == RA)
		operation = "ra";
	else if (o == RB)
		operation = "rb";
	else if (o == RR)
		operation = "rr";
	else if (o == RRA)
		operation = "rra";
	else if (o == RRB)
		operation = "rrb";
	else if (o == RRR)
		operation = "rrr";
	ft_printf("%s\n", operation);
	print_stacks(p);
}
