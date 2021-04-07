/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:20:55 by egrazina          #+#    #+#             */
/*   Updated: 2021/04/06 18:32:50 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	length;

	if (!src)
		return (0);
	length = ft_strlen(src);
	if (!dst || !size)
		return (length);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (length);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	readfile(int fd, char **arr, char *buffer)
{
	ssize_t	rb;

	rb = read(fd, buffer, BUFFER_SIZE);
	if (rb < 0)
		return (-1);
	if (rb == 0)
		return (0);
	buffer[rb] = '\0';
	if (arr[fd] == NULL)
		arr[fd] = ft_strdup(buffer);
	else
		arr[fd] = ft_strjoin(arr[fd], buffer);
	if (arr[fd] == NULL)
		return (-1);
	return (1);
}

int	update_line(int fd, char **arr, char **line)
{
	char	*index;
	char	*tmp;

	index = ft_strchr(arr[fd], '\n');
	if (index)
	{
		*line = ft_substr(arr[fd], 0, index - arr[fd]);
		tmp = ft_substr(index, 1, ft_strlen(arr[fd]) - (index - arr[fd] + 1));
		free(arr[fd]);
		arr[fd] = tmp;
		return (1);
	}
	else
	{
		if (arr[fd])
		{
			*line = ft_strdup(arr[fd]);
			free(arr[fd]);
			arr[fd] = NULL;
		}
		else
			*line = ft_strdup("\0");
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*arr[OPEN_MAX];
	int			status;
	char		*buffer;

	status = 1;
	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (-1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (!ft_strchr(arr[fd], '\n') && status > 0)
		status = readfile(fd, arr, buffer);
	free(buffer);
	if (status == -1)
		return (-1);
	else
		status = update_line(fd, arr, line);
	return (status);
}
