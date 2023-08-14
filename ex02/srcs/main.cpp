#include "MutantStack.hpp"

int main()
{
	// Int stack
	MutantStack<int> mutantstack_int;
	mutantstack_int.push(1);
	mutantstack_int.push(2);
	mutantstack_int.pop();
	mutantstack_int.push(3);
	mutantstack_int.push(4);

	MutantStack<int>::iterator int_iterator_start = mutantstack_int.begin();
	MutantStack<int>::iterator int_iterator_end = mutantstack_int.end();

	std::cout << "Iterate over mutantstack_int: ";
	while (int_iterator_start != int_iterator_end)
	{
		std::cout << *int_iterator_start << " - ";
		int_iterator_start++;
	}
	std::cout << std::endl << std::endl;

	std::cout << "mutantstack_int size: " << mutantstack_int.size() << std::endl;
	std::cout << "Is mutantstack_int empty?: " << (mutantstack_int.empty() ? "yes" : "no") << std::endl;

	// String stack
	MutantStack<std::string> mutantstack_string;
	mutantstack_string.push("one");
	mutantstack_string.push("two");
	mutantstack_string.pop();
	mutantstack_string.push("three");
	mutantstack_string.push("four");

	MutantStack<std::string>::iterator string_iterator_start = mutantstack_string.begin();
	MutantStack<std::string>::iterator string_iterator_end = mutantstack_string.end();

	std::cout << "String Iterator: ";
	while (string_iterator_start != string_iterator_end)
	{
		std::cout << *string_iterator_start << " - ";
		string_iterator_start++;
	}
	std::cout << std::endl << std::endl;

	std::cout << "mutantstack_string size: " << mutantstack_string.size() << std::endl;
	std::cout << "Is mutantstack_string empty?: " << (mutantstack_string.empty() ? "yes" : "no") << std::endl;

	mutantstack_string.pop();
	mutantstack_string.pop();
	mutantstack_string.pop();

	std::cout << "mutantstack_string size: " << mutantstack_string.size() << std::endl;
	std::cout << "Is mutantstack_string empty?: " << (mutantstack_string.empty() ? "yes" : "no") << std::endl;

	return 0;
}
