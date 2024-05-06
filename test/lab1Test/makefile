#Josh Mulyadi
#YOU MUST HAVE YOUR NAME IN YOUR MAKEFILE!
# (you have to have your name in every hand-edited file you turn in)



#set our compiler flags once and forever
CFLAGS= -std=c99 -pedantic -Wformat -Wreturn-type 

#Makefile for lab 1-4.  You need to add you name to this file in the comments
# You will need to add a entry to create your zip file

#change the last dependency for each new lab
all:  tags headers lab1 zd

# This entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files
# THis IS the rule that does linking.  Each lab will have a different set
# of .o files for dependency lists.  THe labs may also have libraries added 
# to the end.
# The core rule you see here will be the same for all C labs.

lab1: lab1.o 
	gcc -g -o $@ $^ 

zd: zd.o
	gcc -g -o $@ $^ 

stuff: makefile
	date > stuff
	ls -lt >> stuff
#this is where you create an entry to build yuour zip file
#it will also update with new labs
lab1.zip: makefile *.c *.h *.awk *.sh README_LAB1
	zip $@ $^
	rm -rf install
	mkdir install
	unzip lab1.zip -d install
#ERRORS BELOW HERE
	make -C install -r lab1
	make -C install -r zd
	make -C install -r tags
	make -C install -r headers
	make -C install -r stuff

#BUILD ERRORS ABOVE HERE
	rm -rf install

#this entry stays for C code labs
tags: *.c
	ctags -R .

# this entry stays for C code labs
headers: *.c tags
	headers.sh


# this entry takes care of C files depending on header files
# It has the flags for compiling the c code that we set at the top
# We leave -g here because it might change, but our basic compiler
# flags will always be the ones we set at the top.
# We will always have -c here, because we turn .c into .o with this rule.
# THIS RULE DOES NOT (AND SHOULD NOT) DO LINKING!

%.o:%.c *.h
	gcc $(CFLAGS)  -g -c $< -o $@


