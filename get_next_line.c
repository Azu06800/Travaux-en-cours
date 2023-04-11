/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:07:19 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/11 15:15:45 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_and_stash(int fd, unsigned char *stash)
{
	unsigned char	*buf;
	unsigned char	*tmp;

	buf = ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
	if(read(fd, buf, BUFFER_SIZE) < 1)
	{	
		if (read (fd, buf, BUFFER_SIZE) == 0)
			free(stash[fd]);
		free(buf);
		return (0);
	}
	tmp = ft_strdup(stash[fd]);
	if (stash[fd])
		free(stash[fd]);
	stash[fd]= ft_calloc(ft_strlen(tmp) + ft_strlen(buf) + 1, sizeof(char));
	stash[fd]= ft_strcat(stash[fd], tmp);
	stash[fd]= ft_strcat(stash[fd], buf);
	free(tmp);
	return (1);
}
unsigned char *extract_line(int fd, unsigned char **stash)
{
	int				i;
	unsigned char 	*line;

	i = 0;
	if(!read_and_stash(fd, stash[fd]))
		return(NULL);
	while(stash[fd][i] != '\n')
	{
		if(i <= ft_strlen(stash[fd]))
		{
			if (stash[fd][i] == '\0')
				return (stash[fd]);
		}
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
