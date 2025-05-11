CC = gcc
CFLAGS = -lm -lglfw -lGL -lGLEW -lGLU
gltest:*.c
	$(CC) $^ $(CFLAGS) -o $@
.PHONY:clean git run
clean:
	rm -rf *.out *.o gltest

git:
	git add .
	git commit -m "Learn GL"
	git status
run:
	./gltest
