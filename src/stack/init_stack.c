/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:36 by igyuveni          #+#    #+#             */
/*   Updated: 2025/04/03 18:29:10 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Add new node to the end of the stack */
static void	add_back(t_node **stack, t_node *new)
{
	t_node	*temp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

/** Check if stack contains duplicate values */
static int	has_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (check->value == current->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

/** Convert string to long integer with overflow protection */
static long	str_to_long(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}

/** Initialize stack from command line arguments */
t_node	*init_stack(int argc, char **argv)
{
	t_node	*head;
	t_node	*new;
	long	num;
	int		i;

	i = 0;
	head = NULL;
	while (i < argc)
	{
		num = str_to_long(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			exit_error_handler(&head, NULL, 1);
		new = malloc(sizeof(t_node));
		if (!new)
			exit_error_handler(&head, NULL, 1);
		new->value = (int)num;
		new->index = 0;
		new->next = NULL;
		add_back(&head, new);
		i++;
	}
	if (has_duplicates(head))
		exit_error_handler(&head, NULL, 1);
	return (head);
}
