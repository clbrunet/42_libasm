/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 08:40:24 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/02 18:01:57 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static int	test_ft_strdup_case(char const *test_name, char const *s, t_args *args)
{
	char	ko;
	char	*ft_dup;
	char	*dup;

	ko = FALSE;
	if (args->verbose > 1)
		printf("\tft_strdup(\"%s\"):", s);
	else if (args->verbose)
		printf("\t%s", test_name);
	ft_dup = ft_strdup(s);
	dup = strdup(s);
	if (dup && ft_dup && strcmp(dup, ft_dup) != 0)
		ko = TRUE;
	free(dup);
	free(ft_dup);
	if (!dup || !ft_dup)
	{
		ko = ERROR;
		fflush(stdout);
		if (args->verbose)
			dprintf(2, RED "\tInsufficient memory.\n" RESET);
	}
	else if (args->verbose)
		print_result(ko);
	return (ko);
}

static void	test_ft_strdup2(char ko, t_args *args)
{
	char	ret;
	char	*long_s;

	long_s = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	ret = test_ft_strdup_case("long_string:\t", long_s, args);
	if (ko != ERROR && ret)
		ko = ret;
	if (!args->verbose && ko == ERROR)
	{
		fflush(stdout);
		dprintf(2, RED "\tInsufficient memory.\n" RESET);
	}
	else if (!args->verbose)
		print_result(ko);
}

void	test_ft_strdup(t_args *args)
{
	static char	done = FALSE;
	char		ko;
	char		ret;

	if (done)
		return ;
	if (args->verbose)
		printf(BOLD "ft_strdup:\n" RESET);
	else
		printf(BOLD "ft_strdup:" RESET);
	ko = test_ft_strdup_case("empty_string:\t", "", args);
	ret = test_ft_strdup_case("one_char_string:", "0", args);
	if (ko != ERROR && ret)
		ko = ret;
	ret = test_ft_strdup_case("small_string:\t", "0123456789", args);
	if (ko != ERROR && ret)
		ko = ret;
	test_ft_strdup2(ko, args);
	done = TRUE;
}
