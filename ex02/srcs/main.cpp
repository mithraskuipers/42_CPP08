/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 08:27:55 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/07 16:50:01 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mutantstack_int;											// Create instance of MutantStack specifically for integers.
	mutantstack_int.push(1);													// Push integers onto the stack.
	mutantstack_int.push(2);	
	mutantstack_int.pop();														// Remove last element from stack using pop().
	mutantstack_int.push(3);													// Push more integers to stack.,
	mutantstack_int.push(4);

	// Create iterators to iterate over the integer stack.
	MutantStack<int>::iterator int_iterator_start = mutantstack_int.begin();	// Using self-made begin() and end() member functions to obtain pointers to elements in the container.
	MutantStack<int>::iterator int_iterator_end = mutantstack_int.end();		// These pointers are also automatically iterators.

	std::cout << "Iterate over mutantstack_int: ";								// Simple loop to print all elements between start and end.
	while (int_iterator_start != int_iterator_end)
	{
		std::cout << *int_iterator_start << " - ";
		int_iterator_start++;
	}
	std::cout << std::endl << std::endl;

	std::cout << "mutantstack_int size: " << mutantstack_int.size() << std::endl;	// Print the size of the integer stack.
	std::cout << "Is mutantstack_int empty?: " << (mutantstack_int.empty() ? "yes" : "no") << std::endl;	// Check if the integer stack is empty and print the result.

	MutantStack<std::string> mutantstack_string;								// Now demo that MutantStack also works with strings.
	mutantstack_string.push("one");												// Push strings onto the stack.
	mutantstack_string.push("two");
	mutantstack_string.pop();													// Remove last element from the stack (removes "two").
	mutantstack_string.push("three");											// Push more strings onto the stack.
	mutantstack_string.push("four");

	MutantStack<std::string>::iterator string_iterator_start = mutantstack_string.begin();	// Using self-made begin() and end() member functions to obtain pointers to elements in the container.
	MutantStack<std::string>::iterator string_iterator_end = mutantstack_string.end();		// These pointers are also automatically iterators.

	std::cout << "String Iterator: ";											// Simple loop to print all elements between start and end.
	while (string_iterator_start != string_iterator_end)
	{
		std::cout << *string_iterator_start << " - ";
		string_iterator_start++;
	}
	std::cout << std::endl << std::endl;

	std::cout << "mutantstack_string size: " << mutantstack_string.size() << std::endl;	// Print the size of the string stack.
	std::cout << "Is mutantstack_string empty?: " << (mutantstack_string.empty() ? "yes" : "no") << std::endl;	// Check if the string stack is empty and print the result.
	
	mutantstack_string.pop();													// Demo that shows the stack can also be emptied completely.
	mutantstack_string.pop();
	mutantstack_string.pop();

	std::cout << "mutantstack_string size: " << mutantstack_string.size() << std::endl;	// Print the size of the string stack after pops.
	std::cout << "Is mutantstack_string empty?: " << (mutantstack_string.empty() ? "yes" : "no") << std::endl;	// Check if the string stack is empty after all these pops and print the result.

	return 0;
}