#include "libft.h"
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	assign_index(t_stack *stack)
{
	
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	size;

	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_arg(argc, argv);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	assign_index(a);
	size = ft_lstsize(a);
	if (size <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
}
