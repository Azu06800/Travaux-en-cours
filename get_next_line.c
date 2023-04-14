/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:07:19 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/14 19:35:30 by nihamdan         ###   ########.fr       */
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
	printf("read_size = %zu\n", read_size);//tmp
	if(read_size <= 0)
	{
		if (read_size == 0)
		{
			printf("adresse stash= %p\n", *stash);//tmp
			free(*stash);
		}
		free(buf);
		return (read_size);
	}
	tmp = ft_strdup(*stash);
	if (*stash)
		free(*stash);
	printf("tmp RnS= %s\n", tmp);//tmp
	printf("buf RnS= %s\n", buf);//tmp
	*stash = ft_calloc(ft_strlen(tmp) + ft_strlen(buf) + 1, sizeof(char));
	*stash = ft_strcat(*stash, tmp);
	*stash = ft_strcat(*stash, buf);
	printf("stash RnS = %s\n", *stash);//tmp
	free(tmp);
	free(buf);
	return (read_size);
}

char *copy_and_clean(char **stash, size_t i, size_t read_size)
{
	char	*line;
	char	*tmp;

	line = ft_calloc(i + 2, sizeof(char));
	tmp = ft_strdup(*stash + (i + 1));
	ft_strlcpy(line, *stash, i + 1);
	free(*stash);
	printf("tmp du copy apres free stash = %s\n", tmp);
	printf("stash du copy apres free = %s\n",*stash);// tmp
	*stash = ft_strdup(tmp);
	if(!read_size)
		**stash = '\0';
	printf("stash du copy = %s\n",*stash);// tmp
	free(tmp);
	return (line);
}

char *extract_line(int fd, char **stash)
{
	size_t				i;
	size_t				read_size;
	size_t				read_max;
	char		 		*line;

	i = 0;
	read_max = 0;
	if (*stash)
	{
		read_max = ft_strlen(*stash);
		printf("read max = %zu\n",read_max);
	}
	while((*stash)[i] != '\n')
	{
		if(i < read_max)
			i++;
		if(i == read_max)
		{
			read_size = read_and_stash(fd, stash);
			printf("read size = %zu\n",read_size);
			if(read_size <= 0)
				return(NULL);
			read_max += read_size;
		}
	}
	printf("stash extract= %s\n", *stash);//tmp
	line = copy_and_clean(stash, i, read_size);
	return(line);
}

char	*get_next_line(int fd)
{
	static char 	*stash[OPEN_MAX];
	char			*line;

	if(fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if(!stash[fd])
		stash[fd] = ft_calloc(1, 1);
	printf("stash gnl = %s\n", stash[fd]);//tmp
	line = extract_line(fd, &(stash[fd]));
	printf("line gnl = %s\n", stash[fd]);//tmp
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
	printf("VRAIE SORTIE 1 = %s", line);
	line = get_next_line(fd);
	printf("VRAIE SORTIE 2 = %s", line);
	line = get_next_line(fd);
	printf("VRAIE SORTIE 3 = %s", line);
	close(fd);
	free(line);
	//system("leaks a.out");
	return (0);
}
