/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 09:06:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/02 09:10:02 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	init_args(t_args *args)
{
	args->all = 0;
	args->bonus = 0;
	args->verbose = 0;
	args->help = 0;
	args->strlen = 0;
	args->strcpy = 0;
	args->strcmp = 0;
	args->write = 0;
	args->read = 0;
	args->strdup = 0;
}

static int	parse_long_flag(char *av, t_args *args)
{
	if (!strcmp(av, "all"))
		args->all = 1;
	else if (!strcmp(av, "bonus"))
		args->bonus = 1;
	else if (!strcmp(av, "verbose"))
		args->verbose++;
	else if (!strcmp(av, "help"))
		args->help = 1;
	else
	{
		dprintf(2, BOLD RED "--%s:" RESET RED " unknown flag\n" RESET, av);
		return (1);
	}
	return (0);
}

static int	parse_flag(char *av, t_args *args)
{
	if (!*av)
	{
		dprintf(2, BOLD RED "-%c:" RESET RED " unknown flag\n" RESET, *av);
		return (1);
	}
	if (*av == '-')
		return (parse_long_flag(av + 1, args));
	while (*av)
	{
		if (*av == 'a')
			args->all = 1;
		else if (*av == 'b')
			args->bonus = 1;
		else if (*av == 'v')
			args->verbose++;
		else if (*av == 'h')
			args->help = 1;
		else
		{
			dprintf(2, BOLD RED "-%c:" RESET RED " unknown flag\n" RESET, *av);
			return (1);
		}
		av++;
	}
	return (0);
}

static int	parse_ft(char *av, t_args *args)
{
	char	*av_bp;

	av_bp = av;
	if (!strncmp(av, "ft_", 3))
		av += 3;
	if (!strcmp(av, "strlen"))
		args->strlen = 1;
	else if (!strcmp(av, "strcpy"))
		args->strcpy = 1;
	else if (!strcmp(av, "strcmp"))
		args->strcmp = 1;
	else if (!strcmp(av, "write"))
		args->write = 1;
	else if (!strcmp(av, "read"))
		args->read = 1;
	else if (!strcmp(av, "strdup"))
		args->strdup = 1;
	else
	{
		dprintf(2, BOLD RED "%s:" RESET RED " unknown function\n" RESET, av_bp);
		return (1);
	}
	return (0);
}

int	parse_av(int ac, char **av, t_args *args)
{
	int		i;

	init_args(args);
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (parse_flag(av[i] + 1, args))
				return (1);
		}
		else if (parse_ft(av[i], args))
			return (1);
		i++;
	}
	return (0);
}
