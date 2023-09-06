/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 23:27:53 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/06 12:14:18 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/easyfind.hpp"

int main() {
	try
	{
		std::vector<int> numbers;												// Create a container for type int.

		numbers.push_back(10);													// Add integers to the container one by one.
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);
		numbers.push_back(50);

		int target1 = 30;														// Try find integer that exists in container.
		std::vector<int>::iterator it1;											// easyfind returns iterator pointing to found element. Declare iterator of type int.
		it1 = easyfind(numbers, target1);
		
		std::cout << "Now succesfully trying to find the number 30 in integer container with values 10, 20, 30, 40, 50" << std::endl;	// I know it will be found, so here is a fixed message.
		std::cout << "Value " << target1 << " found at index [" << std::distance(numbers.begin(), it1) << "]\n" << std::endl;			// std::distance() calculates the n elements between 2 iterators in a single container.
		
		int target2 = 999;														// Try find integer that does NOT exist in container. Will throw exception.
		std::vector<int>::iterator it2;
		it2 = easyfind(numbers, target2);

		std::cout << "Value " << target2 << " found at index [" << std::distance(numbers.begin(), it2) << "]" << std::endl;				// This line won't be reached because an exception will be thrown if the element is not found.
	}
	catch (std::exception& e)
	{
		std::cout << "Element not found in the container." << std::endl;
	}
	return 0;
}
