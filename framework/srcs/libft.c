/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:33:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 21:44:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(len * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (1);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	if (src_len == 0)
		return (NULL);
	new = malloc((src_len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
