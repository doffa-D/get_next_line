/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:36:02 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/27 18:52:17 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h> 
#include <stdio.h>
#include<unistd.h> 
#include <string.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
#endif
#ifndef GET_NEXT_LIEN_H
#define GET_NEXT_LIEN_H

char    *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);


#endif