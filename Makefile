CCX=gcc

CXXFLAGS= -ggdb -fno-stack-protector

OBJS =  main.c
all: ${OBJS}
	$(CCX) $(CXXFLAGS) -o todo $(OBJS)

