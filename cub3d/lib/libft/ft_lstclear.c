/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:41:19 by stalash           #+#    #+#             */
/*   Updated: 2024/03/21 11:41:19 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_struct **lst, void (*del)(void *))
{
	t_struct	*current_lst;
	t_struct	*next_lst;

	if (!lst || !*lst || !del)
		return ;
	current_lst = *lst;
	while (current_lst)
	{
		next_lst = current_lst->next;
		ft_lstdelone(current_lst, del);
		current_lst = next_lst;
	}
	*lst = NULL;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"

// void del(void *content)
// {
// 	free(content);
// }

// void ft_lstclear(t_struct **lst, void (*del)(void *))
// {
// 	t_struct *current = *lst;
// 	t_struct *next;

// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		del(current->content);
// 		free(current);
// 		current = next;
// 	}
// 	*lst = NULL;
// }

// int	main()
// {
// 	t_struct *head = ft_lstnew("Node 1");
// 	ft_lstadd_front(&head, ft_lstnew("Node 2"));
// 	ft_lstadd_front(&head, ft_lstnew("Node 3"));
// 	printf("Original list:\n");
// 	t_struct *current = head;
// 	while (current != NULL)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	ft_lstclear(&head, del);

// 	printf("\nList after clearing:\n");
// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	return (0);
// }
