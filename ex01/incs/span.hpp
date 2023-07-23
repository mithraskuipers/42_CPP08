#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    std::vector<int> numbers;
    unsigned int maxSize;

public:
    Span(unsigned int N);
    void addNumber(int num);
    void addRange(int* begin, int* end);
    int shortestSpan() const;
    int longestSpan() const;
};

#endif  // SPAN_HPP
