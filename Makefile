# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 19:49:21 by zyahansa          #+#    #+#              #
#    Updated: 2025/02/21 12:05:57 by zyahansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g 
LDFLAGS = -O3 -L./minilibx-linux -lmlx_Linux -lmlx -lXext -lX11 -lm -lz
SRCS = main.c ft_rtfm.c ft_rendering_fractal.c ft_minilibx_stuff.c ft_movement.c
OBJS = $(SRCS:.c=.o)
TARGET = fractol

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re