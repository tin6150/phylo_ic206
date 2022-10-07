# INC_DIR = ../StdCUtil
INC_DIR = .
CFLAGS=-c -Wall -I$(INC_DIR)
# CPPFLAGS = -std=c++14 -g -Wall -pedantic
# DEPS = split.h
CXX = g++
CXXFLAGS = -g -c -Wall -I$(INC_DIR)
# RM = rm
# default to rm -f, the nice thing about -f is that it doesn't whine if file has already been removed

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -c     - compile .o but dont link em
#  -Wall  - this flag is used to turn on most compiler warnings
 
# The build target 
# TARGET = ch6
# TARGET = Sn_RndVarMain.exe
TARGET = Sn_RndVarMain
 
all: $(TARGET)
 
$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp
 
clean:
	$(RM) $(TARGET)



Sn_RndVarMain.exe: Sn_RndVarMain.o RandomVariable.o
	${CPP} ${CPPFLAGS} ${INC} -o $@.ex $^

Sn_RndVarMain.o: Sn_RndVarMain.cpp RandomVariable.hpp
	${CPP} -c ${CPPFLAGS} ${INC} $< -o $@

RandomVariable.o: RandomVariable.hpp


# ch6  RandomVariable
old_all:
	#-- /usr/bin/g++ RandomVariable.cpp  -Bstatic -o RandomVariable.o
	/usr/bin/g++ Sn_RndVarMain.cpp -L. -Bstatic -o Sn_RndVarMain.exe

#%.o: %.cpp $(DEPS)
#	$(CXX) -o $@ $< $(CXXFLAGS)


ch5:
	/usr/bin/g++ pointer.cpp -Bstatic -o pointer.a.out 
	./pointer.a.out

ch4:
	/usr/bin/g++  prog_ch4.cpp    -Bstatic -o prog_ch4.a.out && ./prog_ch4.a.out

completed:
	/usr/bin/g++  hello_world.cpp -Bstatic -o hello_world_gpp.a.out



ref-only:
	pgcc hello.c -Bstatic -o hello_pgi



