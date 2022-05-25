#include "push_swap.h"

static void	_print(int operation);

void	execute(int operation, t_program *p)
{
	static int	(*o[])(t_program *p) = {
		pa, pb,
		sa, sb, ss,
		ra, rb, rr,
		rra, rrb, rrr
	};

	if (operation < PA || operation > RRR)
		return ;
	if ((*o[--operation])(p))
		_print(operation);
//	print_stacks(&p->a, &p->b);
}

static void	_print(int operation)
{
	static char	*o[] = {
		"pa\0", "pb\0",
		"sa\0", "sb\0", "ss\0",
		"ra\0", "rb\0", "rr\0",
		"rra\0", "rrb\0", "rrr\0"
	};

	write(STDOUT_FILENO, o[operation], ft_strlen(o[operation]));
	write(STDOUT_FILENO, "\n", 1);
}
