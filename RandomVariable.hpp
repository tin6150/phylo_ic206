// pasted from programming_book.pdf Appendix A
#ifndef RandomVariable_hpp
#define RandomVariable_hpp
class RandomVariable {
public:
RandomVariable(void);
RandomVariable(int x);
double exponentialRv(double lambda);
double uniformRv(void);
double uniformRv(double lower, double upper);
protected:
int seed;
};
#endif

