/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:37:06 by paubotargue       #+#    #+#             */
/*   Updated: 2023/12/27 23:39:38 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	int		min_val;
	int		i;

	i = 0;
	while (i < 2)
	{
		min_node = ft_find_small(*a);
		min_val = min_node->value;
		if (min_node == ft_find_last(*a))
			rra(a, 1);
		if ((*a)->value > min_val)
			ra(a, 1);
		else
		{
			pb(b, a);
			i++;
		}
	}
	ft_sort_three(a);
	pa(a, b);
	pa(a, b);
}
