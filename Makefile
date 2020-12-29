CCX=gcc

CXXFLAGS= -g

OBJS =  main.c
all: ${OBJS}
	$(CCX) $(CXXFLAGS) -o todo $(OBJS)

