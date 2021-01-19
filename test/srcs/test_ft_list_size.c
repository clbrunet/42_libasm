/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 06:36:03 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/19 07:24:10 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if FT_LIST_SIZE

static char	test_ft_list_size_case(char const *test_name, t_list *begin_list, t_args *args)
{
	char	ko;

	if (args->verbose > 1)
		printf("\tft_list_size(begin_list):");
	else if (args->verbose)
		printf("\t%s", test_name);
	ko = FALSE;
	if (ft_list_size(begin_list) != ft_list_size_libft(begin_list))
		ko = TRUE;
	if (args->verbose)
		print_result(ko);
	return (ko);
}

void	test_ft_list_size_cases(char *ko, t_args *args)
{
	t_list		*begin_list;
	unsigned	i;

	begin_list = NULL;
	*ko = test_ft_list_size_case("empty_list:\t", begin_list, args);
	ft_list_push_front_libft(&begin_list, NULL);
	if (test_ft_list_size_case("1_link_list:\t", begin_list, args))
		*ko = TRUE;
	i = 0;
	while (i++ < 10)
		ft_list_push_front_libft(&begin_list, NULL);
	if (test_ft_list_size_case("small_list:\t", begin_list, args))
		*ko = TRUE;
	while (i++ < 100)
		ft_list_push_front_libft(&begin_list, NULL);
	if (test_ft_list_size_case("big_list:\t", begin_list, args))
		*ko = TRUE;
	ft_lstclear(&begin_list, &free);
}

void	test_ft_list_size(t_args *args)
{
	static char	done = FALSE;
	char		ko;

	if (done)
		return ;
	if (args->verbose)
		printf(BOLD "ft_list_size:\n" RESET);
	else
		printf(BOLD "ft_list_size:\t" RESET);
	ko = FALSE;
	test_ft_list_size_cases(&ko, args);
	if (!args->verbose)
		print_result(ko);
	done = TRUE;
}

#else

void	test_ft_list_size(t_args *args)
{
	static char done = FALSE;

	if (done)
		return ;
	if (!args->verbose)
		printf(BOLD "ft_list_size:\t" RESET YELLOW "\tInactive\n" RESET);
	else
		printf(BOLD "ft_list_size:\n" RESET YELLOW "\tInactive\n" RESET);
	done = TRUE;
}

#endif
