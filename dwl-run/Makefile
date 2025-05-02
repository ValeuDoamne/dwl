.PHONY: all install uninstall clean

all: compile

install: compile
	cp ./dwl-run /usr/local/bin/

compile:
	${CC} -o dwl-run main.c

uninstall:
	rm -rf /usr/local/bin/dwl-run

clean:
	rm -rf dwl-run
