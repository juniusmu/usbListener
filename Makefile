app: main.o
	gcc -L/usr/local/Cellar/libusb/1.0.22/lib  main.o -o app -lusb-1.0

main.o: main.c
	gcc -c main.c

clean:
	rm *.o app
