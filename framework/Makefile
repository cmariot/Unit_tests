# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/01/08 22:17:56 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME			= libunit.a
SRCS_DIR		= srcs
INCL_DIR		= includes
TEST_INCL_DIR	= ../tests/includes
OBJS_DIR		= objs/


# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC				= clang

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -I $(INCL_DIR)
CFLAGS			+= -I $(TEST_INCL_DIR)

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRCS			= launch_tests.c \
				  libft.c \
				  logfiles.c \
				  output.c \
				  test_lst_utils.c \
				  timeout.c

SRC				:= $(notdir $(SRCS))

OBJ				:= $(SRC:.c=.o)

OBJS			:= $(addprefix $(OBJS_DIR), $(OBJ))

VPATH			:= $(SRCS_DIR) $(OBJS_DIR) $(shell find $(SRCS_DIR) -type d)

# **************************************************************************** #
#							 	   COLORS                                      #
# **************************************************************************** #

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m


# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #

all : $(NAME)

# Compiling
srcs_compil :
		@printf "$(YE)Source code compilation ... \n"

$(OBJS_DIR)%.o : %.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "$(CC) $(CFLAGS) -c $< -o $@\n"
		
# Linking
obj_link :
		@printf "$(YE)$(NAME) compilation success.\n\n"
		@printf "$(GR)Linking $(NAME) objects ...\n"
		@printf "ar rc $(NAME) $(OBJS) $(RC)\n"

$(NAME)	: srcs_compil $(SRCS) $(OBJS) obj_link
		@ar rc $(NAME) $(OBJS)
		@printf "$(GR)Success, $(NAME) is ready.\n\n$(RC)"

leaks : all
		valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./$(NAME)

# Check 42 norm 
norm :
		@norminette

# Remove object files
clean :
		@printf "Removing $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n$(RC)"

# Remove object and binary files
fclean :
		@printf "Removing $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n"
		@printf "Removing $(NAME) ... "
		@rm -f $(NAME)
		@printf "Done\n$(RC)"

print_divider :
		@printf "\n"

# Remove all and recompile
re :	 fclean print_divider all

.PHONY : clean fclean
