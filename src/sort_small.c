/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:06:27 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/10 17:49:10 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	find_min_position(t_stack **a)
{
	while ((*a))
	{
		if (
	}
}

static void	move_to_top(t_stack **a, int min_pos)
{
	
}

static void    sort_three(t_stack **a)
{
	int first = (*a)->value;
	int second = (*a)->next->value;
	int third = (*a)->next->next->value;

	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void    sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;

	while (ft_lstsize(a) > 3)
	{
		min_pos = find_min_position(a);
		move_to_top(a, min_pos);
		pb(&a, &b)
	}
	sort_three(a);
	pa(&a, &b);
}

void    sort_small(t_stack **a, t_stack **b, int size)
{
    if (size == 2)
    {
	if ((*a)->value > (*a)->next->value)
		sa(a);
    }
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
}
