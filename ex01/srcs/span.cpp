/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 09:46:15 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/06 12:49:25 by mikuiper      ########   odam.nl         */
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
	if (numbers.size() <= 1)	// At least 2 numbers stored in container

	{
		throw std::logic_error("Not enough numbers stored");
	}
	int current_span;
	std::vector<int> sortedNumbers = numbers;	// Create a copy of the 'numbers' vector

	std::sort(sortedNumbers.begin(), sortedNumbers.end());	// Sort it in ascending order

	int shortest_span = sortedNumbers[1] - sortedNumbers[0];	// Initial shortest span

	for (size_t i = 0; i < sortedNumbers.size() - 1; i++)	// Simple algorithm that works because the vector is sorted in ascending order	// Continuously compare current element with next element
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
	if (numbers.size() <= 1)	// At least 2 numbers stored in container

	{
		throw std::logic_error("Not enough numbers stored");
	}
	std::vector<int> sortedNumbers = numbers;	// Create a copy of the 'numbers' vector

	std::sort(sortedNumbers.begin(), sortedNumbers.end());	// Sort it in ascending order

	return (sortedNumbers.back() - sortedNumbers.front());
}
