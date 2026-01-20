/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maba <maba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:15:20 by stalash           #+#    #+#             */
/*   Updated: 2025/04/07 23:17:04 by maba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_struct
{
	void			*content;
	struct s_struct	*next;
}					t_struct;

extern int			ft_atoi(const char *str);
extern void			ft_bzero(void *s, size_t n);
extern void			*ft_calloc(size_t count, size_t size);
extern int			ft_isalnum(int c);
extern int			ft_isalpha(int c);
extern int			ft_isascii(int c);
extern int			ft_isdigit(int c);
extern int			ft_isprint(int c);
extern char			*ft_itoa(int n);
extern void			*ft_memchr(const void *s, int c, size_t n);
extern int			ft_memcmp(const void *s1, const void *s2, size_t n);
extern void			*ft_memcpy(void *dst, const void *src, size_t n);
extern void			*ft_memmove(void *dst, const void *src, size_t len);
extern void			*ft_memset(void *b, int c, size_t len);
extern void			ft_putchar_fd(char c, int fd);
extern void			ft_putendl_fd(char *s, int fd);
extern void			ft_putnbr_fd(int n, int fd);
extern void			ft_putstr_fd(char *s, int fd);
extern char			**ft_split(char const *s, char c);
extern char			*ft_strchr(const char *s, int c);
extern char			*ft_strdup(const char *s1);
extern void			ft_striteri(char *s, void (*f)(unsigned int, char *));
extern char			*ft_strjoin(char const *s1, char const *s2);
extern size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
extern size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
extern size_t		ft_strlen(const char *s);
extern char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern int			ft_strncmp(const char *s1, const char *s2, size_t n);
extern char			*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
extern char			*ft_strrchr(const char *s, int c);
extern char			*ft_strtrim(char const *s1, char const *set);
extern char			*ft_substr(char const *s, unsigned int start, size_t len);
extern int			ft_tolower(int c);
extern int			ft_toupper(int c);
extern void			ft_lstadd_back(t_struct **lst, t_struct *new);
extern void			ft_lstadd_front(t_struct **lst, t_struct *new);
extern void			ft_lstclear(t_struct **lst, void (*del)(void *));
extern void			ft_lstdelone(t_struct *lst, void (*del)(void *));
extern void			ft_lstiter(t_struct *lst, void (*f)(void *));
extern t_struct		*ft_lstlast(t_struct *lst);
extern t_struct		*ft_lstmap(t_struct *lst, void *(*f)(void *),
						void (*del)(void *));
extern t_struct		*ft_lstnew(void *content);
extern int			ft_lstsize(t_struct *lst);
extern bool			ft_is_whitespace(char c);
extern char			*ft_strndup(const char *str, size_t n);
extern int			ft_isnumber(char *str);

//******************get next line******************** */

int					new_line(t_list *list);
t_list				*ft_lst_last(t_list *list);
char				*join_line(t_list *list);
void				copy_list(t_list *list, char *ptr);
int					len_of_list(t_list *list);
char				*get_next_line(int fd);
void				dealloc(t_list **list, t_list *clean_node, char *buffer);
void				create_list(t_list **list, int fd);
void				clean_up_list(t_list **list);

#endif
