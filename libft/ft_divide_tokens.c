/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:16:20 by afonso            #+#    #+#             */
/*   Updated: 2023/05/22 15:06:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_counter(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '\"' )
		{
			count++;
			while (*s && (*s != '\'' || *s != '\"'))
				s++;
		}
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	dquote_handler(const char **s, char **str, char **dst, int *i)
{
	(*s)++;
	(*str) = (char *)*s;
	while (**s && (**s != '\"'))
		(*s)++;
	dst[*i] = (char *)malloc(*s - *str + 1);
	if (!dst)
		return ;
	ft_strlcpy(dst[(*i)], *str, *s - *str + 1);
	(*i) += 1;
	(*s)++;
	return ;
}

void	nondelimiter_handler(char const **s, char **str, char **dst, int *i)
{
	*str = (char *)*s;
	while (**s && **s != ' ')
		(*s)++;
	dst[*i] = (char *)malloc(*s - *str + 1);
	if (!dst[*i])
		return ;
	ft_strlcpy(dst[(*i)++], *str, *s - *str + 1);
}

char	**ft_divide_tokens(char const *s, char c)
{
	char	**dst;
	char	*str;
	int		i;

	dst = (char **)malloc(sizeof(char *) * (char_counter(s, c) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == '\"')
			dquote_handler(&s, &str, dst, &i);
		else if (*s != c)
			nondelimiter_handler(&s, &str, dst, &i);
		else
			s++;
	}
	dst[i] = NULL;
	return (dst);
}
