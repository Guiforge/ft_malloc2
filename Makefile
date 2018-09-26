# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/05 12:29:27 by gpouyat           #+#    #+#              #
#    Updated: 2018/09/26 20:43:45 by gpouyat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.NOTPARALLEL:

.PHONY: all clean fclean re

C_NO = \033[0m
C_G = \033[0;32m
C_Y = \033[1;33m
C_B = \033[1;34m
C_C = \033[1;36m
C_R = \033[1;31m

SRCS_NAME		+= intern/create_zone.c intern/error.c intern/init_zones.c \
					intern/find_block.c intern/get.c intern/check_align.c \
					intern/split_block.c intern/set_extra.c \
					intern/resize_block.c intern/defrag.c intern/link_zone.c \
					intern/create_alloc.c
SRCS_NAME		+= malloc.c free.c


###############################################################################

#  Compiler

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME 			= libft_malloc_$(HOSTTYPE).so
NAME_TEST	= libmalloc_test.a
CC				= clang
CFLAGS		= -Wall -Wextra -Werror

ifeq ($(DEV),yes)
    CFLAGS		+= -g3
endif

ifeq ($(SAN),yes)
    CFLAGS		+= -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -g3
endif

#The Directories, Source, Includes, Objects and Libraries
INC			= -I includes -I libft/includes
SRCS_DIR	= sources
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

#Objects
OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJS_DIR	= objs
OBJS = $(addprefix $(OBJS_DIR)/,$(OBJ_NAME))


LIB_PATH = ./libft/
LIB_NAME = -lft
LIB = $(addprefix -L,$(LIB_PATH))
LFLAGS = $(LIB) $(LIB_NAME)

#Utils
RM					= rm -rf
MKDIR				= mkdir -p
LINK				= libft_malloc.so

COUNT = 0
TOTAL = 0
PERCENT = 0
$(eval TOTAL=$(shell echo $$(printf "%s" "$(SRCS)" | wc -w)))

#tests
COUNT_TESTS = 0
TOTAL_TESTS = 0
PERCENT_TESTS = 0
$(eval TOTAL_TESTS=$(shell echo $$(printf "%s" "$(SRCS_TESTS)" | wc -w)))
###############################################################################


all: lib $(NAME)

lib:
	@make -C $(LIB_PATH) CFLAGS="$(CFLAGS)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(INC) -shared -o $(NAME) $(LFLAGS)
	@/bin/rm -f $(LINK)
	@ln -s $(NAME) $(LINK)
	@echo
	@echo compiling with flag: $(CFLAGS)
	@echo "[\033[35m------------------------------------------------\033[0m]"
	@echo "[\033[36m----------- MALLOC compilation Done! -----------\033[0m]"
	@echo "[\033[35m------------------------------------------------\033[0m]"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR) $(OBJS_DIR)/intern
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	$(eval PERCENT=$(shell echo $$((($(COUNT) * 100 )/$(TOTAL)))))
	@printf "$(C_B)%-8s $(C_C) $<$(C_NO)                                           \n" "[$(PERCENT)%]"

$(OBJS_DIR_TESTS)/%.o: $(SRCS_DIR_TESTS)/%.c
	@mkdir -p $(OBJS_DIR_TESTS)
	@$(CC) $(CFLAGS) $(INC) $(INC_TESTS) -o $@ -c $<
	$(eval COUNT_TESTS=$(shell echo $$(($(COUNT_TESTS)+1))))
	$(eval PERCENT_TESTS=$(shell echo $$((($(COUNT_TESTS) * 100 )/$(TOTAL_TESTS)))))
	@printf "$(C_B)%-8s $(C_G) $<$(C_NO)                                           \n" "[$(PERCENT_TESTS)%]"

clean:
	@echo "\033[35m$(NAME)  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS_DIR_TESTS)
	@make clean -C $(LIB_PATH)

fclean: clean
	@echo "\033[35m$(NAME)  :\033[0m [\033[31mSuppression de $(NAME) et $(LINK)\033[0m]"
	@$(RM) $(NAME)
	@$(RM) $(LINK)
	@$(RM) test
	@$(RM) $(NAME_TEST)
	@make fclean -C $(LIB_PATH)

re: fclean all

miniclean:
	@echo "\033[35m$(NAME)  :\033[0m [\033[31mSuppression des .o\033[0m]"
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS_DIR_TESTS)

miniflcean: miniclean
	@echo "\033[35m$(NAME)  :\033[0m [\033[31mSuppression de $(NAME) et $(LINK)\033[0m]"
	@$(RM) $(NAME)
	@$(RM) $(LINK)
	@$(RM) test
	@$(RM) $(NAME_TEST)

minire: miniflcean all

.PHONY: re clean fclean all lib doc dev minire miniflcean miniclean
.SUFFIXES: .c .h .o .d
