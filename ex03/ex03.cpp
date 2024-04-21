#include "../def.hpp"

int eval_formula(const std::string& expression) {
    std::stack<bool> operandStack;
	bool operand2;
	bool operand1;
	int i = 0;
    for (char op : expression) {
        if (op == '0' || op == '1') {
            operandStack.push(op - '0');
			i++;
        }
		else
		{
			if (i > 0)
			{
				operand2 = operandStack.top();
				operandStack.pop();
				i--;
			}
			if (i > 0)
			{
				operand1 = operandStack.top();
				operandStack.pop();
				i--;
			}
            if (op == '&') {
                operandStack.push(operand1 && operand2);
				i++;
            } else if (op == '|') {
                operandStack.push(operand1 || operand2);
				i++;
            } else if (op == '^') {
                operandStack.push(operand1 ^ operand2);
				i++;
            } else if (op == '!') {
                operandStack.push(!operand2);
				i++;
            }
			else if (op == '>') {
                operandStack.push(operand1 >= operand2);
				i++;
            }
			else if (op == '=') {
                operandStack.push(operand1 == operand2);
				i++;
            }
			else {
            std::cerr << "Opérateur non reconnu : " << op << std::endl;
           	return -1 ;}
        }
    }
    return (int)operandStack.top();
}