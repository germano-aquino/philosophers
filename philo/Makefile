# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: germano <germano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 19:19:45 by grenato-          #+#    #+#              #
#    Updated: 2022/10/11 19:31:12 by germano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= philo

HEADER_PATH			:= inc
HEADER_FILES		:= philosophers.h

SOURCE_DIRS			:= .
SOURCE_DIRS			+= input utils setup philo clist log
SOURCE_PATH			:= $(addprefix src/, $(SOURCE_DIRS))
SOURCE_FILES		:= main.c
SOURCE_FILES		+= validate.c input.c free.c setup.c run.c operations.c
SOURCE_FILES		+= display.c initial_state.c log.c numbers_to_char.c eat.c
SOURCE_FILES		+= wait.c sleep.c think.c

OBJECT_PATH			:= obj
OBJECT				:= $(SOURCE_FILES:%.c=$(OBJECT_PATH)/%.o)

CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror
REMOVE				:= rm -rf
VALGRIND			:= valgrind
LDFLAGS				:= -L -lpthread
IFLAGS				:= -I $(HEADER_PATH)
VGFLAGS				:= --leak-check=full --show-leak-kinds=all
VGFLAGS				+= --trace-children=yes --track-fds=yes
VGSUPRESS			:= --suppressions=readline.supp

vpath				%.c $(SOURCE_PATH)
vpath				%.h $(HEADER_PATH)

ifdef C_DEBUG
	CFLAGS			+= -g3 -pthread
	CC				:= gcc
endif

ifndef ARGS
	ARGS			:= 4 600 100 100
endif

all:				$(NAME)

$(OBJECT_PATH)/%.o:	%.c $(HEADER_FILES) Makefile | $(OBJECT_PATH)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME):			$(OBJECT_PATH) $(OBJECT)
					$(CC) $(CFLAGS) -o $@ $(OBJECT) $(LDFLAGS)

$(OBJECT_PATH):
					mkdir -p $@

clean:
					$(REMOVE) $(OBJECT_PATH)

fclean:				clean
					$(REMOVE) $(NAME)

re:					fclean all

run:				all
					./$(NAME)

vg:					all
					$(VALGRIND) $(VGFLAGS) ./$(NAME) $(ARGS)

test:				all
					cd minishell_tester && ./tester

.PHONY:				all clean fclean re run vg test
