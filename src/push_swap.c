/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:52:16 by kkaman            #+#    #+#             */
/*   Updated: 2026/01/28 21:25:08 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	
	b = NULL;
	a = parse_arg(argc, argv);
	print_stacks(a, b);
	pb(&a, &b, 1);
	print_stacks(a, b);
	return (0);
}
