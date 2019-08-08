# Makefile

prog=prog

obj=main.o matrix.o

all : $(prog)

CC=gcc
CFLAGS= -Iinclude -O3 -Wall

# TODO: add a tool for detecting SIMD instructions set at compile time
MCPU= -mavx -mavx2 -mfma

ASFLAGS= -Iinclude

LD=ld
LDFLAGS= -dynamic-linker /lib64/ld-linux-x86-64.so.2
LDLIB= -lc


%.o : %.S
	$(CC) -c $(ASFLAGS) $(MCPU) $(VECTORFLAGS) -o $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $(MCPU) $(VECTORFLAGS) -o $@ $^

$(prog) : $(obj)
	$(LD) $(LDFLAGS) -o $(prog) $(obj) $(LDLIB)

clean :
	rm -rf $(prog) $(obj)
	@rm -rf .*~ *~
	@cd include && rm -rf .*~ *~ && cd ..

