CCX = g++
CFLAGS = -std=c++11 -Wall -g

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = exec

all: $(MAIN)
	@echo compile completed!

$(MAIN): $(OBJS)
	$(CCX) $(CFLAGS) -o $(MAIN) $(OBJS)

.cpp.o:
	$(CCX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
