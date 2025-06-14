/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:27 by igyuveni          #+#    #+#             */
/*   Updated: 2025/04/01 17:11:28 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** Parse string argument by splitting on spaces */
static t_args	parse_split_args(char *str)
{
	t_args	args;
	int		i;

	i = 0;
	args.values = ft_split(str, ' ');
	if (!args.values)
		exit_error_handler(NULL, NULL, 1);
	if (!*args.values)
	{
		args.should_free = 1;
		exit_error_handler(NULL, &args, 1);
	}
	while (args.values[i])
		i++;
	args.count = i;
	args.should_free = 1;
	return (args);
}

/** Parse individual command line arguments */
static t_args	parse_direct_args(int argc, char **argv)
{
	t_args	args;

	args.values = &argv[1];
	args.count = argc - 1;
	args.should_free = 0;
	return (args);
}

/** Normalize arguments into consistent format */
t_args	normalize_args(int argc, char **argv)
{
	if (argc == 2)
		return (parse_split_args(argv[1]));
	return (parse_direct_args(argc, argv));
}
