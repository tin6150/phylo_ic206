#include <iostream>
using namespace std;

// week 5   2022.09.20   class discussion covered a lot of pointer, double pointer


// see ch   (p44 of programming_book.pdf)


void changeVal(int);
void changeByRef(int&);                 
void changeByPointer(int*);
void changeByDoublePointer(int**);

void changeVal(int x){
    x += 100;
    //cout << "indised changeVal, x has value " << x << endl;
    cout << " address of __x__ " << &x << " it has value of " << x  << " -- insside fn." << endl;
    //cout << "inised  fn, x has value " << x << " and address of " << &x << endl;
}

// call by reference... var is   type&     
// when involking, just pass the var name.  
// changeByRef( myVar ) ;      // don't use &myVar or *myVar 
void changeByRef(int& x){
    x += 100;
    cout << " address of __x__ " << &x << " it has value of " << x  << " -- insside fn." << endl;
    //cout << "inised changeByRef fn, x has value " << x << " and address of " << &x << endl;
}

//
void changeByPointer(int* x) {
    (*x) += 3000;
    cout << " address of __x__ " << &x << " it has value of " << x  << " -- insside fn." << endl;
}

int main(int argc, char* argv[]) {
    int myVar = 7;

    cout << "==First fn - changeVal =="  << endl;
    changeVal(myVar);
    //cout << "in main, myVar has value " << myVar << " and address "  << &myVar << endl;
    cout << " address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << endl << endl;

    cout << "==Second fn - changeByRef =="  << endl;
    changeByRef(myVar);
    //cout << "in main, myVar has value " << myVar << " and address "  << &myVar << endl;
    cout << " address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << endl << endl;


    cout << "==Third fn - changeByPointer =="  << endl;
    // this call is not what was desired!  ++FIXME
    changeByPointer(*myVar);
    cout << " address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;

}