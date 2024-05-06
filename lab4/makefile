#Josh Mulyadi

CFLAGS= -std=c99 -pedantic -Wformat -Wreturn-type 
all:  tags headers lab4 lab4u


headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .


# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@


lab4: lab4.o callbacks.o memory.o bits.o input.o physics.o sim.o output.o n2.o linkedlist.o reliable.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
lab4u: lab4.o callbacks.o memory.o bits.o input.o physics.o sim.o output.o n2.o linkedlist.o unreliable.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist


# Prototypes go here
p:  insert iterate any delete sort 

insert: insert.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
iterate: iterate.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
any: any.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
delete: delete.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist
sort: sort.o
	gcc -g -o $@ $^  -L. -lbtp -lncurses -lm -llinkedlist




# Zip target goes here.  
# If it doesn't self test lab2, your lab is late.

lab4.zip: makefile *.c *.h *.a n2.o unreliable.o reliable.o README_LAB4
#zip all dependicies
	zip $@ $^
#remove install directory
	rm -rf install
#create directory
	mkdir install
#try unziping the lab
	unzip lab4.zip -d install
#take making the lab
	make -C install -r lab4
#recursively remove it
	rm -rf install
