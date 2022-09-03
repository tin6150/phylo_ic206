all:
	#pgcc hello.c -Bstatic -o hello_pgi
	# /usr/bin/g++  hello_world.cpp -Bstatic -o hello_world_gpp.a.out
	/usr/bin/g++  prog_ch4.cpp    -Bstatic -o prog_ch4.a.out && ./prog_ch4.a.out
