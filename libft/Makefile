# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvasilev <dvasilev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 10:30:17 by zscekic           #+#    #+#              #
#    Updated: 2026/06/02 10:38:25 by dvasilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memcpy.o ft_memmove.o \
		ft_memset.o ft_strcmp.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_tolower.o ft_toupper.o ft_strchr.o ft_strrchr.o \
		ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_calloc.o ft_strdup.o ft_putchar_fd.o \
		ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_substr.o ft_strjoin.o ft_strmapi.o ft_striteri.o \
		ft_strtrim.o ft_itoa.o ft_split.o ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o \
		ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) -I . $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re