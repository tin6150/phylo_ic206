#include <iostream>
#include <iomanip>	// std::setprecision()

// ch 4 of programming_book.pdf
// variables, pointers

int main_ch4(int argc, char* argv[]) {
	// p 26 of programming_book.pdf	
	// back to vim, VScode last time caused huge slowlown on TSS
	std::cout << "Hola ch4" << std::endl;
	unsigned int  	myUnsignedInt 	= 7;	// 4 bytes
	float		myFloat 	= 0.1;	// 4 bytes
	double		myDouble 	= 0.1;	// 8 bytes
	bool		myBool = true; 		// 1 byte, true,false, all lower case

	// ch 4.2 p 26
	int		x = 0;
	std::cout << "x's value 	= " <<  x		<< std::endl;
	std::cout << "x's address 	= " << &x		<< std::endl;
	std::cout << "x's size  	= " << sizeof(int) 	<< std::endl;

	// p 28
	std::cout << std::fixed << std::setprecision(50) << "myFloat  = " 	<< myFloat	<< std::endl;
	std::cout << std::fixed << std::setprecision(50) << "myDouble = " 	<< myDouble	<< std::endl;

	// ch 4.4 p 29 ptr of ptr?
	    	x 	= 0;
	int* 	xPtr 	= &x;	// & = address of 
	std::cout << "x's value       	= " <<  x		<< std::endl;
	std::cout << "x's address     	= " << &x		<< std::endl;
	std::cout << "xPtr's value    	= " <<  xPtr		<< std::endl;
	std::cout << "&xPtr's address 	= " << &xPtr		<< std::endl;
	std::cout << "int size   	= " << sizeof(int) 	<< std::endl;
	std::cout << "int* size  	= " << sizeof(int*) 	<< std::endl;	// pointer size is 8 bytes
	std::cout << "char* size  	= " << sizeof(char*) 	<< std::endl;	// pointer size is 8 bytes

	// ch 4.5 p 31 dereferencing 
	*xPtr 	= 3;
	std::cout << "dereferencing, *varname, despite prefer declare pointer as type*, this is why i hate C++\n"; 
	std::cout << "x's value       	= " <<  x		<< std::endl;
	std::cout << "x's address     	= " << &x		<< std::endl;
	std::cout << "xPtr's value    	= " <<  xPtr		<< std::endl;

	// ch 4.6 p 32
	int	a[10];		// array of 10 int
	int* 	aPtr[10];	// array of 10 int* (ie 10 pointers of type int)
	double	y[1000];	
	printf( "cout is actually painful\n" );
	for( int i=0; i<10; i++ ) 
		a[i] = i;
	for( int i=0; i<10; i++ ) 
		//std::cout << "a[" 	<< i 	<< "] = " 	<< a[i]		<< std::endl;
		std::cout << "a[" 	<< i 	<< "] = " 	<< a[i]		<< " @addr: " 	<< &a[i]	<< std::endl;

	std::cout << "ch 4.6 p 34 -- C++ use new / delete [] instead of malloc()\n" ;
	int* 	b       = NULL;
	int 	numInts = 0;
	std::cout << "How many ints: ";
	std::cin  >> numInts;			// reading input from console
	if( numInts <= 0 ) {
		std::cout << "Too few ints!\n"; 
		exit( 1 );
	} else {
		b = new int[numInts]; 	// eg b = new int[10000] , array of specified number of elements
	}

	for( int i=0; i<numInts; i++ ) {
		b[i] = i * 10;
		std::cout << "b[" 	<< i 	<< "] = " 	<< b[i]		<< " @addr: " 	<< &b[i]	<< std::endl;
	}
	delete [] b;	// clear out memory allocation.
		

	return 0;
}

int main_ch3(int argc, char* argv[]) {
    std::cout << "Hola Mundo, ch3 code" << std::endl;
    // std::cin >> myVar;

    // VScode has build in debugger, obviously
    // F5 to run
    // F9 to set breakpoint
    // many are under the run menu
    // when started writting cpp file, it detected and prompted to install C++ module, and recommended g++ !!  in Windows!  (well, may have been in WSL)
    std::cout << "back to regular scheduled book exercise\n";
    
    std::cout << "argc is the number of arguments passed when calling the program, with 0 being the program itself.  argc now is:" << argc << std::endl;
    
    std::cout << "c/c++ array index starts at 0\n"; 
    for( int i=0; i<argc; i++) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
    
    return 0;
}



int main(int argc, char* argv[]) {
	//return main_ch3( argc, argv );
	return main_ch4( argc, argv );
}
