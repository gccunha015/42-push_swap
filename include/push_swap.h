#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "push_swap_types.h"
# include "push_swap_constants.h"
# include "stack.h"
# include "program.h"
# include "operations.h"

void	sort(t_program *p);
int	is_sorted(t_stack *s);

void	sort_up_to_5(t_program *p);
void	radix_sort(t_program *p);

int	get_position(int element, t_stack *s);
int	get_min(t_stack *s, int ignore, int v_to_ignore);
int	get_max(t_stack *s, int ignore, int v_to_ignore);

#endif
