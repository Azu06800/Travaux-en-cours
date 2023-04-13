/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:07:19 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/13 14:59:48 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_and_stash(int fd, unsigned char *stash)
{
	unsigned char	*buf;
	unsigned char	*tmp;
	size_t			read_size;

	buf = ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
	read_size = read(fd, buf, BUFFER_SIZE);
	if(read_size < 1)
	{
		if (read_size == 0)
			free(stash[fd]);
		free(buf);
		return (read_size);
	}
	tmp = ft_strdup(stash[fd]);
	if (stash[fd])
		free(stash[fd]);
	stash[fd]= ft_calloc(ft_strlen(tmp) + ft_strlen(buf) + 1, sizeof(char));
	stash[fd]= ft_strcat(stash[fd], tmp);
	stash[fd]= ft_strcat(stash[fd], buf);
	free(tmp);
	return (read_size);
}
unsigned char *extract_line(int fd, unsigned char **stash)
{
	size_t				i;
	size_t				read_size;
	unsigned char 		*line;

	i = 0;
	read_size = read_and_stash(fd, stash[fd]);
	if(read_size < 1)
		return(NULL);
	while(stash[fd][i] != '\n')
	{
		i++;
	}
	return(line);
}

char	*get_next_line(int fd)
{
	static unsigned char 	*stash[OPEN_MAX];
	unsigned char			*line;

	if(fd < 0)
		return (NULL);
	line = extract_line(fd, stash[fd]);
	//1  read and stash
	//2  extract from stash
	//3  clean stash
	return (line);
}

int main()
{
	char *line;

	line = get_next_line();
	free(line);
}
