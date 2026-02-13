/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:14:06 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/13 19:14:59 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_stack	*current;
	t_stack	*compare;
	int		count;

	current = stack;
	while (current)
	{
		compare = stack;
		count = 0;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	b = NULL;
	if (argc < 2)
		return (0);
	a = parse_arg(argc, argv);
	print_stacks(a, b);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	assign_index(a);
	size = ft_size(a);
	if (size <= 5)
		sort_small(&a, &b, size);
	else
		sort_large(&a, &b);
	print_stacks(a, b);
}
