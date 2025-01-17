/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:28:21 by stalash           #+#    #+#             */
/*   Updated: 2024/03/21 10:28:21 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_struct	*ft_lstlast(t_struct *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>

// int main()
// {
// 	t_struct	*node1;
// 	node1 = (t_struct *)malloc(sizeof(t_struct));
// 	node1->content = "node 1";
// 	node1->next = NULL;

// 	t_struct *node2;
// 	node2 = (t_struct *)malloc(sizeof(t_struct));
// 	node2->content = "node 2";
// 	node2->next = NULL;

// 	t_struct *node3;
// 	node3 = (t_struct *)malloc(sizeof(t_struct));
// 	node3->content = "node 2";
// 	node3->next = NULL;

// 	node1->next = node2;
// 	node2->next = node3;

// 	t_struct *last_node;

// 	last_node = ft_lstlast(node1);

// 	if (last_node != NULL)
// 		printf("%s", (char *)last_node->content);
// 	else
// 		printf("can not alocate memory");

// 	free(node1);
// 	free(node2);
// 	free(node3);

// 	return (0);
// }
