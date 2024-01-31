NAME	=	libft.a
SRC		=	ft_atoi.c			\
			ft_bzero.c 			\
			ft_calloc.c 		\
			ft_isalnum.c 		\
			ft_isalpha.c 		\
			ft_isascii.c 		\
			ft_isdigit.c 		\
			ft_isprint.c 		\
			ft_itoa.c 			\
			ft_memchr.c 		\
			ft_memcmp.c 		\
			ft_memcpy.c 		\
			ft_memmove.c 		\
			ft_memset.c 		\
			ft_putchar_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c 		\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c 		\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strtrim.c		\
			ft_substr.c			\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_split.c			\

BNS_SRC	=	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_lstclear.c

GNL_SRC	=	get_next_line.c	\
			get_next_line_utils.c

PRNTF_SRC =	ft_printf.c				\
			ft_printf_flags.c		\
			ft_printf_formats.c		\
			ft_printf_printers.c	\
			ft_printf_utilities.c

OBJ			=	$(SRC:%.c=%.o)
BNS_OBJ		=	$(BNS_SRC:%.c=%.o)
GNL_OBJ		=	$(GNL_SRC:%.c=%.o)
PRNTF_OBJ	=	$(PRNTF_SRC:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(GNL_OBJ) $(PRNTF_OBJ)
	@ar rcs $(NAME) $(OBJ) $(GNL_OBJ) $(PRNTF_OBJ)

bonus		:	$(OBJ) $(GNL_OBJ) $(PRNTF_OBJ) $(BNS_OBJ)
	@ar rcs $(NAME) $^

$(OBJ)		:	$(SRC)
	@cc -Wall -Wextra -Werror -c $^

$(BNS_OBJ)	:	$(BNS_SRC)
	@cc -Wall -Wextra -Werror -c $^

$(GNL_OBJ)	:	$(GNL_SRC)
	@cc -Wall -Wextra -Werror -c $^

$(PRNTF_OBJ)	:	$(PRNTF_SRC)
	@cc -Wall -Wextra -Werror -c $^

clean		:
	@rm -f $(OBJ) $(BNS_OBJ) $(GNL_OBJ) $(PRNTF_OBJ)

fclean		:	clean
	@rm -f $(NAME)

re			:	fclean all

rebonus		:	fclean bonus

.PHONY:		all clean fclean re bonus