/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:57:51 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/18 16:09:32 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < n)
		i++;
	while (src[j] && i + 1 < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < n)
		dst[i] = '\0';
	while (src[j])
	{
		j++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*join;
	int		len;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof(char) * len);
	if (join == NULL)
		return (NULL);
	join[0] = '\0';
	ft_strlcat(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, s2, len + 1);
	free(s1);
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
