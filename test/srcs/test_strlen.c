/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:30:37 by clbrunet          #+#    #+#             */
/*   Updated: 2020/12/26 15:12:51 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static int	empty_string(t_args *args)
{
	char	ko;

	ko = 0;
	if (args->verbose)
		printf("\tempty_string:\t");
	if (strlen("") != ft_strlen(""))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	one_char_string(t_args *args)
{
	char	ko;

	ko = 0;
	if (args->verbose)
		printf("\tone_char_string:");
	if (strlen("0") != ft_strlen("0"))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	small_string(t_args *args)
{
	char	ko;

	ko = 0;
	if (args->verbose)
		printf("\tsmall_string:\t");
	if (strlen("0123456789") != ft_strlen("0123456789"))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	long_string(t_args *args)
{
	char	ko;
	char	*str;

	str = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	ko = 0;
	if (args->verbose)
		printf("\tlong_string:\t");
	if (strlen(str) != ft_strlen(str))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

void	test_strlen(t_args *args)
{
	static char	done = 0;
	char		ko;

	if (done)
		return ;
	ko = 0;
	if (args->verbose)
		printf(BOLD "ft_strlen:\n" RESET);
	else
		printf(BOLD "ft_strlen:" RESET);
	if (empty_string(args))
		ko = 1;
	if (one_char_string(args))
		ko = 1;
	if (small_string(args))
		ko = 1;
	if (long_string(args))
		ko = 1;
	if (!args->verbose)
		print_result(ko);
	done = 1;
}
