/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:30:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/02 07:45:27 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static int	test_ft_strlen_case(char const *test_name, char const *str, t_args *args)
{
	char	ko;

	if (args->verbose > 1)
		printf("\tft_strlen(\"%s\"):", str);
	else if (args->verbose)
		printf("\t%s", test_name);
	ko = 0;
	if (strlen(str) != ft_strlen(str))
		ko = 1;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

void	test_ft_strlen(t_args *args)
{
	static char	done = 0;
	char		ko;
	char		*long_str;

	if (done)
		return ;
	ko = 0;
	if (args->verbose)
		printf(BOLD "ft_strlen:\n" RESET);
	else
		printf(BOLD "ft_strlen:" RESET);
	if (test_ft_strlen_case("empty_string:\t", "", args))
		ko = 1;
	if (test_ft_strlen_case("one_char_string:", "0", args))
		ko = 1;
	if (test_ft_strlen_case("small_string:\t", "0123456789", args))
		ko = 1;
	long_str = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	if (test_ft_strlen_case("long_string:\t", long_str, args))
		ko = 1;
	if (!args->verbose)
		print_result(ko);
	done = 1;
}
