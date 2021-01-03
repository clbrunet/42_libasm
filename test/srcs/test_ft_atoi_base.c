/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:30:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/03 16:07:04 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static int	test_ft_atoi_base_case(char const *test_name, char *str, char *base, t_args *args)
{
	char	ko;

	if (args->verbose > 1)
		printf("\tft_atoi_base(\"%s\"):", str);
	else if (args->verbose)
		printf("\t%s", test_name);
	ko = FALSE;
	if (strtol(str, NULL, strlen(base)) != ft_atoi_base(str, base))
		ko = TRUE;
	if (args->verbose)
		print_result(ko);
	return (ko);
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
	if (test_ft_atoi_base_case("1_decimal:\t", "1", "0123456789", args))
		ko = TRUE;
	if (test_ft_atoi_base_case("-1_decimal:\t", "-1", "0123456789", args))
		ko = TRUE;
	if (test_ft_atoi_base_case("42_decimal:", "42", "0123456789", args))
		ko = TRUE;
	if (test_ft_atoi_base_case("-42_decimal:\t", "-42", "0123456789", args))
		ko = TRUE;
	if (test_ft_atoi_base_case("0_decimal:\t", "0", "0123456789", args))
		ko = TRUE;
	if (!args->verbose)
		print_result(ko);
	done = TRUE;
}
