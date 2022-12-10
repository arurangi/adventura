/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:43:09 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/10 09:38:28 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Breaks up a text file {fd}
 * into an {array} of substrings
 * based on a seperator character {ch}
 * 
 * Returns array of strings
 */

// split, strjoin, malloc, read, free

#include "libft.h"

static char	*read_and_save(int fd);

char	**ft_split_fd(char *filepath, char seperator)
{
	char	*extracted_text;
	char	**matrix;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0 || fd > FOPEN_MAX || !seperator)
	{
		ft_printf("Error: couldn't open file or no seperator");
		return (NULL);
	}
	extracted_text = read_and_save(fd);
	if (!extracted_text)
	{
		close(fd);
		free(extracted_text);
		return (NULL);
	}
	close(fd);
	matrix = ft_split(extracted_text, seperator);
	free(extracted_text);
	return (matrix);
}

// Reads a file and returns its content
static char	*read_and_save(int fd)
{
	char		buffer[5 + 1];
	char		*tmp;
	int			bytes_read;

	tmp = malloc(sizeof(char) * 1);
	if (!tmp)
		return (NULL);
	tmp[0] = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 5);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	return (tmp);
}
