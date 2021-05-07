template<std::size_t N>
BitSet<N>::BitSet() : bits{0}
{
    bits.reserve(N);
}
    
template<std::size_t N>
BitSet<N>::BitSet(int value)
{
    if(value >= std::pow(2, N))
    {
        std::cout << "Out of Range error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if(0 == value)
    {
        bits = {false};
    }

    while(value > 0)
    {
        bits.push_back(value % 2);
        value /= 2;
    }
}

template<std::size_t N>
BitSet<N>::BitSet(const BitSet& rhs)
{
    for(int i = 0; i < sizeOfBits; ++i)
    {
        this->bits.push_back(rhs.bits[i]);
    }
}


template<std::size_t N>
BitSet<N>& BitSet<N>::set()
{
    for(int i = 0; i < sizeOfBits; ++i)
    {
        bits[i] = true;
    }
    return *this;
}

template<std::size_t N>
BitSet<N>& BitSet<N>::set(std::size_t position, bool value)
{
    bits[position] = value;
    return *this;
}


template<std::size_t N>
bool BitSet<N>::operator[](std::size_t position)
{
    if(position > N)
    {
        std::cout << "Out of Range error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return bits[position];
}

template<std::size_t N>
std::size_t BitSet<N>::getSize() const
{
    return sizeOfBits;
}

template<std::size_t N>
BitSet<N>& BitSet<N>::reset()
{
    
    for(int i = 0; i < sizeOfBits; ++i)
    {
        bits[i] = false;
    }
    return *this;
}

template<std::size_t N>
bool BitSet<N>::all()
{
    for(int i = 0; i < sizeOfBits; ++i)
    {
        if(bits[i] == false)
        {
            return false;
        }
    }
    return true;
}

template<std::size_t N>
bool BitSet<N>::any()
{
    for(int i = 0; i < sizeOfBits; ++i)
    {
        if(bits[i] == true)
        {
            return true;
        }
    }
    return false;
}

template<std::size_t N>
bool BitSet<N>::none()
{
    for(int i = 0; i < sizeOfBits; ++i)
    {
        if(bits[i] == true)
        {
            return false;
        }
    }
    return true;
}





