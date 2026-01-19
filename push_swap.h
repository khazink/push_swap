#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

#include<stdlib.h>
#include<unistd.h>
#include<limits.h>

typedef struct	s_stack
{
	int	value;
	int	index;
	struct	s_stack *next;
	struct	s_stack *prev;
}	t_stack

// --- Parsing and Initialization ---
t_stack	*parse_arguments(int argc, char **argv);


void	print_stacks(t_stack *a, t_stack *b);
