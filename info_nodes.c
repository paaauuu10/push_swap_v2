/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:20:49 by paubotargue       #+#    #+#             */
/*   Updated: 2024/01/10 11:50:39 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_current_position(t_stack *a)
{
	int	i;
	int	half_list;

	i = 0;
	if (a == NULL)
		return ;
	half_list = ft_stack_len(a) / 2;
	while (a)
	{
		a->position = i;
		if (i <= half_list)
			a->above_median = 1;
		else
			a->above_median = 0;
		a->cheapest = 0;
		a = a->next;
		i++;
	}
}

//the function finds and sets as a target the smallest bigger node.

static void	ft_target(t_stack *a, t_stack *b)
{
	int		match;	
	t_stack	*new_a;
	t_stack	*target;

	while (b)
	{
		match = 2147483647;
		new_a = a;
		while (new_a)
		{
			if ((new_a->value > b->value) && (new_a->value < match))
			{
				match = new_a->value;
				target = new_a;
			}
			new_a = new_a->next;
		}
		if (match == 2147483647)
			b->target = ft_find_small(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	ft_price(t_stack *a, t_stack *b)
{
	while (b)
	{
		b->price = b->position;
		if (b->above_median == 0)
			b->price = ft_stack_len(b) - b->position;
		if (b->target->above_median == 1)
			b->price += b->target->position;
		else
			b->price += ft_stack_len(a) - b->target->position;
		b = b->next;
	}
}

void	ft_cheapest(t_stack *b)
{
	long	best;
	t_stack	*best_match;

	if (b == NULL)
		return ;
	best = 2147483648;
	while (b)
	{
		if (b->price < best)
		{
			best = b->price;
			best_match = b;
		}
		b = b->next;
	}
	best_match->cheapest = true;
}

void	ft_info_nodes(t_stack *a, t_stack *b)
{
	ft_current_position(a);
	ft_current_position(b);
	ft_target(a, b);
	ft_price(a, b);
	ft_cheapest(b);
}
