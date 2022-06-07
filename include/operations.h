#ifndef OPERATIONS_H
# define OPERATIONS_H

void	swap(t_node *x, t_node *y);

int	pa(t_program *p);
int	pb(t_program *p);
int	sa(t_program *p);
int	sb(t_program *p);
int	ss(t_program *p);
int	ra(t_program *p);
int	rb(t_program *p);
int	rr(t_program *p);
int	rra(t_program *p);
int	rrb(t_program *p);
int	rrr(t_program *p);

void	execute(int operation, t_program *p);

#endif
