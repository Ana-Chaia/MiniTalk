/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:05:37 by anacaro5          #+#    #+#             */
/*   Updated: 2024/02/05 11:57:21 by anacaro5         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*result;
	size_t	i;

	s_len = ft_strlen(s);
	result = (char *)malloc((s_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	len_s;
	size_t	i;

	len_s = 0;
	if (!s)
		return (NULL);
	while (s[len_s] != '\0')
		len_s++;
	if (len_s < start)
		return (ft_strdup(""));
	if (len >= len_s)
		new = (char *)malloc (len_s - start + 1);
	else
		new = (char *)malloc (len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (len-- > 0 && s[start] != '\0')
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_countncut(char *line, char **rest)
{
	size_t	a;
	char	*cropped;
	char	*first;

	a = 0;
	while (line[a] != '\n' && line[a] != '\0')
		a++;
	if (line[a] != '\0')
	{
		cropped = malloc(ft_strlen(&line[a + 1]) + 1);
		ft_strlcpy(cropped, &line[a + 1], ft_strlen(&line[a + 1]) + 1);
		*rest = cropped;
	}
	else
		*rest = NULL;
	first = ft_substr(line, 0, a + 1);
	free(line);
	return (first);
}

char	*ft_readtxt(int fd, char *line, char *rest)
{
	char		*temp;
	ssize_t		rbytes;

	rbytes = 1;
	while (ft_strchr(rest, '\n') == NULL && rbytes != 0)
	{
		rbytes = read (fd, line, BUFFER_SIZE);
		if (rbytes < 0)
		{
			free(rest);
			return (NULL);
		}
		if (ft_strlen(line) == 0 && rest == NULL)
		{
			return (NULL);
		}
		line[rbytes] = '\0';
		temp = ft_strjoin(rest, line);
		free(rest);
		rest = temp;
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[1024];
	char		*first;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	rest[fd] = ft_readtxt(fd, line, rest[fd]);
	free(line);
	line = rest[fd];
	rest[fd] = NULL;
	if (line == NULL)
		return (NULL);
	first = ft_countncut(line, &rest[fd]);
	return (first);
}
