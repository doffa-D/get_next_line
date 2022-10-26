/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:25:33 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/26 12:32:17 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_copy(int fd,char buffer,char backup)
{
    int read_line;
    char *tmp;
    read_line = 1;
    while(read_line != 0)
    {
        read_line = read(fd,buffer,BUFFER_SIZE);
    }
}
char *get_next_line(int fd)
{
    char *line;
    static char *backup;

    buffer = (char *)malloc(sizeof(char )* (BUFFER_SIZE + 1));

    line = ft_copy(fd,buffer,backup);
}

int main()
{
    
    int fd = open("file.txt", O_RDWR);
    printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    // printf("%s",get_next_line(fd));
    return 0;
}