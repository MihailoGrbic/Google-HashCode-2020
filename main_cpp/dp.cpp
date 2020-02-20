#include "input.h"
#include "input.h"

using namespace std;

#ifdef DEBUG
    #define D(X) X
#else
    #define D(X)
#endif

struct dp_lib
{
    int signtime, lifetime;
    double average_output;
};

int main()
{
    D(freopen("a_example.txt","r",stdin););
    Input load_input();
    return 0;
}
