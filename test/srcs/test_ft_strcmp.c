/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:40:18 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/04 14:16:07 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if FT_STRCMP

static char	simplify_sign(int nb)
{
	if (nb < 0)
		return (-1);
	else if (nb == 0)
		return (0);
	else
		return (1);
}

static char	test_ft_strcmp_case(char const *test_name, char const *s1, char const *s2, t_args *args)
{
	char	ko;

	if (args->verbose > 1)
		printf("\tft_strcmp(\"%s\", \"%s\"):", s1, s2);
	else if (args->verbose)
		printf("\t%s", test_name);
	ko = FALSE;
	if (simplify_sign(ft_strcmp(s1, s2)) != simplify_sign(strcmp(s1, s2)))
		ko = TRUE;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static void	test_ft_strcmp2(char ko, t_args *args)
{
	char	*long_s1;
	char	*long_s2;

	if (test_ft_strcmp_case("diff_on_first_char:", "9123456789", "0123456789", args))
		ko = TRUE;
	if (test_ft_strcmp_case("diff_on_last_char:", "0123456789", "0123456780", args))
		ko = TRUE;
	long_s1 = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	long_s2 = "01234567890123456789012345678901234567890123456789"
		"91234567890123456789012345678901234567890123456789";
	if (test_ft_strcmp_case("same_long_strings:", long_s1, long_s1, args))
		ko = TRUE;
	if (test_ft_strcmp_case("different_long_strings:", long_s1, long_s2, args))
		ko = TRUE;
	if (!args->verbose)
		print_result(ko);
}

void	test_ft_strcmp(t_args *args)
{
	static char	done = FALSE;
	char		ko;

	if (done)
		return ;
	ko = FALSE;
	if (args->verbose)
		printf(BOLD "ft_strcmp:\n" RESET);
	else
		printf(BOLD "ft_strcmp:" RESET);
	if (test_ft_strcmp_case("empty_strings:\t", "", "", args))
		ko = TRUE;
	if (test_ft_strcmp_case("empty_s1:\t", "", "abc", args))
		ko = TRUE;
	if (test_ft_strcmp_case("empty_s2:\t", "abc", "", args))
		ko = TRUE;
	if (test_ft_strcmp_case("same_strings:\t", "0123456789", "0123456789", args))
		ko = TRUE;
	if (test_ft_strcmp_case("different_strings:", "01234A6789", "0123456789", args))
		ko = TRUE;
	if (test_ft_strcmp_case("missing_same_last_char:", "0123456789", "012345678", args))
		ko = TRUE;
	test_ft_strcmp2(ko, args);
	done = TRUE;
}

#else

void	test_ft_strcmp(t_args *args)
{
	static char done = FALSE;

	if (done)
		return ;
	if (!args->verbose)
		printf(BOLD "ft_strcmp:" RESET YELLOW "\tInactive\n" RESET);
	else
		printf(BOLD "ft_strcmp:\n" RESET YELLOW "\t\t\t\tInactive\n" RESET);
	done = TRUE;
}

#endif
