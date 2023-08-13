/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 23:27:53 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/08/13 09:45:04 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/easyfind.hpp"

int main() {
	try
	{
		// Create a container for TYPE int
		std::vector<int> numbers;

		// Add the integers to the container
		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);
		numbers.push_back(50);

		// Integer to find in the container
		int target1 = 30;
	
		// easyfind() has to return pointer to found element
		// So need to specify the appropriate container for TYPE int to capture the easyfind()'s return value
		std::vector<int>::iterator it1;
		it1 = easyfind(numbers, target1);
		
		// I know it will be found, so here is a fixed message
		std::cout << "Now succesfully trying to find the number 30 in integer container with values 10, 20, 30, 40, 50" << std::endl;
		// std::distance() calculates the number of elements between two iterators in a single container
		std::cout << "Value " << target1 << " found at index [" << std::distance(numbers.begin(), it1) << "]\n" << std::endl;
		
		// Try to find a number that doesn't exist
		int target2 = 999;
		// This will throw an exception
		std::vector<int>::iterator it2;
		it2 = easyfind(numbers, target2);

		// This line won't be reached because an exception will be thrown if the element is not found
		std::cout << "Value " << target2 << " found at index [" << std::distance(numbers.begin(), it2) << "]" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Element not found in the container." << std::endl;
	}
	return 0;
}
