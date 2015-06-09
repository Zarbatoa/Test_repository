#include <iostream>
#include "spn.h"

using namespace std;

int main(void) {
    word s_input = 0b1010'0011'1011'1111;

    word s_output = execute_s_box(s_input);
    // s_output = 0110 0001 1100 0111  => 25031
    
    cout << "s_output = " << s_output << endl;

    return 0;
}
