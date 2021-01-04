/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:53:28 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/04 07:29:19 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/libasm_test.h"

void	ft_list_push_front_libft(t_list **begin_list, void *data)
{
	t_list	*new;

	if (!begin_list)
		return ;
	new = ft_lstnew(data);
	if (!new)
		return ;
	if (!*begin_list)
	{
		*begin_list = new;
		return ;
	}
	new->next = *begin_list;
	*begin_list = new;
}
