#ifndef PUSH_SWAP_TYPES_H
# define PUSH_SWAP_TYPES_H

typedef	struct s_node
{
	int	value;
	int	index;
}	t_node;

typedef	struct s_stack
{
	t_node	*nodes;
	char	name;
	int	size;
	int	top;
}	t_stack;

typedef	struct s_program
{
	t_stack	a;
	t_stack	b;
}	t_program;

#endif
