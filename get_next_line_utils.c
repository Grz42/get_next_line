/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrazina <egrazina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:45:12 by egrazina          #+#    #+#             */
/*   Updated: 2021/04/06 18:33:10 by egrazina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*newstr;
	size_t	l;

	l = ft_strlen(s);
	newstr = malloc(sizeof(char) * l + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s, l + 1);
	return (newstr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub_str;

	if (!s)
		return (NULL);
	sub_str = malloc(sizeof(char) * len + 1);
	if (!sub_str)
		return (NULL);
	if (start < ft_strlen(s))
	{
		ft_strlcpy(sub_str, &s[start], len + 1);
		return (sub_str);
	}
	else
		sub_str[0] = '\0';
	return (sub_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*arr;

	if (!s1 && !s2)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	arr = malloc(sizeof(char) * (l1 + l2) + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1, l1 + 1);
	ft_strlcpy(&arr[l1], s2, l2 + 1);
	free(s1);
	return (arr);
}
