NAME=libft.a
CC=gcc
CFLAGS=
RM=rm -f
LDFLAGS=-L.
LDLIBS=-lft -lm -lcrypto -lpub
SRC = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c detach_block.c get_winsize.c  \
ft_lstnew.c ft_itoa.c ft_create_items.c ft_time.c dhexchange.c make_rand_str.c sha256.c get_ip.c get_port.c \
checksum.c read_file.c _strsplit.c random.c ft_llist_splice.c ft_reverse_llist.c
OBJ = $(SRC:.c=.o)
INC = ./inc/

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		$(CC) -I. -o $@ -c $? $(CFLAGS) $(LDLIBS)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean clean
