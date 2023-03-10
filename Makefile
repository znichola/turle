# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:49:24 by znichola          #+#    #+#              #
#    Updated: 2023/03/10 23:24:55 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME	= main turtle drawing init hooks colours map events
SRC		= $(addsuffix .c, $(SNAME))
OBJ		= $(SRC:%.c=%.o)

NAME	= turtle

CFLAGS	= -g
# CFLAGS	= -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
ifdef LINUX
	$(CC) $(OBJ) -Lmlx -lmlx -lXext -lX11 -o $(NAME) -lm
else
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
endif

clean:
	rm -f $(NAME) $(OBJ)

re: clean all
