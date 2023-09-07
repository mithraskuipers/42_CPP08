/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 08:27:55 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/09/07 16:53:20 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T>																// Make clear we are going to create a template that takes a type T (container)
class MutantStack : public std::stack<T>										// This template is a class template named 'MutantStack' that inherits from the base class 'std::stack<T>'
{																				// Requires addition of "public std::stack" next to "<T>" since CPP doesn't know otherwise T is a class
	public:
		// Default constructor
		MutantStack() : std::stack<T>() //Initialize the base class (std::stack<T>) to ensure proper construction of both base and derived class
		{
			std::cout << "Default Constructor called" << std::endl;
		}

		// Destructor
		~MutantStack()															// MutantStack inherits the destructor from the base class
		{
			std::cout << "Destructor called" << std::endl;						// This is sufficient because I don't allocate additional resources.
		}

		// Copy constructor
		MutantStack(const MutantStack &other) : std::stack<T>(other)			// Inherits copy constructor of base class to correctly copy the internal state and elements from 'other'.
		{
			std::cout << "Copy Constructor called" << std::endl;
	
			std::stack<T> tempStack(other);	// Create new container that is a copy of other. This "temp" 
			while (!tempStack.empty())
			{
				this->push(tempStack.top()); // Take last element from tempStack using top() and add that to the front of "this" using push().
				tempStack.pop();             // Remove the element from the temporary stack using pop(). Note pop() does not return the removed element.
			}
		}

		// Assignment operator overload
		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other)
			{
				// Copy the underlying container structure and its contents from 'other' (source stack) to the current instance (destination stack).
				// The line below does that by invoking the assignment operator of the base class std::stack<T>.
				std::stack<T>::operator=(other);
	
				while (!this->empty())											// Clear the current stack in "this"
				{
					this->pop();
				}
	
				// Copy elements from 'other' to the current stack
				std::stack<T> tempStack(other);	// Create new container that is a copy of other. This "temp" 
				while (!tempStack.empty())
				{
					this->push(tempStack.top()); // Take last element from tempStack using top() and add that to the front of "this" using push().
					tempStack.pop();             // Remove the element from the temporary stack using pop(). Note pop() does not return the removed element.
				}
			}
			return (*this);
		}
	
		typedef typename std::stack<T>::container_type::iterator iterator;		// Creation of alias for the iterator of the container
																				// std::stack<T>		<- Container of type T.
																				// iterator				<- Access the iterator within the container.
																				// ::container_type		<- Only added because std::stack<T> on its own does not give direct access to the iterator.
		// Add iterator functionality using a custom begin method. Inherits begin() from underlying base class.
		// begin() has a return type of 'iterator' (see above).
		iterator begin(void)
		{
			return (std::stack<T>::c.begin());									// Access the underlying container of 'std::stack' using 'std::stack<T>::c'.
																				// Returns an iterator pointing to the first element of the underlying container.
		}
		// Add iterator functionality using a custom end method. Inherits end() from underlying base class.
		// end() has a return type of 'iterator' (see above).
		iterator end(void)
		{
			return (std::stack<T>::c.end());									// Access the underlying container of 'std::stack' using 'std::stack<T>::c'.
																				// Returns an iterator pointing to the last element of the underlying container.
		}
};

#endif
