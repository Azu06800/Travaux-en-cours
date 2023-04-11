/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:27:10 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/11 15:15:50 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <limits.h>
# include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int main()
{
	int fd;
	int i;
	int BUFFER_SIZE = 7;
	unsigned char *buf;

	fd = open("text.txt", O_RDONLY);
	i = 8;
	while(i--)
	{
		if(buf)
			free(buf);
		buf = calloc(BUFFER_SIZE + 1 , sizeof(char));
		printf("nbyte retourné = %zd\n", read(fd, buf, BUFFER_SIZE));
		printf("Taille(strlen) = %zd\n", ft_strlen((char *)buf));
		printf("buf = %s\n", buf);
		printf("---------\n");
	}
	free(buf);
	close(fd);
	return 0;
}
