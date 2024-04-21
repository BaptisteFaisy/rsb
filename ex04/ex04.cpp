#include "../def.hpp"


std::vector<std::vector<bool>> generateInputs(int numVariables);
void printInputs(const std::vector<std::vector<bool>>& inputs);

void  print_truth_table(const std::string &str)
{
	size_t i = 0;
	string str2;
	size_t nbr = 2;
	size_t j = 0;
	string strresult;
	int *tab;
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
	tab = new int[str2.size()];
	while (i != 3)
		tab[i++] = 0;
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
		cout << " | " << eval_formula(strresult) << " |" << endl;
    }
	delete tab;
}

std::vector<std::vector<bool>> generateInputs(int numVariables) {
    std::vector<std::vector<bool>> inputs;

    int combinations = 2;
	int i = 0;
	while (i != numVariables)
	{
		combinations *= 2;
		i++;
	}
    for (int i = 0; i < combinations; ++i) {
        std::vector<bool> input(numVariables, false);

        int temp = i;
        int index = numVariables - 1;
        while (temp > 0) {
            input[index--] = temp % 2;
            temp /= 2;
        }

        inputs.push_back(input);
    }

    return inputs;
}
// 	while (i != nbr)
// 	{
// 		j = 0;
// 		tab = l9(tab, str2);
// 		// while (j != str2.size())
// 		// {
// 		// 	if (j == 0)
// 		// 		cout << "| " << tab[j++]; 
// 		// 	else
// 		// 	{
// 		// 		cout << " | " << tab[j];
// 		// 		j++;
// 		// 	}
// 		// }
// 		// cout << " | " << "resultat" << " |" << '\n';
// 		while (j != str2.size())
// 		{
// 			cout << tab[j];
// 			j++;
// 		}
// 		i++;
// 		cout << endl;
// 	}
// 	delete tab;
// }

// int *l9(int *tab, string str2)
// {
// 	int size = str2.size();
// 	int size3 = size;
// 	bool cond = false;
// 	int size2 = size;
// 	bool condin = false;
// 	bool condboucle = false;
// 	while (size != -1)
// 	{
// 		condboucle = true;
// 		if (tab[size] == 1)
// 		{
// 			size2 = size;
// 			while (size2 != -1)
// 			{
// 				if (tab[size2] == 0)
// 				{
// 					cond = true;
// 					size3 = size2;
// 				}
// 				else if (tab[size2] == 1 && size3 != size)
// 				{
// 					break ;
// 				}
// 				size2--;
// 			}
// 			break;
// 		}
// 		size--;
// 	}
// 	// cout << cond << endl;
// 	if (condboucle == false)
// 		tab[0] = 1;
// 	else if (cond == true)
// 	{
// 		tab[size2] = 1;
// 	}
// 	else if (cond == false && (size + 1) == str2.size())
// 	{
// 		size2 = 1;
// 		while (size2 + 1 != str2.size())
// 		{
// 			size2
// 		}
// 	}
// 	else if (cond == false)
// 	{
// 		if (size + 1 <= size3)
// 		{
// 			tab[size + 1] = 1;
// 			while (size != -1)
// 			{
// 				tab[size] = 0;
// 				size--;
// 			}
// 		}
// 	}
// 	return (tab);
// }