/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:40:18 by clbrunet          #+#    #+#             */
/*   Updated: 2020/12/31 09:45:32 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static int	empty_strings(t_args *args)
{
	char	ko;

	ko = 0;
	if (args->verbose)
		printf("\tempty_strings:\t");
	if (ft_strcmp("", "") != 0 && strcmp("", "") == 0)
		ko = 1;
	else if (ft_strcmp("", "abc") >= 0 && strcmp("", "abc") < 0)
		ko = 1;
	else if (ft_strcmp("abc", "") <= 0 && strcmp("abc", "") > 0)
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	same_strings(t_args *args)
{
	char	ko;

	ko = 0;
	if (args->verbose)
		printf("\tsame_strings:\t");
	if (ft_strcmp("0123456789", "0123456789") != 0
			&& strcmp("0123456789", "0123456789") == 0)
		ko = 1;
	else if (ft_strcmp("abc", "abc") != 0 && strcmp("abc", "abc") == 0)
		ko = 1;
	else if (ft_strcmp("ABCDEFG", "ABCDEFG") != 0
			&& strcmp("ABCDEFG", "ABCDEFG") == 0)
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	diff_on_last_char(t_args *args)
{
	char	ko;

	ko = 0;
	if (args->verbose)
		printf("\tdiff_on_last_char:");
	if (ft_strcmp("0123456789", "012345678")
			!= strcmp("0123456789", "012345678"))
		ko = 1;
	else if (ft_strcmp("012345678", "0123456789")
			!= strcmp("012345678", "0123456789"))
		ko = 1;
	else if (ft_strcmp("abc", "abd") != strcmp("abc", "abd"))
		ko = 1;
	else if (ft_strcmp("abd", "abc") != strcmp("abd", "abc"))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	long_strings(t_args *args)
{
	char	ko;
	char	*str;
	char	*str2;
	char	*str3;

	str = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	str2 = "91234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	str3 = "01234567890123456789012345678901234567890123456789"
		"91234567890123456789012345678901234567890123456789";
	ko = 0;
	if (args->verbose)
		printf("\tlong_strings:\t");
	if (ft_strcmp(str, str) != strcmp(str, str))
		ko = 1;
	else if (ft_strcmp(str, str2) != strcmp(str, str2))
		ko = 1;
	else if (ft_strcmp(str2, str) != strcmp(str2, str))
		ko = 1;
	else if (ft_strcmp(str3, str) != strcmp(str3, str))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

void	test_strcmp(t_args *args)
{
	static char	done = 0;
	char		ko;

	if (done)
		return ;
	ko = 0;
	if (args->verbose)
		printf(BOLD "ft_strcmp:\n" RESET);
	else
		printf(BOLD "ft_strcmp:" RESET);
	if (empty_strings(args))
		ko = 1;
	if (same_strings(args))
		ko = 1;
	if (diff_on_last_char(args))
		ko = 1;
	if (long_strings(args))
		ko = 1;
	if (!args->verbose)
		print_result(ko);
	done = 1;
}
