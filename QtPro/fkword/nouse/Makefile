TARGET = FKWord
SRCS = $(wildcard *.cpp) 
OBJS = $(SRCS:.cpp = .o)
CC = g++
INCLUDES = -I./
LIBS = -L./ -lpthread


# For C++ Language
CPPFLAGS = -Wall -Wextra -Wconversion -Wfloat-equal -Wpointer-arith \
           -Wframe-larger-than=10240 -Wno-unused-parameter \
           -Wunreachable-code -Wshadow -Winit-self -Wswitch-default \
           -Wswitch-enum -Waggregate-return -Wredundant-decls \
           -Wcast-align -Wlogical-op -Wformat-security \
           -Wnormalized=nfc \
           -fstrict-overflow -Wstrict-overflow \
           -funsafe-loop-optimizations -Wunsafe-loop-optimizations

CPPFLAGS += -g -Wall -O0 --verbose
CPPFLAGS += -std=c++11 -std=gnu++11

all:FKWord
.PHONY:FKWord
.PHONY:clean

$(TARGET) : $(OBJS)
	make clean
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS)

%.o : %.c
	$(CC) -c $< $(CPPFLAGS)

clean:
	rm *.o $(TARGET) -rf