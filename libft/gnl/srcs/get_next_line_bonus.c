/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:16 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 13:15:30 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

int	read_from_fd(int fd, char *buffer, char **stash)
{
	size_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		if (stash[fd])
			stash[fd] = ft_strjoin_gnl(stash[fd], buffer, bytes_read);
		else
			stash[fd] = ft_strdup_gnl(buffer, NULL, bytes_read);
		if (!stash[fd])
			return (-1);
		return (bytes_read);
	}
	if (bytes_read == 0)
		return (0);
	else
		return (-1);
}

int	ft_realloc(char **stash, int fd, char *new_part)
{
	char	*temp;

	if (*(new_part + 1) != '\0')
	{
		temp = ft_strdup_gnl(new_part + 1, NULL, -1);
		if (!temp)
			return (0);
	}
	else
		temp = NULL;
	free(stash[fd]);
	stash[fd] = temp;
	return (1);
}

char	*construct_line(char *buffer, int fd, char **stash, int bytes_read)
{
	char	*new_part;
	char	*result;

	while (bytes_read > 0 || find_newline(stash[fd]))
	{
		new_part = find_newline(stash[fd]);
		if (new_part)
		{
			result = ft_strdup_gnl(stash[fd], new_part, -1);
			if (!result || !ft_realloc(stash, fd, new_part))
				return (NULL);
			return (result);
		}
		bytes_read = read_from_fd(fd, buffer, stash);
	}
	if (bytes_read == 0)
	{
		if (!stash[fd])
			return (NULL);
		result = ft_strdup_gnl(stash[fd], NULL, -1);
		free(stash[fd]);
		stash[fd] = NULL;
		return (result);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*result;
	static char		*stash[FOPEN_MAX];
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	bytes_read = read_from_fd(fd, buffer, stash);
	result = construct_line(buffer, fd, stash, bytes_read);
	free(buffer);
	return (result);
}
