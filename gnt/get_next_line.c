/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:24:45 by yel-aziz          #+#    #+#             */
/*   Updated: 2021/12/20 16:01:57 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_change_text(char *text)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	j = ft_strlen(text);
	if (text[i] == '\0')
	{
		free(text);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!s)
		return (NULL);
	j = 0;
	while (text[i++] != '\0')
	{
		s[j++] = text[i];
	}
	s[j] = '\0';
	free(text);
	return (s);
}

char	*ft_just_line(char *text)
{
	size_t	i;
	size_t	j;
	char	*b;

	j = 0;
	i = 0;
	if (!*text)
		return (0);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	b = (char *)malloc(sizeof(char) * (i + 1));
	if (!b)
		return (NULL);
	while (j < i)
	{
		b[j] = text[j];
		j++;
	}
	b[j] = '\0';
	return (b);
}

char	*ft_read(char *text, int fd)
{
	char	*p;
	int		n;

	n = 1;
	p = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!p)
		return (NULL);
	while (!(ft_strchr(text, '\n')) && n != 0)
	{
		n = read(fd, p, BUFFER_SIZE);
		if (n == -1)
		{
			free (p);
			return (NULL);
		}
		p[n] = '\0';
			text = ft_strjoin(text, p);
	}
	free (p);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = ft_read(text, fd);
	if (!text)
		return (NULL);
	line = ft_just_line(text);
	text = ft_change_text(text);
	return (line);
}
