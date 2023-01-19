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
		return (write(1, "NULL",1));
	while(string[counter])
	{
		write(1, &string[counter], 1);
		counter++;
	}
	write(1, "\n",1);
	return (counter);
}

int	print_decimal_integer(int number)
{
	char	character;
	int	length;
	int	divider;

	length = counter_length((unsigned int)number, divider);
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
	int	length;
	int	divider;

	divider = 10;
	length = counter_length(number, divider);
	if (number > 9)
	{
		print_decimal_unsigned(number / 10);
		character = number % 10 + '0';
		write(1, &character,1);
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
	char	character;
	int	length;
	int	divider;

	divider = 10;
	length = counter_length(number, divider);
	if (number == 0)
		return(write(1, "0", 1));
	else
	{
		if (number >= 16)
		{
			print_hex((number / 16), type);
			print_hex((number % 16), type);
		}
		else
		{
			if(number <= 9)
			{
				number = number + '0';
				write(1, &number, 1);
			}
			else
			{
				if (type == 'x')
				{
					number = number - 10 + 'a';
	    				write(1, &number, 1);
				}
				if (type == 'X')
				{
					number = number - 10 + 'A';
	    				write(1, &number, 1);
				}
			}		
		}
	}
	return (length - 1);
}

int	counter_length(unsigned int number, int divider)
{
	int	length;

	length = 0;
	if (number > 9)
	{
		while (number > divider)
		{
			number = number / divider;
			length++;
		}
	}
	return (length);
}

int	length_pointer(uintptr_t pointer)
{
	int	length;

	length = 0;
	while (pointer != 0)
	{
		length++;
		pointer = pointer / 16;
	}
	return (length);
}

int	print_pointer(uintptr_t pointer)
{
	int	divider;

	divider = 16;
	if (pointer == 0)
		return (write(1, "(nil)", 5));
	else
	{
		if (pointer >= 16)
		{
			print_pointer(pointer / 16);
			print_pointer(pointer % 16);
		}
		else
			print_hex(pointer, 'x');
	}
	return (length_pointer(pointer) + 2);
}
