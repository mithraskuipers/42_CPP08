#include "span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

void Span::addNumber(int num) {
    if (numbers.size() >= maxSize) {
        throw std::runtime_error("Span size exceeds the maximum limit");
    }
    numbers.push_back(num);
}

void Span::addRange(int* begin, int* end) {
    size_t count = 0;
    int* it = begin;
    while (it != end && count < maxSize) {
        numbers.push_back(*it);
        ++it;
        ++count;
    }
    if (count < maxSize) {
        throw std::runtime_error("Span size exceeds the maximum limit");
    }
}

int Span::shortestSpan() const {
    if (numbers.size() <= 1) {
        throw std::logic_error("Not enough numbers stored");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int shortest = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 2; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }
    return shortest;
}

int Span::longestSpan() const {
    if (numbers.size() <= 1) {
        throw std::logic_error("Not enough numbers stored");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    return sortedNumbers.back() - sortedNumbers.front();
}
