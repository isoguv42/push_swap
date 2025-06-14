/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:16 by igyuveni          #+#    #+#             */
/*   Updated: 2025/04/03 21:12:46 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_args
{
	char	**values;
	int		count;
	int		should_free;
}	t_args;

t_args	normalize_args(int argc, char **argv);
t_node	*init_stack(int argc, char **argv);
void	assign_indexes(t_node *stack);
void	sort_small(t_node **stack);
void	sort_medium(t_node **a, t_node **b);
int		find_min_position(t_node *stack);
void	radix_sort(t_node **a, t_node **b);
void	sa(t_node **stack);
void	ra(t_node **stack);
void	rra(t_node **stack);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
int		is_sorted(t_node *stack);
int		stack_size(t_node *stack);
void	exit_error_handler(t_node **stack, t_args *args, int print_error);
void	free_stack(t_node **stack);

#endif