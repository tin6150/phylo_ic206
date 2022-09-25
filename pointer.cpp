#include <iostream>
using namespace std;

// week 5   2022.09.20   class discussion covered a lot of pointer, double pointer


// see ch   (p44 of programming_book.pdf)


// in practice, these prototype should go to .hpp and 
// should have var names in there also, to help remember what params are needed
void changeVal(int);
void changeByPointer(int*);             // avoid
void incrementByPointer(int* x);        // unable to read var by pointer?  
void changeByRef(int&);                 // good to use.  p39
void changeByDoublePointer(int**);

void changeVal(int x){
    x += 100;
    //cout << "indised changeVal, x has value " << x << endl;
    cout << "  address of __x__ " << &x << " it has value of " << x  << " -- insside fn." << endl;
    //cout << "inised  fn, x has value " << x << " and address of " << &x << endl;
}

// this was the intermediary step in the book
void changeByPointer(int* x) {
    (*x)  = 2000;       // book used this, likely it can set, but not read?
    // (*x) += 2000;
    cout << "  address of __x__ " << &x << " it has value of " << x  << " -- insside fn." << endl;
}
void incrementByPointer(int* x) {
    //(*x)  = 2000;       // book used this, likely it can set, but not read?   or did i do something wrong?
    (*x) += 2200;
    cout << "  address of __x__ " << &x << " it has value of " << x  << " -- insside fn.  (probably can't read var correctly)" << endl;
}


// call by reference... var is   type&     
// when involking, just pass the var name.  
// changeByRef( myVar ) ;      // don't use &myVar or *myVar 
// so this should work well in the OO mindset, just need & in the fn interface definition.
void changeByRef(int& x){
    x += 100;
    cout << "  address of __x__ " << &x << " it has value of " << x  << " -- insside fn." << endl;
    //cout << "inised changeByRef fn, x has value " << x << " and address of " << &x << endl;
}



int main(int argc, char* argv[]) {
    int myVar = 7;

    cout << "==First fn - changeVal =="  << endl;
    changeVal(myVar);
    //cout << "in main, myVar has value " << myVar << " and address "  << &myVar << endl;
    cout << "  address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << "  >> ie, fn call change to var not effected cuz of scoping rule, which is why need address of vars.";
    cout << endl << endl;
    
    // play with this more... seems to not work when i try to increment first...
    cout << "==Intermediary fn - incrementByPointer =="  << endl;
    incrementByPointer(&myVar);
    cout << " address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << " >> can the by pointer read var?  or did i do something wrong?" ;
    cout << endl << endl;


    cout << "==Intermediary fn - changeByPointer =="  << endl;
    // this call is not what was desired!  ++FIXME
    // see ch 5 p38 of programming_book.pdf
    changeByPointer(&myVar);
    cout << " address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << " >> may have some pointer stuff messed up, not a good way to do things i don't think" ;
    cout << endl << endl;

    // ch 5 p39 of programming_book.pdf
    cout << "==Second fn - changeByRef ++ good to use.  p39 ch5 =="  << endl;
    changeByRef(myVar);
    //cout << "in main, myVar has value " << myVar << " and address "  << &myVar << endl;
    cout << " address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << endl << endl;


}