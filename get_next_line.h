

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strncpy(char *dest, char *src, int n);
char	*read_buffer(int fd, char *buffer);
char    *extract_line(char *buffer);
char	*clean_buffer(char *buffer);
char	*get_next_line(int fd);

#endif