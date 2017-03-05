# Galen Helfter
# CPSC 4160
# Makefile

SHELL = /bin/sh

CC = gcc
CFLAGS = -g -W -Wall -O0 -std=c89
CLEANFILES = *.o *.out core.*
LDFLAGS = -g -W -Wall -O0 -std=c89
LIBS = -lSDL2 -lSDL2_image -lm

OBJECTS = 	main.o \
			initialize.o \
			game_ai.o \
			image_util.o \
			renderer.o \
			Vector2.o \
			Vector3.o \
			Vector4.o \
			image_load.o

PROGS = run

all:		$(PROGS)

run:		$(OBJECTS) $(LIBS)
			$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LIBS)

main.o: initialize.h renderer.h
game_ai.o: game_ai.h
image_load.o: image_load.h
image_util.o: image_util.h
initialize.o: initialize.h renderer.h image_load.h
renderer.o: renderer.h
Vector2.o: Vector2.h
Vector3.o: Vector3.h
Vector4.o: Vector4.h

# Header dependencies
Vector2.h: Util.h
Vector3.h: Vector2.h
Vector4.h: Util.h
renderer.h: Vector2.h

.PHONY: clean
clean:
		rm -f $(PROGS) $(CLEANFILES)