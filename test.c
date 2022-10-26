/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:09:42 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/25 13:01:21 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




int ft_strchr(char *str)
{
    int i;
    i = 0;
  
    while(str[i] != '\n')
        i++;
    return i;
}

char *get_next_line(int fd)
{
    static char *str;
    char *len;
    char buff[BUFFER_SIZE];
    int i;
    int j;
    int a;
    int count;
    count = 0;
    a = 0;
    j = 0;
    i = 0;
    
    read(fd, buff,BUFFER_SIZE);
    
    if(!str)
    {
        a = ft_strchr(buff);
        len = malloc(a * (sizeof(char)));
        
        while(buff[i] != '\n')
        {
            len[i] = buff[i];
            i++;
        }
        str = malloc(BUFFER_SIZE - i);
        i++;
        while(i < BUFFER_SIZE)
        {
            str[j ] = buff[i];
            j++;
            i++;
        }
        str[j] = 0;
    }
    else
    {
        a = ft_strchr(buff);
        if(str[i] != 0)
            count = ft_strchr(&str[count]);
        len = malloc(a + 1 + count * (sizeof(char)));
        i = 0;
        while(str[i] != '\n' && str[i] != 0)
        {
          len[i] = str[i];
          i++;
        }
        a = 0;
        while(buff[a] != '\n')
        {
          len[i] = buff[j];
          i++;
          j++;
          a++;
        }
        len[i] = 0;
        i = 0;
        while(str[i])
        {
          str[i] = 0;
          i++;
        }
    }
    // printf("len:# %s #\n",len);
    // printf("static:# %s #",str);

    return len;
}

int main()
{
    
    int fd = open("file.txt", O_RDWR);
    printf("%s\n",get_next_line(fd));
    printf("%s\n",get_next_line(fd));
    printf("%s\n",get_next_line(fd));
    return 0;
}