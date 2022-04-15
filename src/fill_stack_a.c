#include "push_swap.h"

static void	mark_x_when_not_a_number(unsigned int iteration, char *c);

void	fill_stack_a(t_stack *a, char **argv, t_program *p)
{
	size_t	i;
	size_t	j;
	size_t	k;

	argv++;
	i = a->size;
	while (--i != (size_t) -1)
	{
		ft_striteri(argv[i], mark_x_when_not_a_number);
		if (ft_strchr(argv[i], 'x'))
			exit_program(p, ERROR_ARGUMENT_NOT_A_NUMBER);
		k = a->size - 1;
		a->values[k - i] = ft_atoi(argv[i]);
		j = a->size;
		while (--j > i)
			if (a->values[k - j] == a->values[k - i])
				exit_program(p, ERROR_ARGUMENT_DUPLICATED);
		a->top++;
	}
}

static void	mark_x_when_not_a_number(unsigned int iteration, char *c)
{
	(void) iteration;
	if (!*c || ft_isdigit(*c) || (ft_strchr("-+", *c) && ft_isdigit(*(c + 1))))
		return ;
	*c = 'x';
}
