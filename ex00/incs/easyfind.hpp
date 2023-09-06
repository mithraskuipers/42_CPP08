/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 21:55:02 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/06 12:16:37 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>																// std::vector() (for containers)
#include <algorithm> 															// std::sort() (for algorithms)
#include <iostream> 															// std::cout() (for printing)

template <typename T>															// Declare function template that takes a type T (container).
typename T::iterator easyfind(T &container, int i)								// Container can be any type. Function returns iterator of that container.
{
	typename T::iterator it;													// Declare iterator of this type T.
	it = find(container.begin(), container.end(), i);							// Use find() and begin() iterator member functions. Return iterator pointing to element in container.
																				// find() returns iterator to end of range (i.e. after the last element).
																				// find() requires a range, hence .begin() and .end(). Range includes all elemens from begin to (not including) element pointed to be end().
	if (it == container.end())
	{
		throw (std::exception());
	}
	// std::cout << *it << std::endl; // Dereference it first, similar to pointers to a string array.
	return (it);
}

#endif