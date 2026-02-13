/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:57:22 by kkaman            #+#    #+#             */
/*   Updated: 2026/02/13 19:17:08 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// --- Parsing and Initialization ---
t_stack	*parse_arg(int argc, char **argv);

void	print_stacks(t_stack *a, t_stack *b);
void	error_exit(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	free_split(char **split);

// --- Add Stack ---
t_stack	*ft_stack_new(int value);
void	ft_stack_add_back(t_stack **stack, t_stack *new_node);

// --- Operation ---
void	sa(t_stack **a, int to_print);
void	sb(t_stack **b, int to_print);
void	ss(t_stack **a, t_stack **b, int to_print);
void	pa(t_stack **a, t_stack **b, int to_print);
void	pb(t_stack **a, t_stack **b, int to_print);
void	ra(t_stack **a, int to_print);
void	rb(t_stack **b, int to_print);
void	rr(t_stack **a, t_stack **b, int to_print);
void	rra(t_stack **a, int to_print);
void	rrb(t_stack **b, int to_print);
void	rrr(t_stack **a, t_stack **b, int to_print);

// --- Sorting ---
void	sort_small(t_stack **a, t_stack **b, int size);
void	sort_three(t_stack **a);
void	sort_large(t_stack **a, t_stack **b);

// --- Util function ---
int		ft_size(t_stack *stack);
t_stack	*get_last_node(t_stack *stack);

#endif
