/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:43:27 by trpham            #+#    #+#             */
/*   Updated: 2024/11/26 14:36:19 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETNEXTLINE_H
# define FT_GETNEXTLINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

char	*get_next_line(int	fd);
char	*read_file(char *buffer, int	fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif

