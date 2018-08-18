#include <bits/stdc++.h>
using namespace std;

class judge {
public:
    clock_t startTime;
    judge()
    {
        startTime = clock();
    }
    ~judge()
    {
        clock_t endTime = clock();
        printf("\n\nprogram run with %d ms\n", (endTime - startTime) * 1000 / CLOCKS_PER_SEC);
        system("pause");
    }
}__judge;