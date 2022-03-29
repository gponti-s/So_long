/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponti-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:56:51 by gponti-s          #+#    #+#             */
/*   Updated: 2021/03/26 11:56:53 by gponti-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((n == 0) || (dst == src))
		return (dst);
	while (i < n)
	{
		*(char *)dst++ = *(char *)src++;
		i++;
	}
	return (dst - n);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = malloc(((ft_strlen(s1) + 1) * sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ptr[ft_strlen(s1)] = '\0';
	return (ptr);
}

void	ft_strdel(char **ptr)
{
	if ((*ptr) != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static int	get_line(char **line, char **ptr)
{
	char	*temp;
	int		len;

	len = 0;
	while ((*ptr)[len] != '\n' && (*ptr)[len] != '\0')
		len++;
	if ((*ptr)[len] == '\n')
	{
		*line = ft_substr((*ptr), 0, len);
		temp = ft_strdup(&((*ptr)[len + 1]));
		free(*ptr);
		*ptr = temp;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*ptr[FD_SIZE];
	char		r[BUFFER_SIZE + 1];
	size_t		ret_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || line == NULL)
		return (-1);
	ret_read = 1;
	if (ptr[fd] && ft_strrchr(ptr[fd], '\n'))
		return (get_line(line, &ptr[fd]));
	while (ret_read > 0)
	{
		ret_read = read(fd, r, BUFFER_SIZE);
		r[ret_read] = 0;
		ptr[fd] = ft_join(ptr[fd], r);
		if (ft_strrchr(r, '\n'))
			return (get_line(line, &ptr[fd]));
	}
	if (ptr[fd])
	{
		*line = ft_strdup(ptr[fd]);
		ft_strdel(&(ptr[fd]));
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
