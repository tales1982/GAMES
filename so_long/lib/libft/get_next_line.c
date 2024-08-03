/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tales <tales@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:53:54 by tlima-de          #+#    #+#             */
/*   Updated: 2024/06/01 19:46:07 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *ft_read(int int_fd, char *full_line)
{
    char *buffer;
    int nbr_bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    nbr_bytes_read = 1;
    while (nbr_bytes_read != 0)
    {
        nbr_bytes_read = read(int_fd, buffer, BUFFER_SIZE);
        if (nbr_bytes_read == -1)
        {
            free(buffer);
            free(full_line);
            return (NULL);
        }
        buffer[nbr_bytes_read] = '\0';
        char *temp = full_line;
        full_line = ft_strjoin(full_line, buffer);
        free(temp);
        if (ft_strchr(full_line, '\n'))
            break;
    }
    free(buffer);
    return (full_line);
}

static char *ft_return_line(char *full_line)
{
    int i;
    char *line_2b_printed;

    i = 0;
    if (!full_line || !*full_line)
        return (NULL);
    while (full_line[i] && full_line[i] != '\n')
        i++;
    line_2b_printed = malloc(i + 2);
    if (!line_2b_printed)
        return (NULL);
    i = 0;
    while (full_line[i] && full_line[i] != '\n')
    {
        line_2b_printed[i] = full_line[i];
        i++;
    }
    if (full_line[i] == '\n')
    {
        line_2b_printed[i] = full_line[i];
        i++;
    }
    line_2b_printed[i] = '\0';
    return (line_2b_printed);
}

static char *ft_keep_rest(char *full_line)
{
    int i;
    int j;
    char *rest;

    i = 0;
    while (full_line[i] && full_line[i] != '\n')
        i++;
    if (!full_line[i] || (full_line[i] == '\n' && !full_line[i + 1]))
    {
        free(full_line);
        return (NULL);
    }
    rest = malloc(ft_strlen(full_line) - i);
    if (!rest)
        return (NULL);
    i++;
    j = 0;
    while (full_line[i])
        rest[j++] = full_line[i++];
    rest[j] = '\0';
    free(full_line);
    return (rest);
}

char *get_next_line(int fd)
{
    static char *full_line;
    char *line_2b_printed;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!full_line)
    {
        full_line = malloc(1);
        if (!full_line)
            return (NULL);
        full_line[0] = '\0';
    }
    full_line = ft_read(fd, full_line);
    if (!full_line)
        return (NULL);
    line_2b_printed = ft_return_line(full_line);
    full_line = ft_keep_rest(full_line);
    return (line_2b_printed);
}
