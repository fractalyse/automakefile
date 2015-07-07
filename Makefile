NAME	=	autom
OBJ	=	$(SRC:.c=.o)
CC	=	gcc
RM	=	rm -rf
CFLAGS +=	-W -Werror -Wall -pedantic -g3 -ansi -I./include
LDFLAGS =	-Lauto 
SRC	=	src/write_makefile_to_file.c \
		src/get_source.c \
		src/main.c \
		src/open_file.c \
		src/get_include.c \

all:		$(NAME)

export:
		export PATH=$(PATH):$(HOME)bin
install:
		mkdir -p $(HOME)/
		cp -f $(NAME) $(HOME)/bin/

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all