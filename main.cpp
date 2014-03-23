#include <iostream>
#include "funs.h"
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
const int n = 21;

int main()
{
    storage a[n];
    vvod(a);
    output(a);
    cout<<endl;
    sortnum(a);
    output(a);
    sortus(a);
    output(a);
    sortgoods(a);
    output(a);
    //sortdat(a);
    //output(a);
    return 0;
}
