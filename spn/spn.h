#ifndef __SPN_H_
#define __SPN_H_
#include <vector>

typedef std::uint_least32_t word;
typedef std::uint_least16_t sub_key;

int permutation_s[16] = {
    14, 4, 13, 1, 2, 15, 11, 8,
    3, 10, 6, 12, 5, 9, 0, 7
};

int permutation_p[16] = {
    1, 5, 9, 13, 2, 6, 10, 14,
    3, 7, 11, 15, 4, 8, 12, 16
};

void sub_keys(std::vector<sub_key> & sub_keys, word key)
{
    for (int r = 1; r < 6; r++) {
        sub_key kr = (key << (4*r-4)) >> 16;
        sub_keys.insert( sub_keys.end(), kr);
    }
}

word spn_cipher (word plain, word key)
{
}

#endif
