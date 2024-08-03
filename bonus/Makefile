CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = server_bonus.c
SRCC = client_bonus.c minitalk_utils_bonus.c
OBJSC = client_bonus.o minitalk_utils_bonus.o
OBJSS = server_bonus.o minitalk_utils_bonus.o

all: client_bonus server_bonus

client_bonus: $(OBJSC) minitalk_bonus.h
	$(CC) $(CFLAGS) -o $@ $(OBJSC) 

server_bonus: $(OBJSS) minitalk_bonus.h
	$(CC) $(CFLAGS) -o $@ $(OBJSS) 

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJSC) $(OBJSS)

fclean: clean
	rm -rf client_bonus server_bonus
re: fclean all