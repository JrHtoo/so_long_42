# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:28:49 by juhtoo-h          #+#    #+#              #
#    Updated: 2024/10/23 14:42:35 by juhtoo-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/

# SRCS = check_map.c main.c error_utils.c file_to_img.c so_long_utils.c put_pic.c \
# 		events.c animation.c
		
 SRCS = check_map.c so_long.c error_utils.c file_to_img.c so_long_utils.c put_pic.c \
 		events.c animation.c

SRCS_PREFIXED = $(addprefix $(SRC_PATH), $(SRCS))

INCLUDE = include/so_long.h

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -g3 -fsanitize=address

MLX42_PATH = lib/MLX42/

MLX42_LIB = $(MLX42_PATH)build/libmlx42.a -ldl -lglfw -pthread -lm

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

LIBFT_PATH = lib/libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

PRINTF_PATH = lib/ft_printf/

PRINTF_LIB = $(PRINTF_PATH)libftprintf.a

OBJECTS = $(SRCS_PREFIXED:.c=.o)

all: SUBSYSTEMS $(NAME)

SUBSYSTEMS:
		@echo "Making MLX42..."
		@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build && make -C $(MLX42_PATH)/build -j4
		@echo "Making libft"
		make -C $(LIBFT_PATH) all
		@echo "Making libprintf"
		make -C $(PRINTF_PATH) all

%.o : %.c Makefile $(INCLUDE)
	@echo "Compling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) Makefile $(INCLUDE)
	@echo "Compling $(SRCS)..."
	@echo "Finished $(SRCS)"
	@echo
	@echo "Compling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX42_LIB) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)
	@echo "Finished $(NAME)"

norm:
	norminette lib/libft lib/ft_printf src include

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
	@rm -f $(OBJECTS)
	@rm -rf $(MLX42_PATH)build
	@echo "Removed $(OBJECTS)"

fclean: clean
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean
	@rm -f $(NAME)
	@echo "Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re norm