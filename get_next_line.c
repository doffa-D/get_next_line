/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:53:48 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/28 16:18:22 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line <= 0)
			break;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}
char *backup_extractor(char *line)
{
	size_t i;
	char *backup;
	i = 0;
	while(line[i] != '\n' && line[i] != '\0')
		i++;
	if(line[i] == 0 || line[1] == 0)
		return 0;
	backup = ft_substr(line,i + 1,ft_strlen(line) - i);
	if(*backup == 0)
	{
		free(backup);
		return 0;
	}
	line[i + 1] = '\0';
	return backup;
}

char *get_next_line(int fd)
{
	char *line;
	char *buffer;
	static char *backup;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return 0;
	buffer = (char *)malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if(!buffer)
		return 0;
	line = ft_copy(fd,buffer,backup);
	free(buffer);
	buffer = 0;
	if(!line)
		return 0;
	backup = backup_extractor(line);
	return line;
}


// int main()
// {
    
//     int fd = open("file.txt", O_RDWR);
//     printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
    
//     // printf("%s\n",get_next_line(fd));
//     return 0;
// }
