/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:51:49 by goda-sil          #+#    #+#             */
/*   Updated: 2023/01/19 17:39:01 by goda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"


int main(void)
{
    	void *string = "ola";
	int counter = 0;
	counter = ft_printf("%p", string);
	printf("\n%d\n", counter);
	printf("%p", string);
	return (0);
}
