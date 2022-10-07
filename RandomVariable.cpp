// pasted from programming_book.pdf Appendix A

#include <cmath>
#include <ctime>
#include <iostream>
#include "RandomVariable.hpp"
RandomVariable::RandomVariable(void) {
seed = (int)time(NULL);
}
RandomVariable::RandomVariable(int x) {
seed = x;
}
double RandomVariable::exponentialRv(double lambda) {
return -log(uniformRv()) / lambda;
}
double RandomVariable::uniformRv(void) {
int hi = seed / 127773;
int lo = seed % 127773;
int test = 16807 * lo - 2836 * hi;							// really a static way to gen rnd num!!  see notes in pdf 
if (test > 0)
seed = test;
else
seed = test + 2147483647;
return (double)(seed) / (double)2147483647;
}
double RandomVariable::uniformRv(double lower, double upper) {
return 0.0;
}
