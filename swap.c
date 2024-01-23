/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:55:37 by pbotargu          #+#    #+#             */
/*   Updated: 2023/12/27 23:39:33 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	int	aux;

	if (*a == NULL || a == NULL)
		return ;
	if (ft_stack_len(*a) < 2)
		return ;
	aux = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = aux;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	int	aux;

	if (*b == NULL || b == NULL)
		return ;
	if (ft_stack_len(*b) < 2)
		return ;
	aux = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = aux;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
