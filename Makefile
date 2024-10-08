### PROGRAM NAME ###
NAME		:= push_swap

### UTILS ###
CC 			:= clang
CFLAGS 		:= -Wall -Wextra -Werror -g3
DEP_FLAGS	:= -MMD -MP
MAKE_FLAG 	:= --no-print-directory --silent
RM 			:= rm -rf

### COLORS ###
DEFAULT    	:= \033[0m
BLACK    	:= \033[0;30m
RED        	:= \033[0;31m
DRED		:= \033[0;31;5m
GREEN    	:= \033[0;32m
UGREEN    	:= \033[4;32m
YELLOW    	:= \033[;33m
BLUE    	:= \033[0;34m
PURPLE    	:= \033[0;35m
CYAN    	:= \033[0;36m
BWHITE    	:= \033[1;37m
NEW			:= \r\033[K

### DIRECTORIES ###
SRC_DIR 	:= src
INCLD_DIR 	:= include
OBJS_DIR 	:= objs
LIBFT_DIR 	:= libft

### FILES ###
INCLUDES	:= ${INCLD_DIR}/ \
	${LIBFT_DIR}/${INCLD_DIR}/ \
INCLUDES 	:= ${strip ${INCLUDES}}

INCLD_FLAG 	:= ${addprefix -I , ${INCLUDES}}
LIBFT		:= ${LIBFT_DIR}/libft.a

LIB 		:= ${LIBFT}
LIB 		:= ${strip ${LIB}}

SRC := checks.c \
	cost.c \
	main.c \
	push.c \
	rotate.c \
	rrotate.c \
	sort.c \
	start_sort.c \
	swap.c \
	utils.c \

SRC 		:= ${strip ${SRC}}
OBJS 		:= ${patsubst %.c,${OBJS_DIR}/%.o,${SRC}}
DEPS		:= ${patsubst %.c,${OBJS_DIR}/%.d,${SRC}}

### PROJECT ###

.PHONY: all
all: ${NAME}

${NAME}: ${LIB} ${OBJS}
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Compiling:${DEFAULT}${BWHITE} $@${DEFAULT}."
	@${CC} ${CFLAGS} ${OBJS} ${LIB} ${INCLD_FLAG} -o $@
	@printf "\n"

-include ${DEPS}
${OBJS_DIR}/%.o: ${SRC_DIR}/%.c
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Compiling:${DEFAULT} $<."
	@mkdir -p ${OBJS_DIR}
	@${CC} ${DEP_FLAGS} ${CFLAGS} ${INCLD_FLAG} -c $< -o $@

.PHONY: clean
clean:
	@printf "${PURPLE}[${NAME}] ${RED}Cleaning ${DEFAULT}${OBJS_DIR} files.\n"
	@${RM} ${OBJS_DIR}

.PHONY: fclean
fclean: clean
	@printf "${PURPLE}[${NAME}] ${RED}Cleaning ${DEFAULT}${NAME}.\n"
	@${RM} ${NAME}

.PHONY: re
re: fclean all

### LIBFT ###
${LIBFT}:
	@make -C ${LIBFT_DIR} ${MAKE_FLAG}

.PHONY: cleanlib
cleanlib:
	@make -C ${LIBFT_DIR} clean ${MAKE_FLAG}

.PHONY: fcleanlib
fcleanlib:
	@make -C ${LIBFT_DIR} fclean ${MAKE_FLAG}
	@printf "${DRED}[${LIBFT_DIR}] Library cleaned.\n"

.PHONY: relib
relib:
	@make -C ${LIBFT_DIR} re ${MAKE_FLAG}

### NORM ###
.PHONY: norm
norm: ; @make -C ${LIBFT_DIR} norm ${MAKE_FLAG}
	@norminette ${SRC_DIR} ${INCLD_DIR} | awk '/Error/ {print; found=1} END \
	{if {!found} {print "${PURPLE}[${NAME}] ${DEFAULT}Norm: ${BWHITE}OK${DEFAULT}"; exit 0 }; exit 1 }'
