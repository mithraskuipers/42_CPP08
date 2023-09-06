/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/13 09:46:17 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/06 12:16:51 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector> 																// std::vector() (for containers)
#include <algorithm> 															// std::sort() (for algorithms)
#include <stdexcept> 															// (for throwing exceptions)
#include <iostream> 															// std::cout() (for printing)

class Span
{
	private:
		std::vector<int> numbers;
		unsigned int maxSize;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		void addRange(int* begin, int* end); // Extra, see end of subject
		void printContents() const; // Extra, to check above addRange method
};

#endif