#include "push_swap.h"

static void	_print(int operation);

void	execute(int operation, t_program *p)
{
	static int	(*o[OPERATIONS])(t_program *p) = {
		pa, pb,
		sa, sb, ss,
		ra, rb, rr,
		rra, rrb, rrr
	};

	if (!operation--)
		return ;
	if ((*o[operation])(p))
		_print(operation);
	print_stacks(&p->a, &p->b);
}

static void	_print(int operation)
{
	static char	*o[OPERATIONS] = {
		"pa\0", "pb\0",
		"sa\0", "sb\0", "ss\0",
		"ra\0", "rb\0", "rr\0",
		"rra", "rrb", "rrr"
	};

	write(STDOUT_FILENO, o[operation], 3);
	write(STDOUT_FILENO, "\n", 1);
}