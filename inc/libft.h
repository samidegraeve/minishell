/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:     :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:51:04 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/04 18:34:07 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_node
{
	char			*content;
	int				flag;
	int				bultin;
	char			*cmd;
	char			*in;
	char			*out;
	int				in_fd;
	int				out_fd;
	char			**full_cmd;
	int				heredoc;
	int				append;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_env
{
	char			*content;
	char			*attribut;
	int				flag;
	struct s_env	*next;
}				t_env;

typedef struct s_stack
{
	t_node	*up;
	t_node	*low;
}				t_stack;

void		ft_free_all(char **str);
char		*ft_strcreate(char *line, int start, int end);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *restrict dst, \
			const char *restrict src, size_t dstsize);
size_t		ft_strlcat(char *restrict dst, \
			const char *restrict src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
long long	ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
long long	ft_atoi2(const char *str1);

//LISTE CHAINER
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);

//DOUBLE LISTE CHAINER
t_node		*dl_lstnew(char *line, int start, int end);
void		dl_lstadd_front(t_stack *a, char *line, int start, int end);
void		dl_lstdelfront(t_stack *a);
void		dl_lstdelback(t_stack *a);
void		dl_lstadd_back(t_stack *a, char *line, int start, int end);
void		dl_lstdelnode(t_node *node, t_stack *stack);
int			dl_lstsize(t_stack *stack);

#endif