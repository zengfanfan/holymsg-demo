
all: cplib publisher subscriber

cplib:
	@-cp -f libholymsg.so /lib
	@-cp -f libholymsg.so /usr/lib
	@-cp -f libholymsg.so /lib64
	@-cp -f libholymsg.so /usr/lib64

publisher: publisher.o
	gcc -o $@ $^ -lholymsg

subscriber: subscriber.o
	gcc -o $@ $^ -lholymsg

clean:
	rm -f publisher subscriber *.o