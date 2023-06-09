##
## EPITECH PROJECT, 2023
## start_project
## File description:
## Makefile
##

NAME	=	libtools.a

SRC		=	src/char/char_is_num.c	\
			src/char/my_putchar.c	\
			src/char/char_is_alpha.c \
			\
			src/str/cm_strtok.c	\
			src/str/my_strlen.c	\
			src/str/my_putstr.c	\
			src/str/my_getnbr_int.c	\
			src/str/my_getnbr_float.c \
			src/str/my_strcpy.c \
			src/str/my_strncpy.c \
			src/str/my_revstr.c \
			src/str/my_strcmp.c \
			src/str/my_strstr.c \
			src/str/my_strncmp.c \
			src/str/str_is_alpha.c \
			src/str/str_is_num.c \
			src/str/my_strdup.c \
			src/str/str_cat.c \
			src/str/str_get.c \
			src/str/str_to_word_array.c \
			src/str/str_to_int_array.c \
			src/str/str_count_int.c \
			\
			src/int/int_is_negativ.c \
			src/int/int_is_overflow.c \
			src/int/int_to_string.c \
			src/int/my_putnbr.c \
			\
			src/array/str1d_to_str2d.c \
			src/array/free_array.c \
			src/array/print_array1d.c \
			src/array/print_array2d.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS = -Wall -Werror -I includes/

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
