# Copyright 2024 Neil Kirby
# If you edit it, put your name here and next to your edits.
#Josh Mulyadi

CFLAGS= -std=c99 -pedantic -Wformat -Wreturn-type 
all:  tags headers lab3


headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .


# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@

#changed this
lab3: lab3.o bits.o input.o physics.o output.o n2.o sim.o callback.o memory.c
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist


# Prototypes go here
#call to make all prototypes
#added all below here
p: structHelp insert colorBit delete mem

structHelp: structHelp.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
insert: insert.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
colorBit: colorBit.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
delete: delete.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
mem: mem.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist



# Zip target goes here.  
# If it doesn't self test lab2, your lab is late.

lab3.zip: makefile *.c *.h *.a n2.o README_LAB3
#zip all dependicies
	zip $@ $^
#create directory
	mkdir install
#try unziping the lab
	unzip lab3.zip -d install
#take making the lab
	make -C install -r lab3
#recursively remove it
	rm -rf install
