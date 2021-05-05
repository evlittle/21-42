NAME = libft.a

LIST = 		ft_isalnum.c		ft_isalpha.c		ft_isascii.c\
			ft_isdigit.c		ft_isprint.c		ft_putchar_fd.c\
			ft_putnbr_fd.c		ft_putstr_fd.c		ft_strchr.c\
			ft_strlen.c			ft_tolower.c		ft_toupper.c\
			ft_strlcpy.c		ft_strncmp.c		ft_strchr.c\
			ft_strrchr.c		ft_bzero.c			ft_memcpy.c\
			ft_memccpy.c		ft_memset.c			ft_memchr.c\
			ft_memcmp.c			ft_memmove.c		ft_strnstr.c\
			ft_strlcat.c		ft_atoi.c			ft_calloc.c\
			ft_strdup.c			ft_putendl_fd.c		ft_substr.c\
			ft_strjoin.c		ft_strtrim.c		ft_strmapi.c\
			ft_itoa.c			ft_split.c\

OBJ = $(LIST:%.c=%.o)

D_FILES = $(LIST:%.c=%.d)

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror -I libft.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

clean :
	@rm -f $(OBJ) $(D_FILES)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re