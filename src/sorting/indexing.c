/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:33 by igyuveni          #+#    #+#             */
/*   Updated: 2025/04/01 17:11:34 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Assign simplified index values to stack nodes */
void	assign_indexes(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	int		idx;

	i = stack;
	while (i)
	{
		j = stack;
		idx = 0;
		while (j)
		{
			if (j->value < i->value)
				idx++;
			j = j->next;
		}
		i->index = idx;
		i = i->next;
	}
}
