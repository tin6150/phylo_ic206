#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hola Mundo during class" << std::endl;
    char myVar;
    std::cout << "about to get a char input...";
    // std::cin >> myVar;

    // VScode has build in debugger, obviously
    // F5 to run
    // F9 to set breakpoint
    // many are under the run menu
    // when started writting cpp file, it detected and prompted to install C++ module, and recommended g++ !!  in Windows!  (well, may have been in WSL)
    std::cout << "back to regular scheduled book exercise\n";
    
		std::cout << "argc is the number of arguments passed when calling the program, with 0 being the program itself.  argc now is:" << argc << std::endl;
    
    for( int i=0; i<argc; i++) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    
    return 0;
}
