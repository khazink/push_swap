/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:27:31 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/21 17:32:37 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	min_val(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max_val(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	get_cheapest_scenario(int a_up, int b_up, int a_down, int b_down)
{
	int	scheme_1;
	int	scheme_2;
	int	scheme_3;
	int	scheme_4;

	scheme_1 = max_val(a_up, b_up);
	scheme_2 = max_val(a_down, b_down);
	scheme_3 = a_up + b_down;
	scheme_4 = a_down + b_up;
	return (min_val(min_val(scheme_1, scheme_2), min_val(scheme_3, scheme_4)));
}

int	calculate_cost(t_stack *a, t_stack *b, t_stack *target, t_stack *current_b)
{
	int	pos_a;
	int	pos_b;
	int	a_down;
	int	b_down;

	pos_a = get_position(a, target);
	pos_b = get_position(b, current_b);
	a_down = 0;
	b_down = 0;
	if (pos_a != 0)
		a_down = ft_size(a) - pos_a;
	if (pos_b != 0)
		b_down = ft_size(b) - pos_b;
	return (get_cheapest_scenario(pos_a, pos_b, a_down, b_down));
}
