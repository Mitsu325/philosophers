# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 07:29:43 by pmitsuko          #+#    #+#              #
#    Updated: 2022/11/02 12:12:48 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = philo_bonus

# LIBRARY #

HEADER = -I includes -lpthread

# COMPILATION #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# DELETE #

RM = rm -rf

# DIRECTORIES #

SRC_DIR = ./src/

VPATH = $(SRC_DIR)

# FILES #

FILES = main_bonus.c\
		check_arg_bonus.c\
		clear_mem_bonus.c\
		init_bonus.c\
		life_philo_bonus.c\
		simulator_bonus.c\
		time_bonus.c\
		utils_bonus.c

# COMPILED_SOURCES #

OBJ_DIR = ./obj_bonus/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(FILES:.c=.o)))

# **************************************************************************** #

## RULES ##

$(OBJ_DIR)%.o: %.c
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		@echo "\n$(CYAN)----------------------------------------"
		@echo "----------- MAKE PHILO BONUS -----------"
		@echo "----------------------------------------\n$(DEFAULT)"
		@$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $(NAME)

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

clean:
		@$(RM) $(OBJ_DIR) *.gc*

fclean: clean
		@$(RM) $(NAME)
		@echo "\n$(MAGENTA)----------------------------------------"
		@echo "------------- CLEANING DONE ------------"
		@echo "----------------------------------------\n$(DEFAULT)"

re: fclean all

# **************************************************************************** #

## TESTS ##

valgrind: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo_bonus 2 200 100 20

helgrind: re
	@valgrind --tool=helgrind ./philo_bonus 2 200 100 20

.PHONY: all clean fclean re
