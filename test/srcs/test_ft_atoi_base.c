/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:30:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/04 14:14:14 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if FT_ATOI_BASE

static char	test_ft_atoi_base_case(char const *test_name, char *str, char *base, t_args *args)
{
	char	ko;

	if (args->verbose > 1)
		printf("\tft_atoi_base(\"%s\", \"%s\"):", str, base);
	else if (args->verbose)
		printf("\t%s", test_name);
	ko = FALSE;
	if (ft_atoi_base_c_piscine(str, base) != ft_atoi_base(str, base))
		ko = TRUE;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static void	test_ft_atoi_base_basic_cases(char *ko, t_args *args)
{
	if (test_ft_atoi_base_case("1_deci:\t\t", "1", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("-1_deci:\t", "-1", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("42_deci:\t", "42", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("-42_deci:\t", "-42", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("+42_deci:\t", "+42", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("0_deci:\t\t", "0", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("int_max_deci:\t", "2147483647", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("int_min_deci:\t", "-2147483648", "0123456789", args))
		*ko = TRUE;
}

static void	test_ft_atoi_base_complex_cases(char *ko, t_args *args)
{
	if (test_ft_atoi_base_case("multiple_signs1:", "--+42", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("multiple_signs2:", "+-+42", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("whitespaces:\t", "\t  \r\n\n\f\t\v  \t\t+42", "0123456789", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("hex_base:\t", "\t\t  -+ABF2", "0123456789ABCDEF", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("binary_base:\t", "\t\t  -+10101000", "01", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("wtf_base:\t", "\t\t  -+onfiv", "poneyvif", args))
		*ko = TRUE;
}

static void	test_ft_atoi_base_error_cases(char *ko, t_args *args)
{
	if (test_ft_atoi_base_case("1_len_base:\t", "42", "0", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("2_same_chars_base:", "42", "0123345678", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("+_in_base:\t", "42", "0123456+89", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("-_in_base:\t", "42", "0123456-89", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("<space>_in_base:", "42", "0123456 89", args))
		*ko = TRUE;
	if (test_ft_atoi_base_case("<newline>_in_base:", "42", "0123456\t89", args))
		*ko = TRUE;
}

void	test_ft_atoi_base(t_args *args)
{
	static char	done = FALSE;
	char		ko;

	if (done)
		return ;
	if (args->verbose)
		printf(BOLD "ft_atoi_base:\n" RESET);
	else
		printf(BOLD "ft_atoi_base:" RESET);
	ko = FALSE;
	test_ft_atoi_base_basic_cases(&ko, args);
	test_ft_atoi_base_complex_cases(&ko, args);
	test_ft_atoi_base_error_cases(&ko, args);
	if (!args->verbose)
		print_result(ko);
	done = TRUE;
}

#else

void	test_ft_atoi_base(t_args *args)
{
	static char done = FALSE;

	if (done)
		return ;
	if (!args->verbose)
		printf(BOLD "ft_atoi_base:" RESET YELLOW "\tInactive\n" RESET);
	else
		printf(BOLD "ft_atoi_base:\n" RESET YELLOW "\t\t\t\tInactive\n" RESET);
	done = TRUE;
}

#endif
