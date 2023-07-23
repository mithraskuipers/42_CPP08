/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 23:27:53 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/07/11 13:54:28 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/easyfind.hpp"

int main() {
	try
	{
		// Create a container for integers
		std::vector<int> numbers;
		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);
		numbers.push_back(50);

		int target1 = 30; // value to find using easyfind()
		// easyfind() must return pointer to found element, so..
		// I specify the correct container type (i.e. for integers) to capture the return value of easyfind()
		std::vector<int>::iterator it1 = easyfind(numbers, target1);
		std::cout << "Value " << target1 << " found at index [" << std::distance(numbers.begin(), it1) << "]" << std::endl;
		
		// Try to find a number that doesn't exist
		int target2 = 999;
		std::vector<int>::iterator it2 = easyfind(numbers, target2); // This will throw an exception

		// This line won't be reached because an exception will be thrown if the element is not found
		std::cout << "Value " << target2 << " found at index [" << std::distance(numbers.begin(), it2) << "]" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Element not found in the container." << std::endl;
	}
	return 0;
}
