# ch6  RandomVariable
all:
	#/usr/bin/g++ RandomVariable.cpp -Bstatic -o RandomVariable.o
	/usr/bin/g++ Sn_RndVarMain.cpp  -Bstatic -o Sn_RndVarMain.exe


ch5:
	/usr/bin/g++ pointer.cpp -Bstatic -o pointer.a.out 
	./pointer.a.out

ch4:
	/usr/bin/g++  prog_ch4.cpp    -Bstatic -o prog_ch4.a.out && ./prog_ch4.a.out

completed:
	/usr/bin/g++  hello_world.cpp -Bstatic -o hello_world_gpp.a.out



ref-only:
	pgcc hello.c -Bstatic -o hello_pgi
