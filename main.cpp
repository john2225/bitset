#include "my_bitset.h"

int main()
{
    
    BitSet<8> bit(6);
    std::cout << bit;
    BitSet<8> bit1(bit);
    std::cout << bit1;
   

    std::cout << "All:  "  << bit1.all() << std::endl;
    std::cout << "Any:  "  << bit1.any() << std::endl;
    std::cout <<"None:  " << bit1.none() << std::endl;
    

    std::cout << bit1.set(1, 0);
    std::cout << bit;



   // std::cout << bit[0] << std::endl;
    return 0;
}
