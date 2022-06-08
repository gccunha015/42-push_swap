/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:51 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:52:05 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "constants.h"
# include "types.h"
# include "stack.h"
# include "program.h"
# include "operations.h"

void	sort(t_program *p);
int		is_sorted(t_stack *s);

void	sort_up_to_5(t_program *p);
void	radix_sort(t_program *p);

int		get_position(int element, t_stack *s);
int		get_min(t_stack *s, int ignore, int v_to_ignore);
int		get_max(t_stack *s, int ignore, int v_to_ignore);

#endif
