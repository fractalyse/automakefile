#include "auto.h"

int		write_makefile_to_file(char *bin, int fd)
{
  write(fd, "NAME	=	", 7);
  write(fd, bin, strlen(bin));
  write(fd, "\n", 1);
  write(fd, "OBJ	=	$(SRC:.c=.o)", 18);
  write(fd, "\n", 1);
  write(fd, "CC	=	gcc", 8);
  write(fd, "\n", 1);
  write(fd, "RM	=	rm -rf", 11);
  write(fd, "\n", 1);
  write(fd, "CFLAGS +=	-W -Werror -Wall -pedantic -g3 -ansi -I./include", 58);
  write(fd, "\n", 1);
  write(fd, "LDFLAGS =	", 10);
  get_include(fd);
  write(fd, "\n", 1);
  write(fd, "SRC	=	", 6);
  get_source(fd, "src");
  write(fd, "\n", 1);
  write(fd, "all:		$(NAME)", 13);
  write(fd, "\n\n", 2);
  write(fd, "export:", 7);
  write(fd, "\n", 1);
  write(fd, "\t\texport PATH=$(PATH):$(HOME)bin", 32);
  write(fd, "\n\n", 2);
  write(fd, "install:", 8);
  write(fd, "\n", 1);
  write(fd, "\t\tmkdir -p $(HOME)/bin", 19);
  write(fd, "\n", 1);
  write(fd, "\t\tcp -f $(NAME) $(HOME)/bin/", 28);
  write(fd, "\n\n", 2);
  write(fd, "$(NAME):	$(OBJ)", 15);
  write(fd, "\n", 1);
  write(fd, "		$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)", 46);
  write(fd, "\n\n", 2);
  write(fd, "clean:", 6);
  write(fd, "\n", 1);
  write(fd, "		$(RM) $(OBJ)", 14);
  write(fd, "\n\n", 2);
  write(fd, "fclean:		clean", 14);
  write(fd, "\n", 1);
  write(fd, "		$(RM) $(NAME)", 15);
  write(fd, "\n\n", 2);
  write(fd, "re:		fclean all", 15);
  return (0);
}


