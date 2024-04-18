#include "../def.hpp"

using namespace std;

uint32_t Multiplier(uint32_t a, uint32_t b) noexcept 
{
    uint32_t c = 0;

    while (b != 0) {
        if (b & 1)
            c = adder(c, a);
        a <<= 1;
        b >>= 1;
    }
    return c;
}

// int main(int ac, char **av) {cout << Multiplier(atoi(av[1]), atoi(av[2])) << '\n';}