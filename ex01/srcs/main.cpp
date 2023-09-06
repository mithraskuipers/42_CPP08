/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 09:46:12 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/06 12:29:24 by mikuiper      ########   odam.nl         */
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

	std::cout << sp.shortestSpan() << std::endl;								// Print shortest span
	std::cout << sp.longestSpan() << std::endl;									// Print longest span
	
	// The section below is extra
	// Added to meet the point made at the end of the subject
	// ("[..] fill your Span using a range of iterators") <-- In the subject they ofcourse mean integers, not iterators.

	// int arr[] = {2, 4, 7, 8, 10};												// Declare and initialize range of integers

	// First param: Begin of the range. Similar to begin().
	// Second param: End of the range. Similar to end(). Calculate size of entire array, and divide by size of one element. Gives number of elements in array. Add that to arr to get the end of the range.

	// sp.addRange(arr, arr + (sizeof(arr) / sizeof(arr[0])));					// Don't forget to update the Span maxSize from 5 to 10 because we add 5 extra elements to the existin 5.
	// std::cout << sp.shortestSpan() << std::endl;								// Should print 1 (because 6 and 7 occur in the range)
	// std::cout << sp.longestSpan() << std::endl;								// Should print 15 (because 2 is the minimum and 17 is maximum)
	// sp.printContents();														// Extra to check the contents of the range (debugging purposes)
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