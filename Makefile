CC=gcc
CFLAGS=-Wall -Wextra -g

all: clean build

default: build

build: server client

server: server.o common.o \
		server-queues.o \
		server-receiver.o \
		server-writer.o \
		server-sender.o

client: client.o common.o \
		client-queues.o \
		client-reader.o \
		client-sender.o \
		client-receiver.o

clean:
	rm -f server client output.txt project2.zip *.o

zip: 
	zip project2.zip server.c client.c utils.h Makefile README
