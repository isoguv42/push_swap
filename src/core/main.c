/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:39 by igyuveni          #+#    #+#             */
/*   Updated: 2025/04/03 20:28:20 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Validate all input arguments are valid numbers */
static int	validate_input(t_args *input)
{
	int	i;

	if (!input || !input->values || input->count <= 0)
		return (0);
	i = 0;
	while (i < input->count)
	{
		if (!ft_isnum(input->values[i]))
		{
			exit_error_handler(NULL, input, 1);
			return (0);
		}
		i++;
	}
	return (1);
}

/** Choose and apply appropriate sorting algorithm based on stack size */
static void	sort_stacks(t_node **stack_a, t_node **stack_b, int count)
{
	if (is_sorted(*stack_a))
		return ;
	else if (count == 2)
		sa(stack_a);
	else if (count == 3)
		sort_small(stack_a);
	else if (count <= 6)
		sort_medium(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

/** Clean up and free all allocated memory */
static void	clean_exit(t_node **stack_a, t_node **stack_b, t_args *input)
{
	if (input && input->should_free)
		ft_free_split(input->values);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
}

/** Main function - entry point of the program */
int	main(int argc, char **argv)
{
	t_args	input;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (0);
	input = normalize_args(argc, argv);
	if (!validate_input(&input))
		return (1);
	stack_a = init_stack(input.count, input.values);
	assign_indexes(stack_a);
	stack_b = NULL;
	sort_stacks(&stack_a, &stack_b, input.count);
	clean_exit(&stack_a, &stack_b, &input);
	return (0);
}
