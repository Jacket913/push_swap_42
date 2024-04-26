## PROGRAM NAME ##
NAME		:= push_swap

## UTILS ##
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -g3
DEP_FLAGS	:= -MMD -MP
MAKE_FLAG 	:= --no-print-directory --silent
RM 			:= rm -rf

## COLORS ##
DEFAULT		:= \033[0m
BLACK		:= \033[0;30m
RED			:= \033[0;31m
DRED		:= \033[0;31;5m
GREEN		:= \033[0;32m
UGREEN		:= \033[4;32m
YELLOW		:= \033[;33m
BLUE		:= \033[0;34m
PURPLE		:= \033[0;35m
CYAN		:= \033[0;36m
BWHITE		:= \033[1;37m
NEW			:= \r\033[K

## DIRECTORIES ##
SRC_DIR 	:= src
INCLD_DIR 	:= include
OBJS_DIR 	:= objs
LIBFT_DIR 	:= libft

## SOURCES & FILES ##
INCLUDES	:= ${INCLD_DIR}/ \
	${LIBFT_DIR}/${INCLD_DIR}/ \
INCLUDES 	:= ${strip ${INCLUDES}}

INCLD_FLAG 	:= ${addprefix -I , ${INCLUDES}}
LIBFT		:= ${LIBFT_DIR}/libft.a

LIB 		:= ${LIBFT}
LIB 		:= ${strip ${LIB}}

SRC := *.c

SRC 		:= ${strip ${SRC}}
OBJS 		:= ${patsubst %.c,${OBJS_DIR}/%.o,${SRC}}
DEPS		:= ${patsubst %.c,${OBJS_DIR}/%.d,${SRC}}

## PROJECT ##
.PHONY: all clean fclean re cleanlib fcleanlib relib norm
all: ${NAME}

${NAME}: ${LIB} ${OBJS}
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Building:${DEFAULT}${BWHITE} $@${DEFAULT}"
	@${CC} ${CFLAGS} ${OBJS} ${LIB} ${INCLD_FLAG} -o $@
	@printf "\n"

-include ${DEPS}
${OBJS_DIR}/%.o: ${SRC_DIR}/%.c
	@printf "${NEW}${PURPLE}[${NAME}] ${UGREEN}Building:${DEFAULT} $<"
	@mkdir -p ${OBJS_DIR}
	@${CC} ${DEP_FLAGS} ${CFLAGS} ${INCLD_FLAG} -c $< -o $@

clean:
	@printf "${PURPLE}[${NAME}] ${RED}Obliterating ${DEFAULT}${OBJS_DIR} files\n"
	@${RM} ${OBJS_DIR}

fclean: clean
	@printf "${PURPLE}[${NAME}] ${RED}Obliterating ${DEFAULT}${NAME}\n"
	@${RM} ${NAME}

re: fclean all

## LIBFT RULES ##
${LIBFT}:
	@make -C ${LIBFT_DIR} ${MAKE_FLAG}

cleanlib:
	@make -C ${LIBFT_DIR} clean ${MAKE_FLAG}

fcleanlib:
	@make -C ${LIBFT_DIR} fclean ${MAKE_FLAG}
	@printf "${DRED}[${LIBFT_DIR}] Lib obliterated\n"

relib:
	@make -C ${LIBFT_DIR} re ${MAKE_FLAG}

## NORM ##
norm: ; @make -C $(LIBFT_DIR) norm $(MAKE_FLAG)
	@norminette $(SRC_DIR) $(INCLD_DIR) | awk '/Error/ {print; found=1} END \
	{if (!found) {print "$(PURPLE)[$(NAME)] $(DEFAULT)Norm: $(BWHITE)OK$(DEFAULT)"; exit 0 }; exit 1 }'
