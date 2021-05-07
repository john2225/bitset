#ifndef BITSET_H
#define BITSET_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <cstdlib>

template <std::size_t N>
class BitSet
{
public:
    BitSet();
    BitSet(int value);
    BitSet(const BitSet& rhs);
    ~BitSet() = default;
public:
    BitSet& set();
    BitSet& set(std::size_t position, bool value = true);
    BitSet& reset();
    BitSet<N>& operator&=(const BitSet<N>& rhs)
    {
        for(int i = 0; i < sizeOfBits; ++i)
        {
            this->bits[i] &= rhs.bits[i];
        }
    }
    BitSet<N>& operator|=(const BitSet<N>& rhs)
    {
        for(int i = 0; i < sizeOfBits; ++i)
        {
            this->bits[i] |= rhs.bits[i];
        }
    }

    bool operator[](std::size_t position);
    bool all();
    bool any();
    bool none();
    friend std::ostream& operator<< (std::ostream& out,const BitSet& other)
    {
        for(int i = N - 1; i >= 0; --i)
        {
            out << other.bits[i] << " ";
        }
        out << '\n';
        return out;
    }
    std::size_t getSize() const;
    
private:
    std::vector<bool> bits;
    std::size_t sizeOfBits = N;
    const std::size_t IntBits = 8 * sizeof(int);

};



#include "my_bitset.tpp"
#endif /* BITSET_H */



