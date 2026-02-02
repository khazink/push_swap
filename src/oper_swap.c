#include "libft.h"
#include "push_swap.h"

static void	swap(t_stack 

void	sa(t_stack **a, int to_print)
{
	swap(*a);
	if (to_print)
		write (1, "sa\n", 3);
}

void	sb(t_stack **a, int to_print)
{
	swap(*b);
	if (to_print)
		write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
