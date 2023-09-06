#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() // Init of std::stack<T>() is necessary to ensure proper construction of base class and derived class
		{
			std::cout << "Default Constructor called" << std::endl;
		}

		~MutantStack()
		{
			std::cout << "Destructor called" << std::endl;
		}

		MutantStack(const MutantStack &other) : std::stack<T>(other)
		{
			std::cout << "Copy Constructor called" << std::endl;

			// Copy the elements from 'other' to the current stack.
			// Done using pop(). To not shrink the original, first make copy 'tempStack' using copy constructor.
			std::stack<T> tempStack(other);
			while (!tempStack.empty())
			{
				this->push(tempStack.top());									// Copy top element of tempStack to current stack (this)
				tempStack.pop();												// Remove the element from the temporary stack. pop() does not return removed element, only remove top element.
			}
		}

		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other)
			{
				// Copy the underlying container structure and its contents from other (source stack) to the current instance (dest stack)
				// The line below does that. It invokes the assignment operator of the base class std::stack<T>.
				std::stack<T>::operator=(other);

				// Clear the current stack
				while (!this->empty())
				{
					this->pop();
				}

				// Copy elements from 'other' to the current stack
				std::stack<T> tempStack(other);
				while (!tempStack.empty())
				{
					this->push(tempStack.top());								// Copy top element of tempStack to current stack (this)
					tempStack.pop();											// Remove the element from the temporary stack. pop() does not return removed element, only remove top element.
				}
			}
			return (*this);
		}

		// Create alias named 'iterator' for the iterator type of the underlying container used by std::stack.
		// std::stack<T> <- stack template class, that will hold type T.
		// container_type <- Access the container_type type within the std::stack class. Here that's 'double queue' (insertion/deletion at both ends).
		// iterator <- Access the iterator type within the type of container_type.
		typedef typename std::stack<T>::container_type::iterator iterator;

		// Add iterator functionality using custom begin method.
		// begin() has return type 'iterator'
		iterator begin()
		{
			// Access underlying container of 'std::stack' using 'std::stack<T>::c'
			// Returns iterator pointing to first element of the underlying container
			return (std::stack<T>::c.begin());
		}
		// Add iterator functionality using custom end method.
		// end() has return type 'iterator'
		iterator end()
		{
			// Access underlying container of 'std::stack' using 'std::stack<T>::c'
			// Returns iterator pointing to last element of the underlying container
			return(std::stack<T>::c.end());
		}
};

# endif
