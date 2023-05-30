/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:14:44 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/30 20:14:52 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"


void	receive_string(int signal)
{
	
}

int main(int argc, char **argv)
{
	struct sigaction	sa;

	ft_printf("PID is %d.\n",getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &(receive_string);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID is %d.\n",getpid());
	while (1)
		;
	return 0;
}
