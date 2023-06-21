/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:27:20 by atereso-          #+#    #+#             */
/*   Updated: 2023/06/21 14:47:10 by buny             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int	ft_strncmp(const char *s1, const char *s2, size_t n)
//{
//	while (n > 0 && *s1 && *s2)
//	{
//		if (*s1 != *s2)
//			return ((unsigned char)*s1 - *s2);
//		if (!(*s1) || !(*s2))
//			return (0);
//		s1++;
//		s2++;
//		n--;
//	}
//	return (0);
//}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (*str1 && *str2)
	{
		while (n--)
		{
			if (*str1 != *str2)
				return (*str1 - *str2);
			if (!(*str1) || !(*str2))
				return (0);
			str1++;
			str2++;
		}
	}
	return (0);
}
