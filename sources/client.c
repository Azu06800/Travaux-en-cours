/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:14:39 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/27 10:03:10 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

int	test_pid(pid_t pid)
{
	printf("pid = %d\n",pid);
	if (kill(pid, 0) == 0)
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
