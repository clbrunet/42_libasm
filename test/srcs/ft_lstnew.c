/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:50:21 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/04 06:41:55 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if BONUS_PRESENT

t_list	*ft_lstnew(void *data)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return ((t_list *)NULL);
	new->data = data;
	new->next = (t_list *)NULL;
	return (new);
}

#endif
