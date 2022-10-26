/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:20:57 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/26 12:25:27 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>
#include "get_next_line.h"
#include<string.h>
char *ft_copy(int fd,char *buffer,char *backup)
{
    int read_line;
    int k;
    char *temp;

    read_line = 1;
    while(read_line != 0)
    {
        read_line = read(fd, buffer, BUFFER_SIZE);

        if(read_line == -1)
            return 0;
        else if(buffer == 0)
            return 0;
        else if(read_line == 0)
            break;
        buffer[read_line] = '\0';
        if(backup == 0)
            backup = ft_strdup("");
        temp = backup;
        backup = ft_strjoin(temp,buffer);
        free(temp);
        temp = NULL;
        k=gnt_strchr(buffer, '\n');
        if(k!=-1)
            break ;

    }
    return (backup);
}
char *backup_extarct(char *line)
{
    size_t i;
    size_t j;
    i = 0;
    char *backup;
    while(line[i] != '\n' && line[i] != '\0')
        i++;
    j = ft_strlen(line) - i;

    backup = ft_substr(line, i+1 ,j);
    backup[j] = '\0';
    return backup;
    
}
char *get_next_line(int fd)
{
    if(read(fd, 0, 0)<0)
        return 0;
    char *line;
    char *es;
    char *buffer;
    int k;
    static char *backup;
    buffer = (char *)malloc(sizeof(char ) * (BUFFER_SIZE + 1));

    line = ft_copy(fd,buffer,backup);
    free(buffer);
    buffer = 0;
    backup = backup_extarct(line);
    k=gnt_strchr(line, '\n');
    if(k==-1)
        return line;
    es =ft_substr(line,0,k+1);
    free(line);
    return es;
}

// int main()
// {
    
//     int fd = open("file.txt", O_RDWR);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
    
//     // printf("%s\n",get_next_line(fd));
//     return 0;
// }
