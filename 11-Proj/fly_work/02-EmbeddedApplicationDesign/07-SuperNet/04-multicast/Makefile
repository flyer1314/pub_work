SRC = ${wildcard *.c}
BIN = ${patsubst %.c, %, $(SRC)}
CFLAGS = -g -Wall

all:$(BIN)

$(BIN):%:%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) .*.sw?

.PHONY:all clean

######################################################
#组播地址：
#IPV4地址分类
#A类地址：最高位0，主机号站24位，地址范围从1.0.0.1到126.255.255.254；
#B类地址：最高两位为10，主机号占16位，地址范围从128.0.0.1到191.254.255.254；
#C类地址：最高三位为110，主机号占8位，192.0.1.1~223.255.254.254
#D类地址：最高四位为1110,224.0.0.1~239.255.255.254
#E类地址保留；
#D类地址称为组播地址
#######################################################
