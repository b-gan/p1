#include <iostream>
#include <fstream>
#include <vector>
#include <omp.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <string>
#include <ctime>
using namespace std;

#define NUM 10

void openMP()
{
    omp_set_num_threads(1);
    int sum = 0;
#pragma omp parallel for shared(sum) reduction(+ \
                                               : sum)
    {
        for (int i = 0; i < 100; i++)
        {
            sum++;
        }
    }
    cout << "sum = " << sum << endl;
}
int main()
{
    cout << "Open MP \n";
    openMP();
    return 0;
}