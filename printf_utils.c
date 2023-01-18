/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:13 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/18 17:38:39 by goda-sil         ###   ########.fr       */
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
	char		character;
	static int	length;

	length = 0;
	if (number == -2147483648)
		return(write(1, "2147483648", 11));
	else if (number < 0)
	{
	    write(1, "-", 1);
	    print_decimal_integer(-number);
	}
	else if (number > 9)
	{
		print_decimal_integer(number / 10);
		character = number % 10 + '0';
		length++;
		write(1, &character, 1);
	}
	else if (number <= 9)
	{
		character = number + '0';
		length++;
		write(1, &character, 1);
	}
	return (length);
}
