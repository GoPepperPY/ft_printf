/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:00:06 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/19 17:27:58 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	identify_flag(va_list	argument, const char type)
{
	int	length;
	int	temporary;

	length = 0;
	if (type == 'c')
	{
		temporary = va_arg(argument, int);
		return (write(1, &temporary, 1));	
	}
	else if (type == 's')
		length = length + print_string(va_arg(argument, char *));
	else if (type == 'd' || type == 'i')
		length = length + print_decimal_integer(va_arg(argument, int));
	else if (type == 'u')
		length = length + print_decimal_unsigned(va_arg(argument, unsigned int));
	else if (type == 'x' || type == 'X')
		length = length + print_hex(va_arg(argument, unsigned int), type);
	else if (type == 'p')
	{
		write(1, "0x", 2);
		length = length + print_pointer(va_arg(argument, unsigned long long));
	}
	return (length);
}

int	ft_printf(const char *input, ...)
{
	int		counter;
	int		bytes;
	va_list		argument;

	counter = 0;
	bytes = 0;
	va_start(argument, input);
	while (input[counter])
	{
		if (input[counter] == '%')
		{
			bytes = bytes + identify_flag(argument, input[counter + 1]);
			counter++;
		}
		else
			bytes = bytes + write(1, &input[counter], 1);
		counter++;
	}
	va_end(argument);
	return (bytes);
}
