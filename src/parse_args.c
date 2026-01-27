/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 21:22:23 by kkaman            #+#    #+#             */
/*   Updated: 2026/01/27 21:41:02 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	process_split(t_stack **a, char **split)
{
	long	num;
	int		j;

	j = 0;
	while (split[j])
	{
		if (!is_number(split[j]))
		{
			free_split(split);
			error_exit(a, NULL);
		}
		num = ft_atol(split[j]);
		if (num > INT_MAX || num < INT_MIN || is_duplicate(*a, (int)num))
		{
			free_split(split);
			error_exit(a, NULL);
		}
		ft_stack_add_back(a, ft_stack_new((int)num))
		j++;
	}
}

t_stack *parse_arg(int argc, char **argv)
{
        t_stack *a;
        char    **split;
        int             i;

        a = NULL;
        i = 1;
        while (i < argc)
        {
                split = ft_split(argv[i], ' ');
                if (!split)
                        error_exit(&a, NULL);
                process_split(&a, split);
		free_split(split);
		i++;
        }
        return (a);
}

