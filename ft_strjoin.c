/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:45:20 by ibaines           #+#    #+#             */
/*   Updated: 2022/04/13 10:36:56 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr1;
	int		i;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ptr1 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr1)
		return (NULL);
	while (s1[i])
	{
		ptr1[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr1[i + j] = s2[j];
		j++;
	}
	ptr1[j + i] = '\0';
	return (ptr1);
}
