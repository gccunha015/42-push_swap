/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:50 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 15:30:32 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_print(int operation_code);

void	execute(int operation_code, t_program *p)
{
	static int	(*operation[])(t_program *p) = {
		pa, pb,
		sa, sb, ss,
		ra, rb, rr,
		rra, rrb, rrr
	};

	if (operation_code < PA || operation_code > RRR)
		return ;
	if ((*operation[--operation_code])(p))
		_print(operation_code);
}

static void	_print(int operation_code)
{
	static char	*operation[] = {
		"pa\0", "pb\0",
		"sa\0", "sb\0", "ss\0",
		"ra\0", "rb\0", "rr\0",
		"rra\0", "rrb\0", "rrr\0"
	};

	write(STDOUT_FILENO, operation[operation_code],
		ft_strlen(operation[operation_code]));
	write(STDOUT_FILENO, "\n", 1);
}
