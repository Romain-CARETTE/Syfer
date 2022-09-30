NAME = Syfer
LIBFT_PATH = libft/
CFLAGS_COMMON :=  -Wall  -g -std=gnu99 -fPIC -I .. -I bddisasm/inc -I ./$(LIBFT_PATH)/includes
CFLAGS = $(CFLAGS_COMMON)

NASM := nasm -f bin

LDFLAGS := -Lbddisasm/bin/x64/Release -l:libbddisasm.a -lcrypto -L $(LIBFT_PATH) -lft

SRCS_PATH := srcs/
OBJ_PATH  := obj/
LIBFT_PATH := libft/

FLAGS = 
INC := -I ./includes/

SRCS_NAME = main.c \
	    parameter.c \
	    metamorph.c \
	    syfer.c \
	    syscall.c \
	    backdoor.c \
	    utils.c \
	    apply_inner_encryption.c \
	    apply_global_encryption.c \

STRIP  := strip $(NAME)
OBJDUMP := objdump -M intel -d $(NAME) --section=.text > debug/$(NAME).obj
STRINGS := strings $(NAME) > debug/$(NAME).str
XXD := xxd -i

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: INIT $(NAME)

$(NAME): $(OBJ) COMPILE_AND_MOVE
	make -C libft/
	clang $(FLAGS) $(OBJ) srcs/rc4.o $(INC) $(LDFLAGS) -o $(NAME)
	@echo "\033[32m[+] Binary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"
	$(OBJDUMP)
	#$(STRIP)
	#$(STRINGS)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	clang -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

COMPILE_AND_MOVE:
	@for file in `ls srcs/` ; do \
		VAR=$$(echo -e $$file | tail -c3) ; \
		if [ $$VAR = ".s" ] ; then \
			echo $$file ; \
			$(NASM) srcs/$$file  ; \
			VAR=$$(echo -n $$file | tr -d ".s") ; \
			mv srcs/$$VAR bin/ ; \
			xxd -i "bin/$$VAR" > debug/$$VAR ; \
		fi ; \
	done; \

INIT:
	@if [ ! -d "OUT_bin" ] ; then \
		mkdir OUT_bin ; \
	fi ; \
	mkdir -p obj debug bin backup tmp

clean:
	@make -C $(LIBFT_PATH)/ clean
	/bin/rm -rf $(OBJ_PATH) debug/ bin/ backup/ tmp/
	@echo "\033[31mObjects files, debug and bin\033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean RM_OUT_BIN
	@make -C $(LIBFT_PATH)/ fclean
	/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"


RM_OUT_BIN:
	/bin/rm -rf OUT_bin


re: fclean all

.PHONY: all, clean, fclean, re
