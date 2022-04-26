NAME	= libft.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
SRCP	= src
PART_1	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c
PART_2	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
ICDP	= include
ICDS	= -I$(ICDP)
OBJP	= obj
OBJS	= $(PART_1:%.c=$(OBJP)/%.o) $(PART_2:%.c=$(OBJP)/%.o)
AR	= ar -rcs
RM	= rm -fr
MKDIR	= mkdir -p
VPATH	= . $(SRCP) $(OBJP)

$(OBJP)/%.o:	%.c
		$(CC) $(CFLAGS) $(ICDS) -c $< -o $@

all:		$(NAME)

$(OBJP):
		$(MKDIR) $(OBJP)

$(NAME):	$(OBJP) $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJP)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
