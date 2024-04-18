
#include "../def.hpp"

uint32_t adder(uint32_t a, uint32_t b) noexcept
{
	uint32_t c;
	while (b != 0)
	{
		c = a & b;
		a = a ^ b;
		b = c << 1;
	}
	return (a);
}

// int main(int ac, char **av)
// {
// 	std::cout << adder(std::atoi(av[1]), std::atoi(av[2])) << '\n';
// }