/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nide-mel <nide-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:47:17 by nide-mel          #+#    #+#             */
/*   Updated: 2021/09/19 20:47:46 by nide-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	saved_line(int fd, char **line, char **saved)
{
	int			i;
	char		*temp;

	i = 0;
	while (saved[fd][i] != '\n' && saved[fd][i] != '\0')
		i++;
	if (saved[fd][i] == '\n')
	{
		*line = ft_substr(saved[fd], 0, i);
		temp = ft_substr(saved[fd], i + 1, ft_strlen(saved[fd]) - i);
		free(saved[fd]);
		saved[fd] = temp;
		return (1);
	}
	else
	{
		*line = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = 0;
		return (0);
	}
}

static int	ft_return(int fd, char **line, char **saved, int n)
{
	if (n == -1)
		return (-1);
	if (!(n) && saved[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (saved_line(fd, line, saved));
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[100000];
	char		*temp;
	char		buff[BUFFER_SIZE + 1];
	int			n;

	n = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n > 0)
		{
			buff[n] = '\0';
			if (!saved[fd])
				saved[fd] = ft_strdup("");
			temp = ft_strjoin(saved[fd], buff);
			free(saved[fd]);
			saved[fd] = temp;
			if (ft_strchr(saved[fd], '\n'))
				break ;
		}
	}
	return (ft_return(fd, line, saved, n));
}
