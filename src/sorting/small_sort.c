/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:50 by igyuveni          #+#    #+#             */
/*   Updated: 2025/04/03 21:10:54 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Sort 3 elements using optimal operations */
void	sort_small(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

/** Move minimum element to top of stack */
static void	move_min_to_top(t_node **a, int min_pos, int size)
{
	int	is_first_half;

	is_first_half = (min_pos <= size / 2);
	if (is_first_half)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
}

/** Sort 4-5 elements by pushing minimum values to B */
void	sort_medium(t_node **a, t_node **b)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	if (size <= 3)
	{
		sort_small(a);
		return ;
	}
	while (size > 3)
	{
		min_pos = find_min_position(*a);
		move_min_to_top(a, min_pos, size);
		pb(a, b);
		size--;
	}
	sort_small(a);
	while (*b)
		pa(a, b);
}
