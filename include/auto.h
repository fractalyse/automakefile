
#ifndef _AUTO_h_
# define _AUTO_h_
# define _GNU_SOURCE
# define _POSIX_C_SOURCE
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

int		get_fd(int fd);
int		get_include(int fd);
int		get_source(int fd, char *dirname);
int		write_makefile_to_file(char *bin, int fd);
int		open_file(char *bin);

#endif
