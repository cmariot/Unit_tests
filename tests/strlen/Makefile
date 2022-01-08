# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/01/08 22:43:56 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME			= tests
SRCS_DIR		= srcs
INCL_DIR		= ./includes
INCL_DIR2		= ../../framework/includes
OBJS_DIR		= objs/


# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC				= clang

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			= -I $(INCL_DIR)
CFLAGS			+= -I $(INCL_DIR2)

LFLAGS			= -Wall -Wextra -Werror


# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRCS			= ../main.c \
				  00_launcher.c \
				  01_basic_test.c \
				  02_null_test.c \
				  03_bigger_str_test.c

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
		@printf "$(CC) $(LFLAGS) $(OBJS) $(LIB_LFLAGS) -o $(NAME)$(RC)\n"

$(NAME)	: srcs_compil $(SRCS) $(OBJS) obj_link
		@make -C ../../framework
		@mv ../../framework/libunit.a .
		@$(CC) $(LFLAGS) $(OBJS) libunit.a -o $(NAME)
		@printf "$(GR)Success, $(NAME) is ready.\n\n$(RC)"

# Check 42 norm 
norm :
		@norminette

# Compile and launch
test :	all
		@./$(NAME)

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
