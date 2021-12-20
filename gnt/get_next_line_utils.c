/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:41:20 by yel-aziz          #+#    #+#             */
/*   Updated: 2021/12/20 16:02:10 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(char *p)
{
	size_t	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*canca;

	i = -1;
	j = 0;
	if (!s2)
		return (0);
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	canca = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!canca)
		return (NULL);
	while (s1[++i])
		canca[j++] = s1[i];
	i = 0;
	while (s2[i])
		canca[j++] = s2[i++];
	canca[j] = '\0';
	free(s1);
	return (canca);
}
