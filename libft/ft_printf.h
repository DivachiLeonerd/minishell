/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:07:15 by afonso            #+#    #+#             */
/*   Updated: 2022/03/03 13:25:24 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include"libft.h"
# include <stdarg.h>

int			ft_printf(const char *string, ...);
int			print_pointer(void *ptr_x);
int			print_integer(int integer, char format);
int			print_hexa(va_list ap, char format, int counter);
int			print_unsigned_int(unsigned int u);
int			print_string(char *string);
char		*ft_utoa(unsigned int u);

#endif
