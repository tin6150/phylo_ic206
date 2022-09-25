all:
	#/usr/bin/g++  hello_world.cpp -Bstatic -o hello_world_gpp.a.out
	/usr/bin/g++ pointer.cpp -Bstatic -o pointer.a.out 
	./pointer.a.out
	#pgcc hello.c -Bstatic -o hello_pgi
