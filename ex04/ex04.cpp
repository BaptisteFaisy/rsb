#include "../def.hpp"


std::vector<std::vector<bool>> generateInputs(int numVariables);
void printInputs(const std::vector<std::vector<bool>>& inputs);

int print_truth_table(const std::string &str)
{
	size_t i = 0;
	string str2;
	int utils;
	size_t nbr = 2;
	size_t j = 0;
	string strresult;
	while (str[i])
	{
		if (isupper((str[i])))
			str2 += str[i];
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (i == 0)
			cout << "| " << str2[i++]; 
		else
		{
			cout << " | " << str2[i];
			i++;
		}
	}
	cout << " | = |" << '\n';
	i = 0;
	while (str2[i])
	{
		cout << "|---";
		i++;
	}
	cout << "|---|" << '\n';
	i = 0;
	while (i != str2.size())
	{
		nbr = nbr* 2;
		i++;
	}
	i = 0;
	std::vector<std::vector<bool>> inputs = generateInputs(str2.size());
	for (const auto& input : inputs) {
		i = 0;
        for (bool val : input) {
			if (i++ == 0)
				cout << "| " << val;
			else
           		std::cout << " | " << val ;
        }
		strresult = "";
		i = 0;
		j = 0;
		while (i != str.size())
		{
			if (isupper(str[i]))
			{
				strresult += (input[j] + '0');
				j++;
			}
			else
				strresult += str[i];
			// cout << str[i] << endl;
			i++;
			
		}
		// cout << strresult << "f";
		utils = eval_formula(strresult);
		if (utils == -1)
			return -1;
		cout << " | " << utils << " |" << endl;
    }
	return (0);
}

std::vector<std::vector<bool>> generateInputs(int numVariables) {
    std::vector<std::vector<bool>> inputs;

    int combinations = 2;
	int j = 0;
	while (j + 1 != numVariables)
	{
		combinations *= 2;
		j++;
	}
    for (int i = 0; i < combinations; ++i) {
        std::vector<bool> input(numVariables, false);

        int temp = i;
        int index = numVariables - 1;
        while (temp > 0 && index != -1) {
            input[index--] = temp % 2;
            temp /= 2;
        }
        inputs.push_back(input);
    }
    return inputs;
}
