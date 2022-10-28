/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:58:59 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/27 18:51:25 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0 && (unsigned char)c != s[i])
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *) &s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*b;
	int		j;

	if (!s1 || !s2)
		return (0);
	b = malloc((ft_strlen(s1) + 1) + ft_strlen(s2));
	if (!b)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		b[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		b[i] = s2[j];
		i++;
		j++;
	}
	b[i] = '\0';
	return (b);
}
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		s;
	char	*b;

	s = ft_strlen(s1);
	i = 0;
	b = malloc(sizeof(char ) * (s + 1));
	if (!b)
		return (0);
	while (s1[i] != 0)
	{
		b[i] = s1[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*b;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	i = 0;
	if (!s)
		return (0);
	b = malloc(sizeof(char) * (len + 1));
	if (b == 0)
		return (0);
	while (i < len && start < ft_strlen(s))
	{
		b[i] = s[start];
		i++;
		start++;
	}
	b[i] = '\0';
	return (b);
}