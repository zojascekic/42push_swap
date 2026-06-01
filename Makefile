# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 12:06:08 by zscekic           #+#    #+#              #
#    Updated: 2026/06/01 13:48:14 by dvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
OBJECTS = push_swap.o src/benchmark.o src/disorder.o \
		src/input/input_validation.o src/input/utils.o src/input/utils_libft.o \
		src/input/utils_ft_split.o src/input/utils_flags.o \
		src/src_stack/push.o src/src_stack/rev_rotate.o \
		src/src_stack/rotate.o src/src_stack/stack_utils.o \
		src/src_stack/swap.o \
		src/algorithms/adaptive.o src/algorithms/bubble_sort.o \
		src/algorithms/chunk_based_sort.o src/algorithms/radix_sort.o
SRC =  push_swap.c src/benchmark.c src/disorder.c \
		src/input/input_validation.c src/input/utils.c src/input/utils_libft.c \
		src/input/utils_ft_split.c src/input/utils_flags.c \
		src/src_stack/push.c src/src_stack/rev_rotate.c \
		src/src_stack/rotate.c src/src_stack/stack_utils.c \
		src/src_stack/swap.c \
		src/algorithms/adaptive.c src/algorithms/bubble_sort.c \
		src/algorithms/chunk_based_sort.c src/algorithms/radix_sort.c
		
HEADER = push_swap.h
CC = cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
		ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)
		
re: fclean all