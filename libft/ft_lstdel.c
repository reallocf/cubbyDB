/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:34:32 by csummers          #+#    #+#             */
/*   Updated: 2016/11/04 12:34:33 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*lst;

	if (!alst || !del)
		return ;
	lst = *alst;
	while (lst)
	{
		tmp = lst;
		ft_lstdelone(&lst, del);
		lst = tmp->next;
	}
	*alst = NULL;
}
