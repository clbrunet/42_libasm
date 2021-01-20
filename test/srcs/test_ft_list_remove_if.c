/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 06:36:03 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/20 14:50:33 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if FT_LIST_REMOVE_IF

static char	check_list_removals(t_list *begin_list, void *data_ref)
{
	while (begin_list)
	{
		if (!strcmp(begin_list->data, data_ref))
			return (FAILURE);
		begin_list = begin_list->next;
	}
	return (SUCCESS);
}

static char	test_ft_list_remove_if_case(char const *test_name, t_list *begin_list, void *data_ref, t_args *args)
{
	char	ko;

	if (args->verbose > 1)
		printf("\tft_list_remove_if(begin_list, \"%s\", &strcmp, &free):", data_ref);
	else if (args->verbose)
		printf("\t%s", test_name);
	ko = FALSE;
	ft_list_remove_if(&begin_list, data_ref, &strcmp, &free);
	ko = check_list_removals(begin_list, data_ref);
	if (ko == FALSE)
		ft_lstclear(&begin_list, &free);
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static void	test_ft_list_remove_if_noremove_cases(char *ko, t_args *args)
{
	t_list		*begin_list;
	unsigned	i;

	begin_list = ft_lstnew(strdup("."));
	if (test_ft_list_remove_if_case("1_elem_list_noremove:", begin_list, ":", args))
		*ko = TRUE;
	begin_list = NULL;
	i = 0;
	while (i++ < 10)
		ft_list_push_front_libft(&begin_list, strdup("."));
	if (test_ft_list_remove_if_case("small_list_noremove:", begin_list, ":", args))
		*ko = TRUE;
	begin_list = NULL;
	i = 0;
	while (i++ < 100)
		ft_list_push_front_libft(&begin_list, strdup("."));
	if (test_ft_list_remove_if_case("big_list_noremove:", begin_list, ":", args))
		*ko = TRUE;
}
static void	test_ft_list_remove_if_remove_cases(char *ko, t_args *args)
{
	t_list		*begin_list;
	unsigned	i;

	begin_list = ft_lstnew(strdup("."));
	if (test_ft_list_remove_if_case("1_elem_list_remove:", begin_list, ".", args))
		*ko = TRUE;
	begin_list = NULL;
	ft_list_push_front_libft(&begin_list, strdup("."));
	i = 1;
	while (i++ < 4)
		ft_list_push_front_libft(&begin_list, strdup(":"));
	ft_list_push_front_libft(&begin_list, strdup("."));
	ft_list_push_front_libft(&begin_list, strdup("."));
	while (i++ < 6)
		ft_list_push_front_libft(&begin_list, strdup(":"));
	ft_list_push_front_libft(&begin_list, strdup("."));
	if (test_ft_list_remove_if_case("small_list_removes:", begin_list, ".", args))
		*ko = TRUE;
	begin_list = NULL;
	i = 0;
	while (i++ < 25)
		ft_list_push_front_libft(&begin_list, strdup(":"));
	while (i++ < 75)
		ft_list_push_front_libft(&begin_list, strdup("."));
	while (i++ < 100)
		ft_list_push_front_libft(&begin_list, strdup(":"));
	if (test_ft_list_remove_if_case("big_list_removes:", begin_list, ".", args))
		*ko = TRUE;
}

void	test_ft_list_remove_if(t_args *args)
{
	static char	done = FALSE;
	char		ko;

	if (done)
		return ;
	if (args->verbose)
		printf(BOLD "ft_list_remove_if:\n" RESET);
	else
		printf(BOLD "ft_list_remove_if:" RESET);
	ko = test_ft_list_remove_if_case("empty_list:\t", NULL, "a", args);
	test_ft_list_remove_if_noremove_cases(&ko, args);
	test_ft_list_remove_if_remove_cases(&ko, args);
	if (!args->verbose)
		print_result(ko);
	done = TRUE;
}

#else

void	test_ft_list_remove_if(t_args *args)
{
	static char done = FALSE;

	if (done)
		return ;
	if (!args->verbose)
		printf(BOLD "ft_list_remove_if:" RESET YELLOW "\tInactive\n" RESET);
	else
		printf(BOLD "ft_list_remove_if:\n" RESET
				YELLOW "\tInactive\n" RESET);
	done = TRUE;
}

#endif
