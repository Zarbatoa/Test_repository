#include <iostream>
#include <vector>
#include "spn.h"

using namespace std;

int main(void) {
    dword key = 0b0000'0110'1111'1010'0000'1100'0011'0000;
    //sub_key_1 => 0000 0110 1111 1010  => 1786
    //sub_key_2 => 0110 1111 1010 0000  => 28576
    //sub_key_3 => 1111 1010 0000 1100  => 64012
    //sub_key_4 => 1010 0000 1100 0011  => 41155
    //sub_key_5 => 0000 1100 0011 0000  => 3120

    vector<word> keys;
    sub_keys(keys,key);
    cout << "Subkeys test: " << endl;
    int j = 1;
    for(auto i : keys)
    {
        cout << "Sub_key[" << j << "] = " << i << endl;
        j++;
    }

    return 0;
}
