
EXE= nature2d

CC= clang

CFLAGS= 
LIBS= -llua ../lib/libnature2d.a
INCLUDES= -I ../lib

all: $(EXE)

debug: CFLAGS += -DDEBUG # -g
debug: $(EXE)

libnature2d.a:
	cd ../lib && $(MAKE) $@

$(EXE): main.c libnature2d.a
	$(CC) -o $(EXE) $(CFLAGS) $(INCLUDES) $(LIBS) main.c

clean:
	rm -rf $(EXE)
	rm -rf nature2d.dSYM
