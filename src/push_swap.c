#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	size;

	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_arg(argc, argv);
	size = ft_lstsize(a);
	if (size <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
}
