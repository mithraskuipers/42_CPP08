/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 21:55:02 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/07/11 13:55:23 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream> // std::cout
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>															// Specifies we are declaring a function template
typename T::iterator easyfind(T &container, int i)								// The container can be any type as long as it has an iterator type nested within it.
{																				// I decided to set return type to iterator, but could also have been index.
																				// Note: In this exercise we assume we receive a container for integers
	typename T::iterator it;													// Declare an iterator var on the iterator type nested within container T
	// Use find() member function of an iterator.
	// begin() and end() are also member functions of an iterator. They return an iterator pointing to the first and after the last element in the container, respectively.
	// If the element is not found in the container, find() returns an iterator pointing to the end of the range (i.e. after the last element)
	// Note: find() requires a range (see begin() and end()). This range includes all elements from the beginning up to, but NOT INCLUDING, the element pointed to by end().
	it = find(container.begin(), container.end(), i);
	if (it == container.end())
	{
		throw (std::exception());
	}
	// std::cout << *it << std::endl; // Dereference it first, similar to pointers to a string array
	return (it);
}

#endif