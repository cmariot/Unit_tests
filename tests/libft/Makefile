# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/01/10 12:09:56 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME			= tests_libft
SRCS_DIR		= tests
INCL_DIR		= ./includes
INCL_FRAMEWORK	= ../../framework/includes
OBJS_DIR		= objs/

PROJECT_DIR		= ../../libft
INCL_PROJECT	= $(PROJECT_DIR)/includes

# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC				= clang

CFLAGS			= -Wall -Wextra -Werror
CFLAGS			= -I $(INCL_DIR)
CFLAGS			+= -I $(INCL_FRAMEWORK)
CFLAGS			+= -I $(INCL_PROJECT)

LFLAGS			= -Wall -Wextra -Werror
L_LIB_FLAGS		= -L $(PROJECT_DIR) -lft


# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRCS			= ../main.c \
				  00_launcher.c \
				  01_strlen_test.c \
				  02_strtoll_test.c

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
		@make -C ../../framework
		@make -C ../../libft
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
		@mv ../../framework/libunit.a .
		@$(CC) $(LFLAGS) $(OBJS) libunit.a $(L_LIB_FLAGS) -o $(NAME)
		@printf "$(GR)Success, $(NAME) is ready.\n\n$(RC)"

# Check 42 norm
norm :
		@norminette

# Compile and launch
test :	all
		@./$(NAME)

# Remove object files
clean :
		@make -C ../../framework clean
		@make -C ../../libft clean
		@printf "Removing $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n$(RC)"

# Remove object and binary files
fclean :
		@make -C ../../framework fclean
		@make -C ../../libft fclean
		@printf "Removing $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n"
		@printf "Removing $(NAME) ... "
		@rm -f $(NAME) libunit.a *.log
		@printf "Done\n$(RC)"

print_divider :
		@printf "\n"

# Remove all and recompile
re :	 fclean print_divider all

.PHONY : clean fclean
