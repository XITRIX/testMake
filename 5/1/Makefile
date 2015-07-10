NAME = signal
REQUEST = -lpthread

all: $(NAME)
$(NAME): $(NAME).o
	gcc $(NAME).o $(REQUEST) -o run.a
$(NAME).o: $(NAME).c
	gcc $(NAME).c $(REQUEST) -c -o $(NAME).o
