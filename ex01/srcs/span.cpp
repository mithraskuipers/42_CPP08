/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 09:46:15 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/07 13:18:43 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int N)
{
	std::cout << "Span parameterized constructor called" << std::endl;
	this->maxSize = N;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
    if (this == &other)
    {
        return (*this);
    }
    numbers = other.numbers;
    maxSize = other.maxSize;
    return (*this);
}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = other;
}

void Span::addNumber(int num)
{
	if (this->numbers.size() >= maxSize)										// Before adding a number, it checks whether the class is "full".

	{
		throw std::runtime_error("Span size exceeds the maximum limit");
	}
	this->numbers.push_back(num);												// Use container member function push_back() to add integer to end of numbers container.

}

// Added to meet the criteria made at the end of the subject
// ("[..] fill your Span using a range of integers")
void Span::addRange(int *begin, int *end)										// Requires start of array and end of array.
{
	size_t rangeSize = std::distance(begin, end);								// n new items in incoming array.
	size_t totalSize = this->numbers.size() + rangeSize;						// add that to n current items in array to find out what the new total array size will be.

	if (totalSize > maxSize)													// If this new total size exceeds the user specified max size threshold, trigger error.
	{
		throw std::runtime_error("Span size exceeds the maximum limit");
	}

	int *it = begin;															// Received start part of array
	while (it != end)															// While start is not equal to end of array..
	{
		this->numbers.push_back(*it);											// Add current array value to the back of this->numbers.
		it++;
	}
}

void Span::printContents() const												// Simple this->numbers printing funtion.
{
	std::cout << "Contents of Span object:" << std::endl;
	for (size_t i = 0; i < this->numbers.size(); ++i)
	{
		std::cout << this->numbers[i] << " ";
	}
	std::cout << std::endl;
}

int Span::shortestSpan() const
{
	if (this->numbers.size() <= 1)	// At least 2 numbers stored in container.
	{
		throw std::logic_error("Not enough numbers stored");
	}
	int current_span;
	std::vector<int> sortedNumbers = this->numbers;								// Create a copy of the 'numbers' vector.
	std::sort(sortedNumbers.begin(), sortedNumbers.end());						// Sort it in ascending order.
	int shortest_span = sortedNumbers[1] - sortedNumbers[0];					// Initial shortest span. Just a starting point.
	for (size_t i = 0; i < sortedNumbers.size() - 1; i++)						// Simple algorithm that works because the vector is sorted in ascending order. Continuously compare current element with next element.
	{
		current_span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (current_span < shortest_span)										// Detect if current found span is shortest span. If so, update shortest span.
		{
			shortest_span = current_span;
		}
	}
	return (shortest_span);														// Simply return shortest span int value.
}

int Span::longestSpan() const
{
	if (this->numbers.size() <= 1)												// At least 2 numbers stored in container.
	{
		throw std::logic_error("Not enough numbers stored");
	}
	std::vector<int> sortedNumbers = this->numbers;								// Create a copy of the 'numbers' vector.
	std::sort(sortedNumbers.begin(), sortedNumbers.end());						// Sort it in ascending order
	return (sortedNumbers.back() - sortedNumbers.front());
}