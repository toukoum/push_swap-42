/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:20 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 13:16:14 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_strdup_gnl(char *s, char *new_part, int size);
char	*find_newline(const char *s);
char	*ft_strjoin_gnl(char *s1, char const *s2, size_t bytes_read);
int		read_from_fd(int fd, char *buffer, char **stash);
int		ft_realloc(char **stash, int fd, char *new_part);
char	*get_next_line(int fd);
char	*construct_line(char *buffer, int fd, char **stash, int bytes_read);

#endif