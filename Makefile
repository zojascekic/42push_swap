# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zscekic <zscekic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 12:06:08 by zscekic           #+#    #+#              #
#    Updated: 2026/06/02 16:30:03 by zscekic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MAKE = make
OBJECTS = push_swap.o \
		src/benchmark.o \
		src/disorder.o \
		src/input/input_validation.o \
		src/input/utils.o \
		src/input/utils_array.o \
		src/input/utils_flags.o \
		src/src_stack/push.o \
		src/src_stack/rev_rotate.o \
		src/src_stack/rotate.o \
		src/src_stack/stack_utils.o \
		src/src_stack/swap.o \
		src/algorithms/adaptive.o \
		src/algorithms/bubble_sort.o \
		src/algorithms/chunk_based_sort.o \
		src/algorithms/radix_sort.o \
		src/algorithms/sort_small.o
		
HEADER = push_swap.h
CC = cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -I. -I$(LIBFT_DIR) $(CFLAGS) -c $< -o $@

clean: 
		rm -f $(OBJECTS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean
		
re: fclean all

.PHONY: all clean fclean re bonus