#Josh Mulyadi
#YOU MUST HAVE YOUR NAME IN YOUR MAKEFILE!

#Makefile for performance HW.  


# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

#CFLAGS = -g -std=c99 -pedantic -Wformat -Wreturn-type
#CFLAGS = -O -std=c99 -pedantic -Wformat -Wreturn-type
CFLAGS = -Ofast -std=c99 -pedantic -Wformat -Wreturn-type

all: py3 py4 perf.zip

py3: py3.c n2.o makefile
	gcc $(CFLAGS)  $< n2.o  -o $@ -lm

py4: py4.c n2.o makefile
	gcc $(CFLAGS)  $< n2.o  -o $@ -lm

perf.zip: makefile py3.c py4.c n2.*
	zip $@ $^
	rm -rf install
	unzip $@ -d install
	make -C install py3
	make -C install py4
	rm -rf install



#this entry stays for C code labs
tags: *.c
	ctags -R .

# this entry stays for C code labs
headers: *.c tags
	headers.sh


# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h


