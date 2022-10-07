# INC_DIR = ../StdCUtil
INC_DIR = .
CFLAGS=-c -Wall -I$(INC_DIR)
# CPPFLAGS = -std=c++14 -g -Wall -pedantic
# DEPS = split.h
CXX = g++
CXXFLAGS = -g    -Wall -I$(INC_DIR) -L$(INC_DIR)
LIBS = -lm
# CXXFLAGS = -g -c -Wall -I$(INC_DIR) -L$(INC_DIR)
# RM = rm
# default to rm -f, the nice thing about -f is that it doesn't whine if file has already been removed

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -c     - compile .o but dont link em
#  -Wall  - this flag is used to turn on most compiler warnings

# https://www.tutorialspoint.com/makefile/makefile_quick_guide.htm
# $@ is the name of the file to be made.
# $? is the names of the changed dependents.
# $< the name of the related file that caused the action.
# $* the prefix shared by target and dependent files.


## think really just need to run 
## g++ Sn_RndVarMain.cpp RandomVariable.cpp -o Sn_RndVarMain 
all: 
	g++ Sn_RndVarMain.cpp RandomVariable.cpp -o Sn_RndVarMain 

# review those below later to see what borked with the generalization process

 
# The build target 
# TARGET = ch6
# TARGET = Sn_RndVarMain.exe
TARGET = Sn_RndVarMain
OBJS = Sn_RndVarMain.o RandomVariable.o

Stil_no_all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o $@ ${OBJS} ${LIBS} 

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

bad_all: Sn_RndVarMain.out
	$(CXX) $(CXXFLAGS) -Wall Sn_RndVarMain.o RandomVariable.o -o Sn_RndVarMain.out -lm
	
 
generic_all: $(TARGET)
 
$(TARGET).o: $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) 
 
clean:
	# $(RM) $(TARGET)
	$(RM) $(TARGET) *.o



xxSn_RndVarMain.exe: Sn_RndVarMain.o RandomVariable.o
	${CPP} ${CPPFLAGS} ${INC} -o $@.ex $^

xxSn_RndVarMain.o: Sn_RndVarMain.cpp RandomVariable.hpp
	${CPP} -c ${CPPFLAGS} ${INC} $< -o $@

xxRandomVariable.o: RandomVariable.hpp


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



