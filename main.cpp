#include <iostream>
#include <string>

#include "bwt.h"

using namespace std;

int main()
{
    string x;
    
    string result_of_encode = "";
    int i;
    string result_of_decode = "";

    cin >> x;
    
    bwt::encode(x, result_of_encode, i);
    bwt::decode(result_of_encode, result_of_decode, i);

    cout << "Результат кодирования: " << result_of_encode << endl;
    cout << "Результат декодирования: " << result_of_decode << endl;

    return 0;
}
