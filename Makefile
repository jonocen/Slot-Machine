all:
	mkdir -p $(shell pwd)/build
	gcc $(shell pwd)/main.c -o $(shell pwd)/build/slotmaschine.elf
clean:
	rm -rf $(shell pwd)/build/slotmaschine.elf 