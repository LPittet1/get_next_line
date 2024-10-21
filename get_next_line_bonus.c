/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:38:03 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/21 14:39:29 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*read_line(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

static	char	*extract_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	line = ft_substr(s, 0, i + 1);
	return (line);
}

static	char	*refresh_stash(char *s)
{
	int		i;
	char	*stash;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (s)
		stash = ft_substr(s, i + 1, ft_strlen(s));
	else
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	free(s);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_line(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = refresh_stash(stash[fd]);
	if (line == NULL)
		free(stash[fd]);
	return (line);
}
