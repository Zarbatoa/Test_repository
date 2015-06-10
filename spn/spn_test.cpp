#include <iostream>
#include <bitset>
#include "spn.h"

using namespace std;

int main(void) {
    word plain_text = 0b1010'1010'1010'1010;
    dword key       = 0b1111'1111'1111'1111'0000'0000'0000'0000;
    
    word crypt_text = spn_cypher(plain_text,key);

    cout << "key        = " << bitset<32>(key).to_string() << endl
         << "plain_text = " << bitset<16>(plain_text).to_string() << endl
         << "crypt_text = " << bitset<16>(crypt_text).to_string() << endl;

    return 0;
}
