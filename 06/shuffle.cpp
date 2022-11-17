#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    randomize (arr, n);
    printArray(arr, n);

    return 0;
}
