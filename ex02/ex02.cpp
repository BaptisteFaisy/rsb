#include "../def.hpp"

uint32_t gray_code(uint32_t nbr)noexcept { return (nbr ^ (nbr >> 1));}