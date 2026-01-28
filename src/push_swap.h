/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:57:22 by kkaman            #+#    #+#             */
/*   Updated: 2026/01/28 21:23:22 by kkaman           ###   ########.fr       */
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

// --- Util function ---
int		ft_atoi(const char *str);
int		ft_isNumber(char *argv);

#endif
