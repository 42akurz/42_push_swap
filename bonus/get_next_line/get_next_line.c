/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:01:21 by akurz             #+#    #+#             */
/*   Updated: 2021/08/17 13:52:02 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*if_newline(char **save, char *line, int i)
{
	char	*tmp;

	line = ft_substr(*save, 0, i + 1);
	tmp = ft_strdup(&((*save)[i + 1]));
	free(*save);
	*save = tmp;
	if ((*save)[0] == '\0')
	{
		free(*save);
		*save = NULL;
	}
	return (line);
}

static char	*ft_return(char **save, int bytes)
{
	int		i;
	char	*line;

	line = NULL;
	if (bytes == 0 && *save == NULL)
		return (NULL);
	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if ((*save)[i] == '\n')
		line = if_newline(save, line, i);
	else
	{
		line = ft_strdup(*save);
		free(*save);
		*save = NULL;
	}
	return (line);
}

static char	*ft_joinstuff(char *save, char *buff)
{
	char	*temp;

	temp = ft_strjoin(save, buff);
	free(save);
	save = temp;
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buff[1 + 1];
	int			bytes;

	bytes = 1;
	if (fd < 0)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read (fd, buff, 1);
		if (bytes == 0)
			break ;
		if (bytes > 0)
			buff[bytes] = '\0';
		else if (bytes == -1)
			return (NULL);
		if (!save)
			save = ft_strdup(buff);
		else
			save = ft_joinstuff(save, buff);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (ft_return(&save, bytes));
}
