SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) a.out $(BIN) *.*.sw?

.PHONY:all clean

#01-pipe.c
#02-fifo_write.c
#03-fifo_read.c
#04-kill_raise.c
#05-alarm_pause.c
#06-signal.c
#07-sigaction.c
