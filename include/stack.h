#ifndef STACK_H
# define STACK_H

t_stack	stack_create(char name, int size, t_program *p);
void	stack_delete(t_stack *s);

int	is_empty(t_stack *s);
int	has_at_least_2_elements(t_stack *s);
int	is_full(t_stack *s);
void	push(t_stack *s, t_node n);
t_node	*pop(t_stack *s);

#endif
