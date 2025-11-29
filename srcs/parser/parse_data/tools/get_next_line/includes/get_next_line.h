/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:47:57 by mfeldman          #+#    #+#             */
/*   Updated: 2023/08/29 18:23:52 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

//**********************************************//
//					GET_NEXT_LINE   			//
//**********************************************//

char	*extract_line(char *line_buffer, char *buf);
char	*get_next_line(int fd);

//**********************************************//
//					UTILS   					//
//**********************************************//

bool	is_end_line(char *buf);
size_t	ft_strlen(char *buf);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif 
