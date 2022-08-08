##------------------------------------------------------------------------------##
## 								 THE TARGET										##
##------------------------------------------------------------------------------##
TARGET	:= libft.a

##------------------------------------------------------------------------------##
##								HEADERS											##
##------------------------------------------------------------------------------##
HEADERS	:=	./includes/libft.h
INCLUDE :=	-I  ./includes

##------------------------------------------------------------------------------##
##								SOURCES											##
##------------------------------------------------------------------------------##
MANDATORY	:=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
				ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c		\
	   			ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
				ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c 	\
	   			ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c 	\
	   			ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c 	\
	  			ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		\
				ft_strmapi.c 	ft_striteri.c	ft_putchar_fd.c	ft_putnbr_fd.c	\
				ft_putstr_fd.c	ft_putendl_fd.c ft_tablen.c		ft_tabfree.c\
				get_next_line_utils.c get_next_line.c ft_strcmp.c

BONUS		:=	ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c \
				ft_lstdelone.c		ft_lstiter.c		ft_lstlast.c \
				ft_lstmap.c			ft_lstnew.c			ft_lstsize.c

# Src directory
SRC_DIR		:=	src/
# Subdirectories of src
SRCS_SUBDIR	:=	src/mandatory/ src/bonus/

# Full paths sources
SRCS		:= $(addprefix src/mandatory/, $(MANDATORY))
BONUS_SRCS	:= $(addprefix src/bonus/, $(BONUS))


##----------------------------------------------------------------------------------##
##								OBJECTS												##
##----------------------------------------------------------------------------------##
OBJ := $(SRCS:.c=.o)
# Objects directory
OBJ_DIR	:= obj/
# From str to obj/
OBJS := $(subst $(SRC_DIR), $(OBJ_DIR), $(OBJ))


##----------------------------------------------------------------------------------##
##							 OBJ_DIR CREATION										##
##----------------------------------------------------------------------------------##
MKDIR_P	:= mkdir -p
# Objects directory creation
NEWSUBDIR = $(MKDIR_P) $(addsuffix ;, $(subst $(SRC_DIR), $(OBJ_DIR), $(listObj)))


##------------------------------------------------------------------------------##
##									PRINT										##
##------------------------------------------------------------------------------##
ECHO	:= echo
# colors
RED		:= \033[1;31m
YEL		:= \033[1;33m
BLU		:= \033[1;34m
WHITE	:= \033[1;37m
GREEN	:= \033[1;32m
RESET	:= \033[0m


##------------------------------------------------------------------------------##
##								COMPILATION										##
##------------------------------------------------------------------------------##
CC		:= gcc
# Creation of the library
AR		:= ar rcs
# Compilation flags
CFLAGS	:= -Wall -Wextra -Werror $(INCLUDE)
# explicit compilation
$(OBJ_DIR)%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDE)  -c $< -o $@
# vpath
VPATH := $(SRC_DIR) $(OBJ_DIR) $(SRCS_SUBDIR) obj/bonus/


##------------------------------------------------------------------------------##
##									BONUS OBJECTS								##
##------------------------------------------------------------------------------##
BONUS_OBJ := $(BONUS_SRCS:.c=.o)

BONUS_OBJS := $(subst $(SRC_DIR), $(OBJ_DIR), $(BONUS_OBJ))
Objects = $(OBJS)
# By default the bonus aren't included
GOTBONUS =
# if the rules 'bonus' is called add bonus objects
ifeq ($(GOTBONUS),)
	Objects += $(BONUS_OBJS)
endif

##------------------------------------------------------------------------------##
##									MAKE RULES									##
##------------------------------------------------------------------------------##
all:	$(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ $(foreach listObj, $(SRCS_SUBDIR), $(NEWSUBDIR))

$(TARGET):	$(SRCS) $(Objects)
	@ $(ECHO) "$(GREEN)Libft compiled with success!$(RESET)"
	@ $(AR) $(TARGET) $(Objects)

addBonus:
	@ $($(GOTBONUS) += bonus)

bonus: addBonus all

clean:
	@ $(ECHO) "\n $(RED)libft removing: $(RESET) $(OBJ_DIR) $(OBJS)\n$(RESET)"
	@ rm -rf $(OBJS)
	@ rm -rf $(BONUS_OBJS)
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ $(ECHO) "\n $(RED)libft removing: $(RESET) $(TARGET)\n"
	@ rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re bonus
