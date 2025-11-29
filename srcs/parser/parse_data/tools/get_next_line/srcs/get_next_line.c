/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:35:12 by mfeldman          #+#    #+#             */
/*   Updated: 2023/08/29 18:26:31 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *line_buffer, char *buf)
{
	char			*line;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (line_buffer[j] && j < i)
	{
		line[j] = line_buffer[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (line_buffer[i] && j < BUFFER_SIZE)
		buf[j++] = line_buffer[i++];
	buf[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line;
	char			*line_buffer;
	int				ret;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line_buffer = ft_strdup(buf);
	if (!line_buffer)
		return (NULL);
	ret = 1;
	while (!is_end_line(buf) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1 || (!ret && !line_buffer[0]))
			return (free(line_buffer), NULL);
		buf[ret] = '\0';
		line_buffer = ft_strjoin(line_buffer, buf);
		if (!line_buffer)
			return (NULL);
	}
	line = extract_line(line_buffer, buf);
	return (free(line_buffer), line);
}
