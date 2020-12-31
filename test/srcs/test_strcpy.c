/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:40:18 by clbrunet          #+#    #+#             */
/*   Updated: 2020/12/26 15:13:37 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static int	empty_source_string(t_args *args)
{
	char	ko;
	char	dest[1];
	char	ft_dest[1];

	ko = 0;
	if (args->verbose)
		printf("\tempty_source_string:");
	strcpy(dest, "");
	if (ft_dest != ft_strcpy(ft_dest, ""))
		ko = 1;
	if (strcmp(dest, ft_dest))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	one_char_source_string(t_args *args)
{
	char	ko;
	char	dest[2];
	char	ft_dest[2];

	ko = 0;
	if (args->verbose)
		printf("\tone_char_source_string:");
	strcpy(dest, "0");
	if (ft_dest != ft_strcpy(ft_dest, "0"))
		ko = 1;
	if (strcmp(dest, ft_dest))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	small_source_string(t_args *args)
{
	char	ko;
	char	dest[11];
	char	ft_dest[11];

	ko = 0;
	if (args->verbose)
		printf("\tsmall_source_string:");
	strcpy(dest, "0123456789");
	if (ft_dest != ft_strcpy(ft_dest, "0123456789"))
		ko = 1;
	if (strcmp(dest, ft_dest))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static int	long_source_string(t_args *args)
{
	char	ko;
	char	dest[101];
	char	ft_dest[101];
	char	*str;

	str = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	ko = 0;
	if (args->verbose)
		printf("\tlong_source_string:");
	strcpy(dest, str);
	if (ft_dest != ft_strcpy(ft_dest, str))
		ko = 1;
	if (strcmp(dest, ft_dest))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

void	test_strcpy(t_args *args)
{
	static char	done = 0;
	char		ko;

	if (done)
		return ;
	ko = 0;
	if (args->verbose)
		printf(BOLD "ft_strcpy:\n" RESET);
	else
		printf(BOLD "ft_strcpy:" RESET);
	if (empty_source_string(args))
		ko = 1;
	if (one_char_source_string(args))
		ko = 1;
	if (small_source_string(args))
		ko = 1;
	if (long_source_string(args))
		ko = 1;
	if (!args->verbose)
		print_result(ko);
	done = 1;
}
