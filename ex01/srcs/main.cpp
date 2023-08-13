/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 09:46:12 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/08/13 17:41:11 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

int main()
{
	// Declaration of Span class instance 
	Span sp = Span(5);

	// Add elements to the vector
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	// The section below is extra
	// Added to meet the point made at the end of the subject
	// ("[..] fill your Span using a range of iterators")
	// int arr[] = {2, 4, 7, 8, 10}; // Range of iterators
	// First param: Start of range
	// Second param: Calculation to find number of elements in range
	// sp.addRange(arr, arr + (sizeof(arr) / sizeof(arr[0]))); // Don't forget to update the Span maxSize from 5 to 10
	// std::cout << sp.shortestSpan() << std::endl; // Should print 1 (because 6 and 7 occur in the range)
	// std::cout << sp.longestSpan() << std::endl; // Should print 15 (because 2 is the minimum and 17 is maximum)
	// sp.printContents(); // Extra to check the contents of the range (debugging purposes)
	return 0;
}

/*
// Main provided by the subject
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
*/