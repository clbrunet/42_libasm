/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 08:40:24 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/02 10:42:28 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static int	test_ft_strdup_case(char const *test_name, char const *s, t_args *args)
{
	static char	ko = 0;
	char	*dup;
	char	*ft_dup;

	if (ko == -1)
		return (0);
	ko = 0;
	if (args->verbose > 1)
		printf("\tft_strdup(\"%s\"):", s);
	else if (args->verbose)
		printf("\t%s", test_name);
	fflush(stdout);
	dup = strdup(s);
	ft_dup = ft_strdup(s);
	if (dup && ft_dup && strcmp(dup, ft_dup) != 0)
		ko = 1;
	free(dup);
	free(ft_dup);
	if (!dup || !ft_dup)
	{
		dprintf(2, RED "\tInsufficient memory.\n" RESET);
		ko = -1;
	}
	else if (args->verbose)
		print_result(ko);
	return (ko);
}

void	test_ft_strdup(t_args *args)
{
	static char	done = 0;
	char		ko;
	char		ret;
	char		*long_s;

	if (done)
		return ;
	ko = 0;
	if (args->verbose)
		printf(BOLD "ft_strdup:\n" RESET);
	else
		printf(BOLD "ft_strdup:" RESET);
	ret = test_ft_strdup_case("empty_string:\t", "", args);
	if (ret)
		ko = ret;
	ret = test_ft_strdup_case("one_char_string:", "0", args);
	if (ko != -1 && ret)
		ko = ret;
	ret = test_ft_strdup_case("small_string:\t", "0123456789", args);
	if (ko != -1 && ret)
		ko = ret;
	long_s = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	ret = test_ft_strdup_case("long_string:\t", long_s, args);
	if (ko != -1 && ret)
		ko = ret;
	if (!args->verbose && ko != -1)
		print_result(ko);
	done = 1;
}
