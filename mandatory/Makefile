CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = server.c
SRCC = client.c minitalk_utils.c
OBJSC = client.o minitalk_utils.o
OBJSS = server.o 

all: client server

client: $(OBJSC) minitalk.h
	$(CC) $(CFLAGS) -o $@ $(OBJSC) 

server: $(OBJSS) minitalk.h
	$(CC) $(CFLAGS) -o $@ $(OBJSS) 

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJSC) $(OBJSS)

fclean: clean
	rm -rf client server
re: fclean all