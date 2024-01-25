/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:20:57 by paubotargue       #+#    #+#             */
/*   Updated: 2024/01/25 17:20:37 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_str(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (1);
		str++;
	}
	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2 && !check_str(argv[1]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_init_stack(&a, argv, argc == 2);
	if (!ft_is_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, 1);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else if (ft_stack_len(a) == 5)
			ft_sort_five(&a, &b);
		else
			ft_push_swap(&a, &b);
	}
	ft_free_stack(&a);
}
