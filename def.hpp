#include <iostream>
#include <stack>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

uint32_t adder(uint32_t a, uint32_t b) noexcept ;
uint32_t Multiplier(uint32_t a, uint32_t b) noexcept ;
uint32_t gray_code(uint32_t nbr)noexcept ;
bool eval_formula(const std::string& expression);
void  print_truth_table(const std::string &str);