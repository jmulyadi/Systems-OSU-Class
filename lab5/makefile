# lab 5 Makefile for SP 2024
# Your name goes here or you get a zero.
#Josh mulyadi

CFLAGS= -std=c99 -pedantic -Wformat -Wreturn-type 
all:  tags atest lab5

tags: *.c
	ctags -R .


#####################################################################


	
bonus: bonus.o main.s a_shim.o analyze.s m_shim.o middle.s print.o
	gcc -g -m64 -o $@ $^
	
lab5: lab5.o a_shim.o analyze.s m_shim.o middle.s print.o
	gcc -g -m64 -o $@ $^
	
atest: atest.o a_shim.o analyze.s
	gcc -g -m64 -o $@ $^
	


#####################################################################

# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c  
	gcc $(CFLAGS) -g -c $< -o $@



# Zip target goes here.  
# If it doesn't self test all of your executables, your lab is late.
	lab5.zip: makefile *.c *.s *.o README_LAB5
#zip all dependicies
	zip $@ $^
#remove install directory
	rm -rf install
#create directory
	mkdir install
#try unziping the lab
	unzip lab5.zip -d install
#take making the lab
	make -C install -r lab5
	make -C install -r atest
#recursively remove it
	rm -rf install

