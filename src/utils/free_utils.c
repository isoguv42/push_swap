/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:30 by igyuveni          #+#    #+#             */
/*   Updated: 2025/04/01 17:11:31 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Free all nodes in a stack */
void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/** Handle errors, clean memory and exit program */
void	exit_error_handler(t_node **stack, t_args *args, int print_error)
{
	if (args && args->should_free)
		ft_free_split(args->values);
	if (stack)
		free_stack(stack);
	if (print_error)
		write(2, "Error\n", 6);
	exit(1);
}
