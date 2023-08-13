/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 09:46:17 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/08/13 17:39:41 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector> // std::vector()
#include <algorithm> // std::sort()
#include <stdexcept> // throwing exceptions
#include <iostream> // std::cout()

class Span
{
	public:
		Span(unsigned int N);
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		void addRange(int* begin, int* end); // Extra, see end of subject
		void printContents() const; // Extra, to check above addRange method
	private:
		std::vector<int> numbers;
		unsigned int maxSize;
};

#endif
