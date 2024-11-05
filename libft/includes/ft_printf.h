/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:36:48 by nusamank          #+#    #+#             */
/*   Updated: 2024/03/11 18:51:43 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <inttypes.h>
# include <stdarg.h>
# include <unistd.h> 

int	ft_printf(const char *format, ...);
int	print_format(const char *specifier, va_list args);
int	print_c(int c);
int	print_str(char *s);
int	print_ptr(void *ptr);
int	print_int(long n);
int	print_hex(unsigned int n, char x);

#endif