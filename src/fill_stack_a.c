#include "push_swap.h"

static void	mark_x_when_not_a_number(unsigned int iteration, char *c);

void	fill_stack_a(t_stack *a, char **argv, t_program *p)
{
	int	i;
	int	j;
	int	k;

	argv++;
	i = a->size;
	while (--i >= 0)
	{
		ft_striteri(argv[i], mark_x_when_not_a_number);
		if (ft_strchr(argv[i], 'x'))
			exit_program(p, EXIT_FAILURE);
		k = a->size - 1;
		a->values[k - i] = ft_atoi(argv[i]);
		if ((a->values[k - i] == -1 && ft_strncmp(argv[i], "-1", ft_strlen(argv[i])))
			|| (!a->values[k - i] && ft_strncmp(argv[i], "0", ft_strlen(argv[i]))))
			exit_program(p, EXIT_FAILURE);
		j = a->size;
		while (--j > i)
			if (a->values[k - j] == a->values[k - i])
				exit_program(p, EXIT_FAILURE);
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
