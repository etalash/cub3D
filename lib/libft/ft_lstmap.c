/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:30:42 by stalash           #+#    #+#             */
/*   Updated: 2024/03/21 12:30:42 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_struct	*ft_lstmap(t_struct *lst, void *(*f)(void *), void (*del)(void *))
{
	t_struct	*new_lst;
	t_struct	*new_node;
	t_struct	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		temp = (*f)(lst->content);
		new_node = ft_lstnew(temp);
		if (!new_node)
		{
			del(temp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
