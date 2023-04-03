/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:43:06 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/03 11:09:21 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int main ()
{

	printf("int putchar = %d \n", ft_putchar('c'));

	return 0;
}
