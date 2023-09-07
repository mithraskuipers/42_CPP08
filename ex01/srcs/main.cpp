/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 09:46:12 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/07 13:16:47 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);															// Declaration of Span class instance 

	sp.addNumber(6);															// Add elements to the container
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;								// Should print 2 because distance between 9 and 11 is 2
	std::cout << sp.longestSpan() << std::endl;									// Should print 14 because 17 - 3 = 14
	
	// The section below is extra
	// Added to meet the point made at the end of the subject
	// ("[..] fill your Span using a range of iterators")
	// int arr[] = {2, 4, 7, 8, 10}; // Range of iterators
	// First param: Start of range
	// Second param: End of range
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