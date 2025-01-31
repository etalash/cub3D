/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:15:12 by stalash           #+#    #+#             */
/*   Updated: 2024/03/21 11:15:12 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_struct *lst, void (*del)(void*))
{
	if (lst != NULL || del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
//function of void (*del)(void*)) is
// void	*del(void *content)
// {
// 	free((char *)content);
// }
