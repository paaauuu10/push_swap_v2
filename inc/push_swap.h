/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:12:52 by pbotargu          #+#    #+#             */
/*   Updated: 2023/12/28 01:13:22 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

//struct used for the push_swap

typedef struct s_stack
{
	int				value;
	int				position;
	int				price;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Split
char	**ft_split(char const *s, char c);
char	**createwords(char const *s, char c, char **split);
int		checkwords(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);

// Initialize stack
void	ft_init_stack(t_stack **a, char **argv, int flag);
int		ft_syntax_error(char *s);
int		ft_find_repetition(t_stack *a, int nbr);
void	ft_add_to_final(t_stack **stack_a, int nbr);
t_stack	*ft_find_last(t_stack *stack_a);

// Stack utils
int		ft_is_sorted(t_stack *a);
int		ft_stack_len(t_stack *a);
t_stack	*ft_find_small(t_stack *a);

// Free and error
void	ft_error_free(t_stack **a, char **argv, int flag);
void	ft_free_stack(t_stack **a);
void	free_split(char **argv);

// How to handle errors
int		ft_syntax_error(char *s);
int		ft_find_repetition(t_stack *a, int nbr);

// Sort three
void	ft_sort_three(t_stack **a);

// Sort five 
void	ft_sort_five(t_stack **a, t_stack **b);

// Push_swap algorithm
void	ft_push_swap(t_stack **a, t_stack **b);

// Swap
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b);

// Push
void	pb(t_stack **b, t_stack **a);
void	pa(t_stack **a, t_stack **b);

// Rotate
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b);

// Reverse rotate
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b);

//Getting info for the nodes
void	ft_info_nodes(t_stack *a, t_stack *b);
void	ft_cheapest(t_stack *b);
void	ft_price(t_stack *a, t_stack *b);
void	ft_current_position(t_stack *a);

//LIBFT
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
