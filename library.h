/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:33:40 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/19 17:45:40 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *input, ...);
int		identify_flag(va_list argument, const char type);

int		print_string(char *string);
int		print_decimal_integer(int number);
int		print_decimal_unsigned(unsigned int number);
int		print_hex(unsigned int number, char type);
int		counter_length(unsigned int number);
int		print_pointer(unsigned long long pointer);
void	print_pointer_two(unsigned long long pointer);
int		pointer_length(unsigned long long pointer);

#endif
