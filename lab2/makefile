# Sample lab 2 Makefile for SP 2024
# Josh Mulyadi

CFLAGS= -std=c99 -pedantic -Wformat -Wreturn-type 
all:  tags headers lab2

  

headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .


# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@


lab2: lab2.o bits.o input.o physics.o output.o n2.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm


# Prototypes go here
prototype1: prototype1.o
	gcc -g -o $@ $^ -L. -lm -lbtp -lncurses
prototype2: prototype2.o
	gcc -g -o $@ $^ -L. -lm -lbtp -lncurses
prototype3: prototype3.o
	gcc -g -o $@ $^ -L. -lm -lbtp -lncurses
prototype4: prototype4.o
	gcc -g -o $@ $^ -L. -lm -lbtp -lncurses
bitMinip: bitMinip.o
	gcc -g -o $@ $^ -L. -lm -lbtp -lncurses


# Zip target goes here.  
# If it doesn't self test lab2, your lab is late.
lab2.zip: makefile *.c *.h *.a n2.o README_LAB2
#zip all dependicies
	zip $@ $^
#create directory
	mkdir install
#try unziping the lab
	unzip lab2.zip -d install
#take making the lab
	make -C install -r lab2
#recursively remove it
	rm -rf install

