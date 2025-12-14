#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "bwt.h"

using namespace std;

int main()
{
    string x = ".BANANA.";
    string result_of_encode = "";
    int i;
    string result_of_decode = "";
    
    bwt::encode(x, result_of_encode, i);
    bwt::decode(result_of_encode, result_of_decode, i);

    cout << result_of_encode << i << endl;
    cout << result_of_decode << endl;

    return 0;
}
