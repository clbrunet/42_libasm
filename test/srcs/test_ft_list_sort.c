/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 06:36:03 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/19 15:22:57 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if FT_LIST_SORT

static char	check_list_sort(t_list *begin_list)
{
	char	*tmp;

	tmp = "";
	while (begin_list)
	{
		if (strcmp(tmp, begin_list->data) > 0)
			return (FAILURE);
		tmp = begin_list->data;
		begin_list = begin_list->next;
	}
	return (SUCCESS);
}

static char	test_ft_list_sort_case(char const *test_name, t_list *begin_list, t_args *args)
{
	t_list	*begin_list_backup;
	char	ko;

	if (args->verbose > 1)
		printf("\tft_list_sort(begin_list, &strcmp):");
	else if (args->verbose)
		printf("\t%s", test_name);
	begin_list_backup = begin_list;
	ko = FALSE;
	ft_list_sort(&begin_list, &strcmp);
	if (!begin_list)
		ko = TRUE;
	else if (check_list_sort(begin_list))
		ko = TRUE;
	if (ko == FALSE)
		ft_lstclear(&begin_list, &free);
	if (args->verbose)
		print_result(ko);
	return (ko);
}

void	test_ft_list_sort_cases(char *ko, t_args *args)
{
	t_list		*begin_list;
	char		str[2];
	unsigned	i;

	begin_list = NULL;
	str[1] = 0;
	i = 0;
	while (i < 10)
	{
		str[0] = i++ + '0';
		ft_list_push_front_libft(&begin_list, strdup(str));
	}
	if (test_ft_list_sort_case("sorted_list:\t", begin_list, args))
		*ko = TRUE;
	begin_list = NULL;
	str[1] = 0;
	i = 9;
	while (i > 5)
	{
		str[0] = i-- + '0';
		ft_list_push_front_libft(&begin_list, strdup(str));
	}
	str[0] = '0';
	ft_list_push_front_libft(&begin_list, strdup(str));
	str[0] = '1';
	ft_list_push_front_libft(&begin_list, strdup(str));
	ft_list_push_front_libft(&begin_list, strdup(str));
	if (test_ft_list_sort_case("unsorted_list:\t", begin_list, args))
		*ko = TRUE;
}

void	test_ft_list_sort(t_args *args)
{
	static char	done = FALSE;
	char		ko;

	if (done)
		return ;
	if (args->verbose)
		printf(BOLD "ft_list_sort:\n" RESET);
	else
		printf(BOLD "ft_list_sort:\t" RESET);
	ko = FALSE;
	test_ft_list_sort_cases(&ko, args);
	if (!args->verbose)
		print_result(ko);
	done = TRUE;
}

#else

void	test_ft_list_sort(t_args *args)
{
	static char done = FALSE;

	if (done)
		return ;
	if (!args->verbose)
		printf(BOLD "ft_list_sort:\t" RESET YELLOW "\tInactive\n" RESET);
	else
		printf(BOLD "ft_list_sort:\n" RESET
				YELLOW "\tInactive\n" RESET);
	done = TRUE;
}

#endif
