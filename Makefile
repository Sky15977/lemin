##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles mylib
##

CC	=	gcc

SRC	=	\
		src/algo/tab/create_tab.c	\
		src/algo/tab/display_path.c	\
		src/algo/tab/test_bfs.c		\
		src/algo/start_algo.c	\
		src/algo/tab/change_tab_value.c \
		src/algo/tab/fill_visited.c \
		\
		src/display_informations/display_parsing.c	\
		src/display_informations/display_info.c		\
		src/display_informations/display_no_room.c	\
		\
		src/error/check_room.c	\
		src/error/error.c		\
		\
		src/parsing/body_lemin.c			\
		src/parsing/check_no_pipe_room.c	\
		src/parsing/count.c					\
		src/parsing/error_handling_tab.c	\
		src/parsing/open_read_file.c		\
		src/parsing/init_struct.c			\
		src/parsing/parsing.c				\
		src/parsing/fill_element.c			\
		src/parsing/recup_nbr.c				\
		src/parsing/get_ants.c				\
		src/parsing/check_file.c			\
		\
		src/main.c		\
		src/getnbr.c	\
		src/my_strcat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

INCLUDES	=	-I includes/	\
				-I lib/tools/includes	\

LDFLAGS += 		-L lib/tools/ -l tools \

CFLAGS	=	$(INCLUDES) -Wall -Wextra -g

all: 	$(NAME)

$(NAME):	make_lib $(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		@echo -e "\033[1;32mCompilation done\033[0m"

%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

make_lib:
		@make -C lib/tools/

clean:
	@rm -f $(OBJ)
	@make clean -C lib/tools/
	@find . \( -name "*~" -o -name "#*" -o -name "*#" \) -delete
	@echo -e "\033[1;31mClean done\033[0m"

fclean: clean
	@make fclean -C lib/tools/
	@rm -f $(NAME)
	@rm -f coding-style-reports.log
	@rm -f vgcore*
	@echo -e "\033[1;31mFclean done\033[0m"

re: 	fclean all

.PHONY: all re clean fclean
