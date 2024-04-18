
#include "def.hpp"
using namespace std;

int main(void)
{
	uint32_t i = 0;
	cout << adder(3 , 3) << '\n';
	cout << Multiplier(5, 4) << '\n';
	while (i != 9)
		cout << gray_code(i++) << '\n';
	
}