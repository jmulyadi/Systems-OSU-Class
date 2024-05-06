
# lab 5 Makefile for SP 2024
# Your name goes here or you get a zero.
#Josh Mulyadi

CFLAGS= -std=c99 -pedantic -Wformat -Wreturn-type 
all:  tags headers ops_test lab6

tags: *.c
	ctags -R .

headers: *.c tags
	headers.sh

#####################################################################

	
bonus: bonus.o s_shim.o d_shim.o print.o search.s do_op.s ops.s
	gcc -g -m64 -o $@ $^
	
lab6: lab6.o d_shim.o print.o do_op.s ops.s
	gcc -g -m64 -o $@ $^
	
ops_test: ops_test.o o_shim.o ops.s
	gcc -g -m64 -o $@ $^
	


#####################################################################

# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@



# Zip target goes here.  
# If it doesn't self test all of your executables, your lab is late.
lab6.zip: makefile *.h *.c *.s d_shim.o o_shim.o s_shim.o print.o o_shim.o README_LAB6
#zip all dependicies
	zip $@ $^
#remove install directory
	rm -rf install
#create directory
	mkdir install
#try unziping the lab
	unzip lab6.zip -d install
#take making the lab
	make -C install -r lab6
	make -C install -r ops_test
#recursively remove it
	rm -rf install

