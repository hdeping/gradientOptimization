CC = gcc -g -lm
option = -o exe
object = main.o
source = main.c
run:$(object)
	$(CC) $(object) $(option)
	./exe
2:
	gcc -O2 main.c -o exe
	./exe
g:
	$(CC) $(source)
	gdb exe
p:
	gnuplot pic.sh
	gspng
	crop_png pic.png
	rm pic.png
	eog newpic.png
clean:
	rm exe $(object)

