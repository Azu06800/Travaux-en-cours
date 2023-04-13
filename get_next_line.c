/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:07:19 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/13 19:17:33 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_and_stash(int fd, char **stash)
{
	char	*buf;
	char	*tmp;
	size_t			read_size;

	buf = ft_calloc(BUFFER_SIZE + 1 , sizeof(char));
	read_size = read(fd, buf, BUFFER_SIZE);
	if(read_size < 1)
	{
		if (read_size == 0)
			free(*stash);
		free(buf);
		return (read_size);
	}
	tmp = ft_strdup(*stash);
	if (*stash)
		free(*stash);
	*stash = ft_calloc(ft_strlen(tmp) + ft_strlen(buf) + 1, sizeof(char));
	*stash = ft_strcat(*stash, tmp);
	*stash = ft_strcat(*stash, buf);
	free(tmp);
	free(buf);
	return (read_size);
}

char *copy_and_clean(char *stash, size_t i)
{
	char	*line;
	char	*tmp;

	line = ft_calloc(i + 1, sizeof(char));
	tmp = ft_strdup(stash + (i + 1));
	ft_strlcpy(line, stash, i);
	free(stash);
	stash = ft_strdup(tmp);
	free(tmp);
	return (line);
}

char *extract_line(int fd, char *stash)
{
	size_t				i;
	size_t				read_size;
	char		 		*line;

	i = 0;
	read_size = -1;
	read_size += read_and_stash(fd, &stash);
	if(read_size < 0)
		return(NULL);
	while(stash[i] != '\n' && stash[i] != '\0')
	{
		if(i == read_size)
			read_size += read_and_stash(fd, &stash);
		else if(i < read_size)
			i++;
	}
	line = copy_and_clean(stash, i);
	return(line);
}

char	*get_next_line(int fd)
{
	static char 	*stash[OPEN_MAX];
	char			*line;

	if(fd < 0 || BUFFER_SIZE < 1)
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
	int fd;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	free(line);
	//system("leaks a.out");
	return (0);
}
