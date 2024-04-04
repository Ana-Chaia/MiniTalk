/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:32 by anacaro5          #+#    #+#             */
/*   Updated: 2024/03/12 16:29:26 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Libraries
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// for ft_printf
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

//Funtions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int chr);
char	*ft_strrchr(const char *str, int chr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *ptr, int value, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *strn);
void	*ft_calloc(size_t n_elem, size_t size_bytes);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

//Functions (ex-Bonus Part)
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del) (void *));
void	ft_lstiter(t_list *lst, void (*f) (void *));
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)(void *));

//Post Functions

//for get_next_line_bonus
char	*get_next_line(int fd);
void	*ft_calloc(size_t n_elem, size_t size_bytes);
// char	*ft_strchr(const char *str, int chr);
// char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
// size_t	ft_strlen(const char *str);
char	*ft_countncut(char *line, char **rest);
char	*ft_readtxt(int fd, char *line, char *rest);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

//for ft_printf
int		ft_put_str(char *str);
int		ft_put_char(char c);
int		ft_put_nbr(int n);
int		ft_put_unsig(unsigned int n);
int		ft_put_hexa(unsigned int n, char especifier);
int		ft_put_pointer(unsigned long n);
int		ft_print_pref(unsigned long n);
int		ft_check_n_print(const char *str, int *idx, va_list ap);
int		ft_printf(const char *format, ...);

#endif
