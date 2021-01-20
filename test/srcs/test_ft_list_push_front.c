/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 06:36:03 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/19 15:00:00 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if FT_LIST_PUSH_FRONT

static char	test_ft_list_push_front_case(char const *test_name, t_list *begin_list, void *data, t_args *args)
{
	t_list	*begin_list_backup;
	char	ko;

	if (args->verbose > 1)
		printf("\tft_list_push_front(begin_list, \"%s\"):", data);
	else if (args->verbose)
		printf("\t%s", test_name);
	begin_list_backup = begin_list;
	ko = FALSE;
	ft_list_push_front(&begin_list, data);
	if (!begin_list)
		ko = TRUE;
	else if (begin_list->data != data)
		ko = TRUE;
	else if (begin_list->next != begin_list_backup)
		ko = TRUE;
	if (ko == FALSE)
		ft_lstclear(&begin_list, &free);
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static void	test_ft_list_push_front_cases(char *ko, t_args *args)
{
	t_list		*begin_list;
	unsigned	i;

	begin_list = NULL;
	if (test_ft_list_push_front_case("empty_list:\t", begin_list, strdup("a"), args))
		*ko = TRUE;
	begin_list = ft_lstnew(strdup("a"));
	if (test_ft_list_push_front_case("1_link_list:\t", begin_list, strdup("b"), args))
		*ko = TRUE;
	begin_list = NULL;
	i = 0;
	while (i++ < 10)
		ft_list_push_front_libft(&begin_list, strdup("."));
	if (test_ft_list_push_front_case("small_list:\t", begin_list, strdup(":"), args))
		*ko = TRUE;
	begin_list = NULL;
	i = 0;
	while (i++ < 100)
		ft_list_push_front_libft(&begin_list, strdup("."));
	if (test_ft_list_push_front_case("big_list:\t", begin_list, strdup(":"), args))
		*ko = TRUE;
}

void	test_ft_list_push_front(t_args *args)
{
	static char	done = FALSE;
	char		ko;

	if (done)
		return ;
	if (args->verbose)
		printf(BOLD "ft_list_push_front:\n" RESET);
	else
		printf(BOLD "ft_list_push_front:" RESET);
	ko = FALSE;
	test_ft_list_push_front_cases(&ko, args);
	if (!args->verbose)
		print_result(ko);
	done = TRUE;
}

#else

void	test_ft_list_push_front(t_args *args)
{
	static char done = FALSE;

	if (done)
		return ;
	if (!args->verbose)
		printf(BOLD "ft_list_push_front:" RESET YELLOW "\tInactive\n" RESET);
	else
		printf(BOLD "ft_list_push_front:\n" RESET
				YELLOW "\tInactive\n" RESET);
	done = TRUE;
}

#endif
