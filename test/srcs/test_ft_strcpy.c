/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:40:18 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/02 09:09:08 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static int	test_ft_strcpy_case(char const *test_name, char const *src, t_args *args)
{
	char	ko;
	char	dest[101];
	char	ft_dest[101];

	ko = 0;
	if (args->verbose > 1)
		printf("\tft_strcpy(dest, \"%s\"):", src);
	else if (args->verbose)
		printf("\t%s", test_name);
	strcpy(dest, src);
	if (ft_dest != ft_strcpy(ft_dest, src))
		ko = 1;
	if (strcmp(dest, ft_dest))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

void	test_ft_strcpy(t_args *args)
{
	static char	done = 0;
	char		ko;
	char		*long_src;

	if (done)
		return ;
	ko = 0;
	if (args->verbose)
		printf(BOLD "ft_strcpy:\n" RESET);
	else
		printf(BOLD "ft_strcpy:" RESET);
	if (test_ft_strcpy_case("empty_source_string:", "", args))
		ko = 1;
	if (test_ft_strcpy_case("one_char_source_string:", "0", args))
		ko = 1;
	if (test_ft_strcpy_case("small_source_string:", "0123456789", args))
		ko = 1;
	long_src = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	if (test_ft_strcpy_case("long_source_string:", long_src, args))
		ko = 1;
	if (!args->verbose)
		print_result(ko);
	done = 1;
}
