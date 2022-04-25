#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# define SWAP "sa sb ss"
# define PUSH "pa pb"
# define ROTATE "ra rb rr"
# define REVERSE_ROTATE "rra rrb rrr"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

enum	e_order
{
	ASCENDING,
	DESCENDING
};

typedef struct s_node
{
	int	value;
	int	index;
}	t_node;

typedef struct s_stack
{
	t_node	*nodes;
	char	name;
	int	size;
	int	top;
}	t_stack;

typedef struct s_program
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_program;

void	print_stacks(t_program p);

void	initialize_program(t_program *p, int argc);
void	exit_program(t_program *p, int exit_code);

void	stack_create(t_stack *s, char name, int size, t_program *p);
void	stack_delete(t_stack *s);
int	stack_is_empty(t_stack *s);
int	stack_has_at_least_2_elements(t_stack *s);
int	stack_push(t_stack *s, t_node node);
t_node	*stack_pop(t_stack *s);

void	fill_stack_a(t_program *p, char **argv);

int	swap(char *operation, t_program *p);
void	swap_nodes(t_node *x, t_node *y);
int	push(char *operation, t_program *p);
int	rotate(char *operation, t_program *p);
int	reverse_rotate(char *operation, t_program *p);

void	operate(char *operation, t_program *p);

int	stack_get_min(t_stack *s);
int	stack_get_max(t_stack *s);
void	sort(t_program *p);

#endif
