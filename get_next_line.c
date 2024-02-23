/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:52:54 by sessarhi          #+#    #+#             */
/*   Updated: 2024/02/23 18:16:59 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*my_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (newstr);
}

char	*ft_backup(char **str, int newline)
{
	char	*backup;
	int		len;

	len = ft_strlen(*str);
	backup = ft_substr(*str, newline, len - newline);
	free(*str);
	*str = NULL;
	return (backup);
}

char	*haha1(char **str, int i)
{
	char	*s;

	s = ft_substr(*str, 0, i + 1);
	*str = ft_backup(str, i + 1);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;
	int			newline;
	int			rd;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd >= 0)
	{
		buff[rd] = '\0';
		if (!str[0] && !rd)
			break ;
		str = my_strjoin(str, buff);
		newline = ft_strchr(str, '\n');
		if (newline != -42)
			return (free(buff), haha1(&str, newline));
		else if (!rd)
			return (free(buff), ft_backup(&str, 0));
		rd = read(fd, buff, BUFFER_SIZE);
	}
	return (free(str), free(buff), str = NULL, NULL);
}
