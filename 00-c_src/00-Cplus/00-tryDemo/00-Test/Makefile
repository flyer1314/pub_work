.PHONY:clean ALL 
.IGNORE:_define5 _define6

CFLAGS= -g -Wall -O0


#
#-Wall：选项可以打印出编译时所有的错误或者警告信息。这个选项很容易被遗忘，编译的时候，没有错误或者警告提示，以为自己的程序很完美，其实，里面有可能隐藏着许多陷阱。变量没有初始化，类型不匹配，或者类型转换错误等警告提示需要重点注意，错误就隐藏在这些代码里面。没有使用的变量也需要注意，去掉无用的代码，让整个程序显得干净一点。下次写Makefile的时候，一定加-Wall编译选项。
#-O0： 表示编译时没有优化。
#-O1： 表示编译时使用默认优化。
#-O2： 表示编译时使用二级优化。
#-O3： 表示编译时使用最高级优化。
#-Os：相当于-O2.5优化，但又不所见代码尺寸

AllObj	:=hello bool ForceChange strlen sizeof strncpy t0 bitLen float define static BitCalculate t1 t2 t3 continue break switch goto _fun1 _fun2 _fun3 _fun4 _GlobalVariables0 _GlobalVariables1 _GlobalVariables2 _funPoint _pointFun _define0 _define1 _define2 _define3 _define4 _funPointArr itoa void0 void1 _ArrInit0 _ArrInit1 _ArrInit2 _ArrUse0 _define5 _define6 t4 sizeofDataType getmac pragma 
APP_TEST	:=endian fahr IntArg byteTbin

ALL:$(AllObj) $(APP_TEST)

#1
hello:hello.c
	$(CC) -o hello -g -Wall hello.c

#2
bool:bool.c
	$(CC) -o bool -g -Wall bool.c

#3
ForceChange:ForceChange.c
	$(CC) -o ForceChange -g -Wall ForceChange.c
	
#4
strlen:strlen.c
	$(CC) -o strlen -g -Wall strlen.c

#5
sizeof:sizeof.c
	$(CC) -o sizeof -g -Wall sizeof.c

#6
strncpy:strncpy.c
	$(CC) -o strncpy -g -Wall strncpy.c

#7
t0:t0.c
	$(CC) -o t0 -g -Wall t0.c

#8
bitLen:bitLen.c
	$(CC) -o bitLen -g -Wall bitLen.c

#9
float:float.c
	$(CC) -o float -g -Wall float.c

#10
define:define.c
	$(CC) -o define -g -Wall define.c

#11
static:static.c
	$(CC) -o static -g -Wall static.c

#12
BitCalculate:BitCalculate.c
	$(CC) -o BitCalculate -g -Wall BitCalculate.c

#13
t1:t1.c
	$(CC) -o t1 -g -Wall t1.c

#14
t2:t2.c
	$(CC) -o t2 -g -Wall t2.c

#15
t3:t3.c
	$(CC) -o t3 -g -Wall t3.c

#16
continue:continue.c
	$(CC) -o continue -g -Wall continue.c

#17
break:break.c
	$(CC) -o break -g -Wall break.c

#18
switch:switch.c
	$(CC) -o switch -g -Wall switch.c

#19
goto:goto.c
	$(CC) -o goto -g -Wall goto.c

#20
_fun1:_fun1.c
	$(CC) -o _fun1 -g -Wall _fun1.c

#21
_fun2:_fun2.c
	$(CC) -o _fun2 -g -Wall _fun2.c

#22
_fun3:_fun3.c
	$(CC) -o _fun3 -g -Wall _fun3.c

#23
_fun4:_fun4.c
	$(CC) -o _fun4 -g -Wall _fun4.c

#24
_GlobalVariables0:_GlobalVariables0.c
	$(CC) -o _GlobalVariables0 -g -Wall _GlobalVariables0.c

#25
_GlobalVariables1:_GlobalVariables1.c
	$(CC) -o _GlobalVariables1 -g -Wall _GlobalVariables1.c

#26
_GlobalVariables2:_GlobalVariables2.c
	$(CC) -o _GlobalVariables2 -g -Wall _GlobalVariables2.c

#27
_funPoint:_funPoint.c
	$(CC) -o _funPoint -g -Wall _funPoint.c

#28
_pointFun:_pointFun.c
	$(CC) -o _pointFun -g -Wall _pointFun.c

#29
_define0:_define0.c
	$(CC) -o _define0 -g -Wall _define0.c

#30
_define1:_define1.c
	$(CC) -o _define1 -g -Wall _define1.c

#31
_define2:_define2.c
	$(CC) -o _define2 -g -Wall _define2.c
	
#32
_define3:_define3.c
	$(CC) -o _define3 -g -Wall _define3.c

#33
_define4:_define4.c
	$(CC) -o _define4 -g -Wall _define4.c

#34
_funPointArr:_funPointArr.c
	$(CC) -o _funPointArr -g -Wall _funPointArr.c

#35
itoa:itoa.c
	$(CC) -o itoa -g -Wall itoa.c

#36
void0:void0.c
	$(CC) -o void0 -g -Wall void0.c

#37
void1:void1.c
	$(CC) -o void1 -g -Wall void1.c

#38
_ArrInit0:_ArrInit0.c
	$(CC) -o _ArrInit0 -g -Wall _ArrInit0.c

#39
_ArrInit1:_ArrInit1.c
	$(CC) -o _ArrInit1 -g -Wall _ArrInit1.c

#40
_ArrInit2:_ArrInit2.c
	$(CC) -o _ArrInit2 $(CFLAGS)  _ArrInit2.c

#41
_ArrUse0:_ArrUse0.c
	$(CC) -o  _ArrUse0  $(CFLAGS)  _ArrUse0.c

#42
_define5:_define5.c
	@echo "The file (_define5.c) will not be compiled !"

#43
_define6:_define6.c
	@echo "The file (_define6.c) will not be compiled !"

#44
t4:t4.c
	$(CC) -o t4 $(CFLAGS) t4.c -Wl,-Map,t4.map

#45
sizeofDataType:sizeofDataType.c
	$(CC) -o sizeofDataType sizeofDataType.c $(CFLAGS)

#46
getmac:getmac.c

#47
pragma:pragma.c

#48--------(2017/01/03--22:00)
endian:
	$(CC) -o endian 01-endian.c $(CFLAGS)

#49--------
fahr:
	$(CC) -o fahr 02-fahr.c $(CFLAGS)

#50
IntArg:
	$(CC) -o IntArg 03-IntArg.c $(CFLAGS)

#51
byteTbin:
	$(CC) -o byteTbin 04-byteTbin.c $(CFLAGS)


LIB:
	make -C ./library/dynamicLib main
	make -C ./library/staticLib main

#update current dir the name list of FILES
# 按修改时间的先后顺序列出文件名
list:
	ls -alt > FILES
#	cat FILES
	ls -at

# 删除所有新生成的文件，并进入特定目录下执行MakeFile的clean目标
clean:
	$(RM) a.out  $(AllObj) t4.map *.o $(APP_TEST)
	make -C ./library/dynamicLib clean
	make -C ./library/staticLib clean

#备份Makefile
DATE = $(shell date)
backup:
	cp Makefile Makefile.bak
	@echo "Backup Makefile succeed $(DATE)"
	
