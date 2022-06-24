NAME = "Syfer"
CFLAGS_COMMON =  -Wall  -g -std=gnu99 -fPIC -I .. -I bddisasm/inc
CFLAGS = $(CFLAGS_COMMON)

LDFLAGS = -Lbddisasm/bin/x64/Release -l:libbddisasm.a

SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS =
INC = -I ./includes/

SRCS_NAME = main.c \
	    parameter.c \
		syfer.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(INC) $(LDFLAGS) -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	mkdir -p obj
	gcc -c $(FLAGS) $(LDFLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
