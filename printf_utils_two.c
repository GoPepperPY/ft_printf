#include "library.h"

int	pointer_length(unsigned long long pointer)
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

void	print_pointer_two(unsigned long long pointer)
{
	char	character;

	if (pointer >= 16)
	{
		print_pointer_two(pointer / 16);
		print_pointer_two(pointer % 16);
	}
	else
	{
		if (pointer <= 9)
		{
			character = pointer + '0';
			write(1, &character, 1);
		}
		else
		{
			character = pointer - 10 + 'a';
			write(1, &character, 1);
		}
	}
}

int	print_pointer(unsigned long long pointer)
{
	int	length;

	length = 0;
	if (pointer == 0)
		length = length + write(1, "(nil)", 1);
	else
	{
		length = length + write(1, "0x", 2);
		print_pointer_two(pointer);
		length = pointer_length(pointer);
	}
	return (length);
}
