#ifndef TOOLS_HPP
#define TOOLS_HPP

template <typename Num>
void Swap(Num& a, Num& b)
{
    Num tmp = a;
    a = b;
    b = tmp;
}

#endif // TOOLS_HPP