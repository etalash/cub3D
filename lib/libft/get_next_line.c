/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:29:29 by stalash           #+#    #+#             */
/*   Updated: 2025/02/08 19:35:24 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clean_up_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + sizeof(char));
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = ft_lst_last(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] != '\0' && last_node->content[++i] != '\0')
		buf[j++] = last_node->content[i];
	buf[j] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*join_line(t_list *list)
{
	char	*new_list;
	int		len;

	if (list == NULL)
		return (NULL);
	len = len_of_list(list);
	new_list = malloc(len + sizeof(char));
	if (new_list == NULL)
		return (NULL);
	copy_list(list, new_list);
	return (new_list);
}

void	add_to_the_end(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	if (list == NULL)
		return ;
	last_node = ft_lst_last(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->content = buf;
	new_node->next = NULL;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	if (list == NULL)
		return ;
	while (!new_line(*list))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			buf = NULL;
			return ;
		}
		buf[char_read] = '\0';
		add_to_the_end(list, buf);
	}
	return ;
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*str;
	t_list			*temp;

	if (read(fd, &str, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		if (list == NULL)
			return (NULL);
		while (list != NULL)
		{
			temp = (list)->next;
			free((list)->content);
			free(list);
			list = temp;
		}
		return (NULL);
	}
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	str = join_line(list);
	clean_up_list(&list);
	return (str);
}
