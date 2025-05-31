CC = gcc
CFLAGS = -lm -lglfw -lGL -lGLEW -lGLU -lstb
gltest:*.c
	$(CC) $^ $(CFLAGS) -o $@
.PHONY:clean git run move backup
clean:
	@rm -rf *.out *.o gltest

git:
	git add ..
	git commit -m "Learn GL"
	git status
run:
	@./gltest
move:
	cp -r /root/sd/code/learngl/* ./..
backup:
	cp -r ./../*  /root/sd/code/learngl/