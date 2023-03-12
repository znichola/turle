# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:49:24 by znichola          #+#    #+#              #
#    Updated: 2023/03/11 14:25:53 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= $(addsuffix .c, $(SNAME))
OBJ		= $(SRC:%.c=%.o)

NAME	= tester

CC	= gcc
CFLAGS	= -Wall -Wextra
# CFLAGS	+= -Werror

ifdef DEBUG
CFLAGS	+= -g3 -fsanitize=address
else
ifdef DEBUGL
CFLAGS += -g3
endif
endif

# 		 main
TURTLE	= turtle drawing init hooks colours map events
CUBE	= main cube ft_vectors ft_mat4x4

FILES	= $(addprefix turtle/, $(TURTLE)) $(addprefix cube/, $(CUBE))

OBJS_PATH = objs/
SRCS_PATH = srcs/
INCS_PATH = -Iincludes/.

SRCS	= $(addprefix $(SRCS_PATH), $(addsuffix .c, $(FILES)))
OBJS	= $(addprefix $(OBJS_PATH), $(addsuffix .o, $(FILES)))

all : $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS_PATH) -Imlx -c $< -o $@

$(NAME): $(OBJS)
ifdef WSL2_GUI_APPS_ENABLED
	$(CC) $(CFLAGS) $(INCS_PATH) $(OBJS) -Lmlx -lmlx -lXext -lX11 -o $(NAME) -lm
else
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
endif

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: clean all
