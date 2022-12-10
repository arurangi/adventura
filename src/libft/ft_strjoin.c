/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:10:02 by arurangi          #+#    #+#             */
/*   Updated: 2022/12/10 16:05:58 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Combines two strings to create a new one (with memory allocation)
*/

#include "libft.h"

static char	*free_array(char *to_free, char *return_str);

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		length;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (length + 1));
	if (!s3)
		return (0);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (free_array(s1, s3));
}

char	*free_array(char *to_free, char *return_str)
{
	free(to_free);
	return (return_str);
}
