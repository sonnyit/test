CC = g++
CFLAGS = -std=c++11 -Wall -g

SRCS = 

OBJS = $(SRCS:.c=.o)

MAIN = exec

all: $(MAIN)
	@echo compile completed!

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)