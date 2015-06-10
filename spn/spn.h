#ifndef __SPN_H_
#define __SPN_H_
#include <vector>
#include <bitset>

typedef std::uint_least32_t dword;
typedef std::uint_least16_t word;

int permutation_s[16] = {
    14, 4, 13, 1, 2, 15, 11, 8,
    3, 10, 6, 12, 5, 9, 0, 7
};

int permutation_p[16] = {
    1, 5, 9, 13, 2, 6, 10, 14,
    3, 7, 11, 15, 4, 8, 12, 16
};

void sub_keys(std::vector<word> & sub_keys, dword key)
{
    for (int r = 1; r < 6; r++) {
        word kr = (key << (4*r-4)) >> 16;
        sub_keys.insert( sub_keys.end(), kr);
    }
}

word execute_s_box (word u)
{
    word v = 0;

    for (int i = 0; i < 4; i++)
    {
        word s_index = ((u << i*4) >> 12) & 0xF;
        word nibble = permutation_s [s_index];
        v = v | (nibble << (3-i)*4);
    }

    return v;
}

word execute_permutation (word input)
{
    std::bitset<16> w;
    std::bitset<16> v(input);

    for (int i = 0; i < 16; i++)
        w[16 - permutation_p[i]] = v[15 - i];

    return w.to_ulong();
}

word spn_cypher (word plain, dword key)
{
    //creating sub keys
    std::vector<word> keys;
    sub_keys(keys, key);

    word wr = plain; // w0
    word ur,vr;

    for (int r = 0; r < 3; r++) {
        ur = wr ^ keys[r];
        vr = execute_s_box(ur);
        wr = execute_permutation(vr);
    }

    //last round does'nt have permutation
    ur = wr ^ keys[3];
    vr = execute_s_box(ur);

    word crypt = vr ^ keys[4];

    return crypt;
    //TODO: Test this function
}

#endif
