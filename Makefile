CC = gcc
CFLAGS = -lglfw -lGL -lGLEW -lGLU
gltest:*.c
	$(CC) $^ $(CFLAGS) -o $@
.PHONY:clean
clean:
	rm -rf *.out *.o gltest