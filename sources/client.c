/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:14:39 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/25 18:54:27 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

int	test_pid(pid_t pid)
{
	if (kill(0, pid) == 0)
		return 1;
	else 
		return 0;
}

int main(int argc, char **argv)
{
	if (argc)
		;
	if(test_pid(ft_atoi(argv[1])))
		printf("pid est valide\n");
	else 
		printf("pid est incorrect\n");
	return 0;
}
