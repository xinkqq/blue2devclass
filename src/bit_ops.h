//
// Created by xinkq on 04/08/22.
//

#ifndef BLUE2DEVCLASS_BIT_OPS_H
#define BLUE2DEVCLASS_BIT_OPS_H

#include <bitset>
#include <iostream>

template <size_t N1, size_t N2 >
std :: bitset <N1 + N2> concatenate_bitsets( const std :: bitset <N1> & bitset_1, const std :: bitset <N2> & bitset_2 );

template<std :: size_t N>
void reverse_bitset(std :: bitset<N> &bitset);



template <size_t N1, size_t N2 >
inline std :: bitset <N1 + N2> concatenate_bitsets(const std :: bitset <N1> & bitset_1, const std :: bitset <N2> & bitset_2 ) {
    std :: string s1 = bitset_1.to_string();
    std :: string s2 = bitset_2.to_string();
    return std :: bitset <N1 + N2>( s1 + s2 );
}

template<std :: size_t N>
inline void reverse_bitset(std :: bitset<N> &bitset){
    for(std::size_t i = 0; i < N/2; ++i) {
        bool t = bitset[i];
        bitset[i] = bitset[N-i-1];
        bitset[N-i-1] = t;
    }
}

#endif //BLUE2DEVCLASS_BIT_OPS_H
