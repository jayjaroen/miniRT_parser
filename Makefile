# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 10:52:57 by nusamank          #+#    #+#              #
#    Updated: 2024/11/05 15:44:04 by jjaroens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = miniRT

# CC = cc
# CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
# MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
# MLX_PATH = MLX42
# MLX_A = $(MLX_PATH)/build/libmlx42.a

# LIBFT = libft/
# LIBFT_A = $(LIBFT)libft.a
# HEAD = includes
# SRCDIR = srcs
# BINDIR = bin

# HEADERS = $(HEAD)/minirt.h $(HEAD)/struct.h
# SRCS = light.c main.c plane.c quit_program.c rays.c shade.c sphere.c utils.c \
# 		vector_operations.c vector_operations2.c
		
# OBJS = $(SRCS:%.c=$(BINDIR)/%.o)

# all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT_A) Makefile $(MLX_A)
# 	$(CC) $(CFLAGS) -I $(HEAD) $(OBJS) $(LIBFT_A) $(MLX_A) $(MLXFLAGS) -o $@

# $(LIBFT_A):
# 	make -C $(LIBFT)

# $(MLX_A): | $(MLX_PATH)
# 	cmake $(MLX_PATH) -B $(MLX_PATH)/build
# 	make -C $(MLX_PATH)/build -j4

# $(OBJS): $(BINDIR)%.o: $(SRCDIR)%.c $(HEADERS) $(LIBFT_A) Makefile
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -c -I $(HEAD) -I$(LIBFT)$(HEAD) $< -o $@
	
# clean:
# 	rm -rf $(BINDIR)
# 	make -C $(LIBFT) clean
# 	rm -rf $(MLX_PATH)/build

# fclean: clean
# 	rm -rf $(NAME)
# 	make -C $(LIBFT) fclean

# re: fclean all

# .PHONY: all clean fclean re

########################### Below is Mac Version #########################
NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -I minilibx_opengl_20191021
LFLAGS = -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/
LIBFT_A = $(LIBFT)libft.a
HEAD = includes
SRCDIR = srcs
BINDIR = bin

HEADERS = $(HEAD)/minirt.h $(HEAD)/struct.h
# SRCS = light.c main.c plane.c quit_program.c rays.c shade.c sphere.c utils.c \
# 		vector_operations.c vector_operations2.c
SRCS =  main.c parser/check_file.c

OBJS = $(SRCS:%.c=$(BINDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LFLAGS) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT)

$(BINDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) $(LIBFT_A) Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -I $(HEAD) -I$(LIBFT)$(HEAD) $< -o $@

clean:
	rm -rf $(BINDIR)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re