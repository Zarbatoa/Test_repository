#include <iostream>
#include <bitset>
#include "spn.h"

using namespace std;

int main(void) {

    word input = 0b1111'0100'1100'0101; // 62661
    //string binary = bitset<16>(62661).to_string();
    //unsigned long decimal = bitset<16>(binary).to_ulong(); 

    //cout << "bin = " << binary  << endl
    //     << "dec = " << decimal << endl;

    word output = execute_permutation(input);
    //out = 1010 1111 1000 1001  => 44937

    cout << "output = " << output << endl;

    return 0;
}
