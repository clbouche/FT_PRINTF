# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 13:42:55 by clbouche          #+#    #+#              #
#    Updated: 2020/02/18 13:04:29 by clbouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########
# NAME #
########

NAME = libftprintf.a

###################
# FLAGS & LIBRARY #
###################

CC = gcc

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra

############
# Includes #
############

INCLUDES_PRINTF = includes/
I_INCLUDES += -I $(INCLUDES_PRINTF)

INCLUDES_LIBFT = libft/
I_LIB_INCLUDES += -I $(INCLUDES_LIBFT)

DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

###########
# Headers #
###########

HEADER += ft_printf.h 

vpath %.h $(INCLUDES_PRINTF)

########################
# Sources compilations #
########################

PATH_SRCS = srcs

SRCS += ft_printf.c
SRCS += utils_conv.c
SRCS += utils_flags.c 
SRCS += form_char.c 
SRCS += form_string.c 
SRCS += form_int.c 
SRCS += form_address.c 
SRCS += form_hexa.c 
SRCS += form_unsigned.c 
SRCS += form_unsigned_hexa.c 
SRCS += form_percent.c 

vpath %.c $(PATH_SRCS)

########################
# Objects compilations #
########################

PATH_OBJS = objs/
OBJS = $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

#########
# RULES #
#########

all: $(PATH_OBJS) $(NAME) 

$(NAME): $(OBJS) 
		make -C $(DIR_LIB)
		cp $(LIB) ./$(NAME)
		ar rcs $(NAME) $(OBJS)

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(I_LIB_INCLUDES) $(I_INCLUDES) -c $< -o $@

$(PATH_OBJS):
	mkdir $@

clean:
	$(RM) $(OBJS)
	$(RM) -R $(PATH_OBJS)
	make clean -C $(DIR_LIB)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(DIR_LIB)

re: fclean all

.PHONY : all clean fclean re