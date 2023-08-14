#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() : std::stack<T>()
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

	    // Copy the elements from 'other' to the current stack
	    std::stack<T> tempStack(other); // Use the base class's copy constructor
	    while (!tempStack.empty())
	    {
	        this->push(tempStack.top()); // Push each element onto the current stack
	        tempStack.pop(); // Pop the element from the temporary stack
	    }
	}

	    MutantStack &operator=(const MutantStack &other)
    {
        if (this != &other)
        {
            std::stack<T>::operator=(other);
        }
        return (*this);
    }

    iterator begin()
    {
        return std::stack<T>::c.begin();
    }

    iterator end()
    {
        return std::stack<T>::c.end();
    }
};

#endif
