NAME = 1

all: $(NAME)
$(NAME): $(NAME).o
	gcc $(NAME).o -o run.a
$(NAME).o: ./$(NAME).c
	gcc ./$(NAME).c -c -o $(NAME).o
