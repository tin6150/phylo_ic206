// pasted from programming_book.pdf Appendix A

#include <iomanip>
#include <iostream>
#include "RandomVariable.hpp"
int main(int argc, const char * argv[]) {
// instantiate the RandomVariable class
RandomVariable rv;
/* Generate uniform(a,b) random variables. Note
that the mean of a uniform(a,b) distribution is
0.5 * (a + b) and the variance is (1/12) * (b-a) * (b-a) */
int numUniforms = 10000;
double a = 0.0, aOld = 0.0, s = 0.0;
for (int i=0; i<numUniforms; i++)
{
double u = rv.uniformRv();
if (i == 0)
{
a = u;
s = 0.0;
}
else
{
aOld = a;
a = aOld + (u - aOld) / (i+1);
s = s + (u - aOld) * (u - aOld);
}
}
double mean = a;
double variance = 0.0;
if (numUniforms > 1)
variance = s / (numUniforms - 1);
std::cout << std::fixed << std::setprecision(3);
std::cout << "Results for " << numUniforms << " uniform(0,1) random variables" << std::endl;
std::cout << " Mean: " << mean << " (Expected=" << 0.5 << ")" << std::endl;
std::cout << " Variance: " << variance << " (Expected=" << (1.0/12.0) << ")" << std::endl;
/* Generate exponential(lambda) random variables. Note
that the mean of an exponential(lambda) distribution is
1.0/lambda and the variance is 1.0/(lambda*lambda). */
int numExponentials = 10000;
double lambda = 10.0;
a = 0.0;
aOld = 0.0;
s = 0.0;
for (int i=0; i<numExponentials; i++)
{
double u = rv.exponentialRv(lambda);
if (i == 0)
{
a = u;
s = 0.0;
}
else
{
aOld = a;
a = aOld + (u - aOld) / (i+1);
s = s + (u - aOld) * (u - aOld);
}
}
mean = a;
variance = 0.0;
if (numUniforms > 1)
variance = s / (numExponentials - 1);
std::cout << "Results for " << numExponentials << " exponential(" << lambda << ") random variables" << std::endl;
std::cout << " Mean: " << mean << " (Expected=" << 1.0/lambda << ")" << std::endl;
std::cout << " Variance: " << variance << " (Expected=" << 1.0/(lambda*lambda) << ")" << st
return 0;
}

