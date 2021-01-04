/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 09:06:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/03 16:30:21 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	init_args(t_args *args)
{
	args->all = FALSE;
	args->bonus = FALSE;
	args->verbose = 0;
	args->help = FALSE;
	args->strlen = FALSE;
	args->strcpy = FALSE;
	args->strcmp = FALSE;
	args->write = FALSE;
	args->read = FALSE;
	args->strdup = FALSE;
	args->atoi_base = FALSE;
	args->list_push_front = FALSE;
	args->list_size = FALSE;
	args->list_sort = FALSE;
	args->list_remove_if = FALSE;
}

static int	parse_long_flag(char *av, t_args *args)
{
	if (!strcmp(av, "all"))
		args->all = TRUE;
	else if (!strcmp(av, "bonus"))
		args->bonus = TRUE;
	else if (!strcmp(av, "verbose"))
		args->verbose++;
	else if (!strcmp(av, "help"))
		args->help = TRUE;
	else
	{
		dprintf(2, BOLD RED "--%s:" RESET RED " unknown flag\n" RESET, av);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	parse_flag(char *av, t_args *args)
{
	if (!*av)
	{
		dprintf(2, BOLD RED "-%c:" RESET RED " unknown flag\n" RESET, *av);
		return (FAILURE);
	}
	if (*av == '-')
		return (parse_long_flag(av + 1, args));
	while (*av)
	{
		if (*av == 'a')
			args->all = TRUE;
		else if (*av == 'b')
			args->bonus = TRUE;
		else if (*av == 'v')
			args->verbose++;
		else if (*av == 'h')
			args->help = TRUE;
		else
		{
			dprintf(2, BOLD RED "-%c:" RESET RED " unknown flag\n" RESET, *av);
			return (FAILURE);
		}
		av++;
	}
	return (SUCCESS);
}

static int	parse_ft(char *av, t_args *args)
{
	char	*av_bp;

	av_bp = av;
	if (!strncmp(av, "ft_", 3))
		av += 3;
	if (!strcmp(av, "strlen"))
		args->strlen = TRUE;
	else if (!strcmp(av, "strcpy"))
		args->strcpy = TRUE;
	else if (!strcmp(av, "strcmp"))
		args->strcmp = TRUE;
	else if (!strcmp(av, "write"))
		args->write = TRUE;
	else if (!strcmp(av, "read"))
		args->read = TRUE;
	else if (!strcmp(av, "strdup"))
		args->strdup = TRUE;
	else if (!strcmp(av, "atoi_base"))
		args->atoi_base = TRUE;
	else if (!strcmp(av, "list_push_front"))
		args->list_push_front = TRUE;
	else if (!strcmp(av, "list_size"))
		args->list_size = TRUE;
	else if (!strcmp(av, "list_sort"))
		args->list_sort = TRUE;
	else if (!strcmp(av, "list_remove_if"))
		args->list_remove_if = TRUE;
	else
	{
		dprintf(2, BOLD RED "%s:" RESET RED " unknown function\n" RESET, av_bp);
		return (FAILURE);
	}
	return (SUCCESS);
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
				return (FAILURE);
		}
		else if (parse_ft(av[i], args))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
