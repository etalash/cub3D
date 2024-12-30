/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:08:02 by stalash           #+#    #+#             */
/*   Updated: 2024/03/21 12:08:02 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
// #include "libft.h"
// #include <stdlib.h>

// int main()
// {
// 	char *lst1 = ft_lstnew("node 1");
// 	char *lst2 = ft_lstadd_front("node 2");
// 	char *lst3 = ft_lstadd_front("node 3");

// 	printf("the lst is\n");
// 	ft_lstitre()
// }

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	while (lst != NULL)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// }

// void *f(void *str)
// {
// 	printf("%d", (char *)content);
// }
