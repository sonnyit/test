CC = g++
CFLAGS = -std=c++11 -Wall -g

SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)

MAIN = exec

all: $(MAIN)
	@echo compile completed!

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
