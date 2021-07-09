
EXE = nature2d

CC = clang

CFLAGS = 
LIBS = -llua

all: $(EXE)

debug: CFLAGS += -DDEBUG -g
debug: $(EXE)

$(EXE): main.c
	$(CC) -o $(EXE) $(CFLAGS) $(LIBS) ../lib/external/open-simplex-noise.c main.c


clean:
	rm -rf $(EXE)
	rm -rf nature2d.dSYM
