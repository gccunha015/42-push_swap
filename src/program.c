/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:22:51 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/06/08 22:09:51 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_program(t_program *p, int exit_code);

void	initialize_program(t_program *p, int argc, char **argv)
{
	int	stack_size;

	if (argc < 2)
		exit_program(NULL, EXIT_SUCCESS);
	p->a.nodes = NULL;
	p->b.nodes = NULL;
	stack_size = argc - 1;
	p->a = stack_create('a', stack_size, p);
	p->b = stack_create('b', stack_size, p);
	fill_stack_a(p, ++argv);
}

void	exit_program(t_program *p, int exit_code)
{
	if (p)
	{
		stack_delete(&p->a);
		stack_delete(&p->b);
	}
	if (exit_code)
		write(STDERR_FILENO, "Error\n", 6);
	exit(exit_code);
}
