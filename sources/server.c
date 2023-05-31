/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:14:44 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/31 20:50:35 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>


void* ft_realloc(void* ptr, size_t size)
{
	void* new_ptr;
	
    if (ptr == NULL) 
        return (malloc(size));
	else 
	{
    	new_ptr = malloc(size);
        if (new_ptr == NULL) 
            return ptr;
        ft_memcpy(new_ptr, ptr, size);
        free(ptr);
        return (new_ptr);
    }
}

void	receive_string(int signum)
{
	static char		*string;
	static char		c;
	static int		byte;
	static int		i;
	
	if(signum == SIGUSR1)
		c |= 1 << byte;
	if (byte++ == 7 && c != '\0')
	{
		string = ft_realloc(string, ft_strlen(string + 2));
		string[i++] = c;
		c = 0;
		byte = 0;
	}
	else if (c == '\0')
	{
		string[i] = '\0';
		printf("%s",string);
		free(string);
		string = NULL;
		i = 0;
		byte = 0;
	}
	return ;
}

int main()
{
	struct sigaction	sa;

	ft_printf("PID is %d.\n",getpid());
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = receive_string;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return 0;
}
