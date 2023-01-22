/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:13 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/19 17:45:14 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	print_string(char *string)
{
	int	counter;

	counter = 0;
	if (string == NULL)
		return (write(1, "NULL", 1));
	while (string[counter])
	{
		write(1, &string[counter], 1);
		counter++;
	}
	write(1, "\n", 1);
	return (counter);
}

int	print_decimal_integer(int number)
{
	char	character;
	int		length;

	length = counter_length((unsigned int)number);
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (number < 0)
	{
		write(1, "-", 1);
		print_decimal_integer(-number);
	}
	else if (number > 9)
	{
		print_decimal_integer(number / 10);
		character = number % 10 + '0';
		write(1, &character, 1);
	}
	else if (number <= 9)
	{
		character = number + '0';
		write(1, &character, 1);
	}
	return (length + 1);
}

int	print_decimal_unsigned(unsigned int number)
{
	char	character;
	int		length;

	length = counter_length(number);
	if (number > 9)
	{
		print_decimal_unsigned(number / 10);
		character = number % 10 + '0';
		write(1, &character, 1);
	}
	else if (number <= 9)
	{
		character = number + '0';
		write(1, &character, 1);
	}
	return (length + 1);
}

int	print_hex(unsigned int number, char type)
{
	if (number == 0)
		return (write(1, "0", 1));
	if (number >= 16)
	{
		print_hex((number / 16), type);
		print_hex((number % 16), type);
	}
	else
	{
		if (number <= 9)
		{
			number = number + '0';
			write(1, &number, 1);
		}
		else
		{
			if (type == 'x')
				number = number - 10 + 'a';
			if (type == 'X')
				number = number - 10 + 'A';
			write(1, &number, 1);
		}		
	}
	return (counter_length(number) + 1);
}

int	counter_length(unsigned int number)
{
	int	length;

	length = 0;
	if (number >= 9)
	{
		while (number > 10)
		{
			number = number / 10;
			length++;
		}
	}
	return (length);
}
