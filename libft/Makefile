# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:16:33 by nusamank          #+#    #+#              #
#    Updated: 2024/06/27 14:00:27 by nusamank         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = srcs
BINDIR = bin
LIBFTDIR = $(SRCDIR)/libft
FT_PRINTF_DIR = $(SRCDIR)/ft_printf
GET_NEXT_LINE_DIR = $(SRCDIR)/get_next_line

SRC_LIBFT = ft_atoi.c    ft_isalnum.c  ft_isdigit.c  ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c  ft_lstmap_bonus.c ft_memchr.c  ft_memmove.c \
			ft_putendl_fd.c  ft_split.c   ft_striteri.c  ft_strlcpy.c \
			ft_strncmp.c  ft_strtrim.c  ft_toupper.c  ft_bzero.c  ft_isalpha.c \
			ft_isprint.c  ft_lstadd_front_bonus.c  ft_lstiter_bonus.c \
			ft_lstnew_bonus.c   ft_memcmp.c  ft_memset.c      ft_putnbr_fd.c \
			ft_strchr.c  ft_strjoin.c  ft_strlen.c   ft_strnstr.c  ft_substr.c \
			ft_calloc.c  ft_isascii.c  ft_itoa.c     ft_lstclear_bonus.c \
			ft_lstlast_bonus.c ft_lstsize_bonus.c ft_memcpy.c ft_putchar_fd.c \
			ft_putstr_fd.c   ft_strdup.c  ft_strlcat.c   ft_strmapi.c \
			ft_strrchr.c  ft_tolower.c
SRC_LIBFT := $(addprefix $(LIBFTDIR)/, $(SRC_LIBFT))
SRC_FT_PRINTF = ft_printf.c  print_c.c  print_hex.c  print_int.c  print_ptr.c  print_str.c
SRC_FT_PRINTF := $(addprefix $(FT_PRINTF_DIR)/, $(SRC_FT_PRINTF))
SRC_GET_NEXT_LINE = get_next_line.c get_next_line_utils.c
SRC_GET_NEXT_LINE := $(addprefix $(GET_NEXT_LINE_DIR)/, $(SRC_GET_NEXT_LINE))
OBJ_LIBFT := $(patsubst $(LIBFTDIR)/%.c,$(BINDIR)/%.o,$(SRC_LIBFT))
OBJ_FT_PRINTF := $(patsubst $(FT_PRINTF_DIR)/%.c,$(BINDIR)/%.o,$(SRC_FT_PRINTF))
OBJ_GET_NEXT_LINE := $(patsubst $(GET_NEXT_LINE_DIR)/%.c,$(BINDIR)/%.o,$(SRC_GET_NEXT_LINE))
OBJS = $(OBJ_LIBFT) $(OBJ_FT_PRINTF) $(OBJ_GET_NEXT_LINE)

HEAD = includes

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(BINDIR)/%.o: $(LIBFTDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@
	
$(BINDIR)/%.o: $(FT_PRINTF_DIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(BINDIR)/%.o: $(GET_NEXT_LINE_DIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@
		
$(BINDIR):
	mkdir -p $(BINDIR)
	
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(BINDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re