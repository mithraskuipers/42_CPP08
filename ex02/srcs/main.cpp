/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 08:27:55 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/08/31 09:58:54 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	// Create instance of MutantStack for integers
	MutantStack<int> mutantstack_int;
	
	// Push integers onto the stack
	mutantstack_int.push(1);
	mutantstack_int.push(2);
	
	// Pop element (last one) from stack (removes 2)
	mutantstack_int.pop();
	
	// Push more integers to stack
	mutantstack_int.push(3);
	mutantstack_int.push(4);

	// Create iterators to iterate over the integer stack
	MutantStack<int>::iterator int_iterator_start = mutantstack_int.begin();
	MutantStack<int>::iterator int_iterator_end = mutantstack_int.end();

	// Iterate over the integer stack and print elements
	std::cout << "Iterate over mutantstack_int: ";
	while (int_iterator_start != int_iterator_end)
	{
		std::cout << *int_iterator_start << " - ";
		int_iterator_start++;
	}
	std::cout << std::endl << std::endl;

	// Print the size of the integer stack
	std::cout << "mutantstack_int size: " << mutantstack_int.size() << std::endl;
	
	// Check if the integer stack is empty and print the result
	std::cout << "Is mutantstack_int empty?: " << (mutantstack_int.empty() ? "yes" : "no") << std::endl;

	// Create an instance of MutantStack for strings
	MutantStack<std::string> mutantstack_string;
	
	// Push strings onto the stack
	mutantstack_string.push("one");
	mutantstack_string.push("two");
	
	// Pop an element from the stack (removes "two")
	mutantstack_string.pop();
	
	// Push more strings onto the stack
	mutantstack_string.push("three");
	mutantstack_string.push("four");

	// Create iterators to iterate over the string stack
	MutantStack<std::string>::iterator string_iterator_start = mutantstack_string.begin();
	MutantStack<std::string>::iterator string_iterator_end = mutantstack_string.end();

	// Iterate over the string stack and print elements
	std::cout << "String Iterator: ";
	while (string_iterator_start != string_iterator_end)
	{
		std::cout << *string_iterator_start << " - ";
		string_iterator_start++;
	}
	std::cout << std::endl << std::endl;

	// Print the size of the string stack
	std::cout << "mutantstack_string size: " << mutantstack_string.size() << std::endl;
	
	// Check if the string stack is empty and print the result
	std::cout << "Is mutantstack_string empty?: " << (mutantstack_string.empty() ? "yes" : "no") << std::endl;

	// Perform pop operations on the string stack
	mutantstack_string.pop();
	mutantstack_string.pop();
	mutantstack_string.pop();

	// Print the size of the string stack after pops
	std::cout << "mutantstack_string size: " << mutantstack_string.size() << std::endl;
	
	// Check if the string stack is empty after pops and print the result
	std::cout << "Is mutantstack_string empty?: " << (mutantstack_string.empty() ? "yes" : "no") << std::endl;

	return 0;
}
