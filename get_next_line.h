/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:57:45 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/18 15:26:22 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

//get_next_line.c
char	*get_next_line(int fd);

//get_next_line_utils.c
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
int		find_new_line(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *s);

#endif