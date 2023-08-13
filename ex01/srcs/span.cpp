/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 09:46:15 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/08/13 20:14:43 by mikuiper      ########   odam.nl         */
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
	std::cout << "Span Copy Constructor called" << std::endl;
	*this = other;
}

// Before adding a number, it checks whether the class is "full"
void Span::addNumber(int num)
{
	if (numbers.size() >= maxSize)
	{
		throw std::runtime_error("Span size exceeds the maximum limit");
	}
	// Use built-in push_back method to add integer to 'numbers' vector
	numbers.push_back(num);
}

// Added to meet the point made at the end of the subject
// ("[..] fill your Span using a range of iterators")
void Span::addRange(int* begin, int* end)
{
	size_t rangeSize = std::distance(begin, end);
	size_t totalSize = numbers.size() + rangeSize;

	if (totalSize > maxSize)
	{
		throw std::runtime_error("Span size exceeds the maximum limit");
	}

	int* it = begin;
	while (it != end)
	{
		numbers.push_back(*it);
		it++;
	}
}

void Span::printContents() const
{
	std::cout << "Contents of Span object:" << std::endl;
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

int Span::shortestSpan() const
{
	// At least 2 numbers stored in container
	if (numbers.size() <= 1)
	{
		throw std::logic_error("Not enough numbers stored");
	}
	int current_span;
	// Create a copy of the 'numbers' vector
	std::vector<int> sortedNumbers = numbers;
	// Sort it in ascending order
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	// Initial shortest span
	int shortest_span = sortedNumbers[1] - sortedNumbers[0];
	// Simple algorithm that works because the vector is sorted in ascending order
	// Continuously compare current element with next element
	for (size_t i = 0; i < sortedNumbers.size() - 1; i++)
	{
		current_span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (current_span < shortest_span)
		{
			shortest_span = current_span;
		}
	}
	return (shortest_span);
}

int Span::longestSpan() const
{
	// At least 2 numbers stored in container
	if (numbers.size() <= 1)
	{
		throw std::logic_error("Not enough numbers stored");
	}
	// Create a copy of the 'numbers' vector
	std::vector<int> sortedNumbers = numbers;
	// Sort it in ascending order
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return (sortedNumbers.back() - sortedNumbers.front());
}
