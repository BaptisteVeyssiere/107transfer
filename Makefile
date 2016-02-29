##
## Makefile for 107transfer in /home/VEYSSI_B/rendu/Maths/107transfer
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Mon Feb 29 15:55:18 2016 Baptiste veyssiere
## Last update Mon Feb 29 16:04:11 2016 nathan scutari
##

NAME	= 107transfer

SRCS	= src/107transfer.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CC	= gcc

LDFLAGS	= -lm

CFLAGS	= -I./include

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
