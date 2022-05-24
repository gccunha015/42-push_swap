#ifndef PROGRAM_H
# define PROGRAM_H

void	initialize_program(t_program *p, int argc, char **argv);
void	fill_stack_a(t_program *p, char **argv);
void	exit_program(t_program *p, int exit_code);

#endif
