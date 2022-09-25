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
    cout << "  address of __x__ " << &x << " it has value of  IN: " << x  << " -- insside fn." << endl;
    x += 100;
    //cout << "indised changeVal, x has value " << x << endl;
    cout << "  address of __x__ " << &x << " it has value of OUT:" << x  << " -- insside fn." << endl;
    //cout << "inised  fn, x has value " << x << " and address of " << &x << endl;
}

// this was the intermediary step in the book
// p 38 ch 4
// the pointer notation need losts of * in many places to get it right, 
// which is why I want to avoid!
void changeByPointer(int* x) {
    cout << "  address of __x__ " << &x << " it has value of  IN: " << x  << " -- insside fn." << endl;
    cout << "  Ptr from   _*x__ " << *x << " it has value of  IN: " << *x  << " -- insside fn." << endl;
    (*x)  = 2000;       // book used this p 38
    // (*x) += 2000;
    cout << "  address of __x__ " << &x << " it has value of OUT: " << x  << " -- insside fn." << endl;
    cout << "  Ptr from   _*x__ " << *x << " it has value of OUT: " << *x  << " -- insside fn." << endl;
}
void incrementByPointer(int* x) {
    cout << "  address of __x__ " << &x << " it has value of  IN: " << x  << " -- insside fn." << endl;
    cout << "  Ptr from   _*x__ " << *x << " it has value of  IN: " << *x  << " -- insside fn." << endl;
    //(*x)  = 2000;       // book used this, can read/set if use right notation of *x
    (*x) += 2200;
    cout << "  address of __x__ " << &x << " it has value of OUT: " << x  << " -- insside fn. " << endl;
    cout << "  Ptr from   _*x__ " << *x << " it has value of OUT: " << *x  << " -- insside fn." << endl;
}

// double pointer thing done in class.... thought it was with array...
//void incrementByDoublePointer(int** x) {
void incrementByDoublePointer(int* x) {      // not working, this set for now so it compiles... ++FIXME++
    cout << "  address of __x__ " << &x << " it has value of  IN: " << x  << " -- insside fn." << endl;
    cout << "  Ptr from   _*x__ " << *x << " it has value of  IN: " << *x  << " -- insside fn." << endl;
    //cout << "  Ptr from   **x__ " << **x << " it has value of  IN: " << **x  << " -- insside fn." << endl;
    //(**x) += 30;
    cout << "  address of __x__ " << &x << " it has value of OUT: " << x  << " -- insside fn. " << endl;
    cout << "  Ptr from   _*x__ " << *x << " it has value of OUT: " << *x  << " -- insside fn." << endl;
    //cout << "  Ptr from   **x__ " << **x << " it has value of  IN: " << **x  << " -- insside fn." << endl;
}

// double pointer eg
// this is the code that was done in class as part of main
// https://photos.google.com/u/2/photo/AF1QipPCjsGHsZXFRobudUI-ec64qV35fiPAlzl4ryDH
void standAloneDoublePointerEg(void) {
    int** x = new int*[5];
    cout << "  address of __x__ " << &x << " it has value of OUT: " << x  << " -- insside fn. " << endl;
    for( int i=0; i<5; i++) {
        x[i] = NULL;
        //XX &(x[i]) = i;
        //XX (*x)[i] = i;
        cout << "  index   of __i__ " << i << " x[i] has value of : " << x[i]  << " address of _&x[i]_ " << &x[i] << " -- insside fn. " << endl;
    }

    cout << " part 2 using ** p as declaration, but actual var is *p... i so much hate the brain overtaxing of pointers!" << endl ;

    int** p = x;
    for( int i=0; i<5; i++) {
        //x[i] = NULL;
        cout << "  index   of __i__ " << i << " (*p) has value of : " << (*p)  << " address of _&(*p)_ " << &(*p) << " -- insside fn. " << endl;
        (*p)++;
    }



}


// ================== preferred ======================
// p 39 ch 4
// call by reference... var is   type&     
// when involking, just pass the var name.  
// changeByRef( myVar ) ;      // don't use &myVar or *myVar  when using the variable.
// so this should work well in the OO mindset, just need & in the fn interface definition.
void changeByRef(int& x){
    cout << "  address of __x__ " << &x << " it has value of  IN: " << x  << " -- insside fn." << endl;
    x += 5000;
    cout << "  address of __x__ " << &x << " it has value of OUT: " << x  << " -- insside fn." << endl;
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
    cout << "  address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << "  >> the pointer read var if it use the right notation.  so be very careful!";
    cout << endl << endl;


    cout << "==Intermediary fn - changeByPointer =="  << endl;
    // this call is not what was desired!  ++FIXME
    // see ch 5 p38 of programming_book.pdf
    changeByPointer(&myVar);
    cout << "  address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << endl << endl;

    // ch 5 p39 of programming_book.pdf
    cout << "==Second fn - changeByRef ++ good to use.  p39 ch5 =="  << endl;
    changeByRef(myVar);
    //cout << "in main, myVar has value " << myVar << " and address "  << &myVar << endl;
    cout << "  address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    cout << "  >> preferred way.  ie call by reference.  p 39 ch 5";
    cout << endl << endl;

    // double pointer thing done in class
    // not sure on syntax on  how to call it
    cout << "==Double Pointer thing done in class 5-1 =="  << endl;
    standAloneDoublePointerEg(); 
    cout << "  address of myVar " << &myVar << " it has value of " << myVar  << " -- main." << endl;
    //cout << "==Double Pointer thing as fn call, haven't gotten it to work yet =="  << endl;
    //incrementByDoublePointer(&myVar); 

}