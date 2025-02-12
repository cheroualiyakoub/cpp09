/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:12:55 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/13 00:09:28 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	
}

PmergeMe::PmergeMe(std::vector<std::string>  rawNumbers) : _rawNumbers(rawNumbers)
{
	fillContainerFromRawNumbers(rawNumbers, this->_vecotrNumbers);	
	fillContainerFromRawNumbers(rawNumbers, this->_dequeNumbers);
	std::cout << "before:   " ;
	printContainer(_vecotrNumbers);
	std::chrono::nanoseconds time1 = sortVector();
	std::chrono::nanoseconds time2 = sortDeque();
	std::cout << "After     ";
	printContainer(_dequeNumbers);
	printTime(_vecotrNumbers, time1);
	printTime(_dequeNumbers, time2);
}

PmergeMe::PmergeMe(const PmergeMe& copy) : _rawNumbers(copy._rawNumbers)
{
	
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) 
{
	this->_rawNumbers = copy._rawNumbers;
	this->_dequeNumbers = copy._dequeNumbers;
	this->_vecotrNumbers = copy._vecotrNumbers;
	return *this;
}

template <typename Container>
bool PmergeMe::isSorted(const Container& container)
{
    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator next = it;
    ++next;
    while (next != container.end())
    {
        if (*it > *next)
            return false;
		++it;
        ++next;
    }
    return true;
}

template <typename Container>
void PmergeMe::fillContainerFromRawNumbers(const std::vector<std::string>& rawNumbers, Container& container)
{
	if (rawNumbers.size() < 2)
		throw std::invalid_argument ("Error: program takes a positive integer sequence.");

    for (typename std::vector<std::string>::const_iterator it = rawNumbers.begin();
         it != rawNumbers.end(); ++it)
    {
		size_t i = (it->c_str()[0] == '+') ? 1 : 0;
    	for (; i < it->size(); ++i)
		{
        	if (!std::isdigit(it->c_str()[i])) 
				throw std::invalid_argument("Error: Invalid input character");
		}
        int value = std::atoi(it->c_str());
        container.push_back(value);
    }
	if (isSorted(container))
		throw std::invalid_argument ("Sequence already sorted.");
}



template <typename Container>
void PmergeMe::printContainer(Container& container)
{
    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator end = container.end();
	std::size_t endIndex = 10;
    std::size_t i = 0;
	
    while (it != end && i++ < endIndex)
        std::cout << *it++ << " ";
    if (container.size() > endIndex)
        std::cout << "[...]";
    std::cout << std::endl;
}

std::chrono::nanoseconds PmergeMe::sortVector(void)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    std::vector<int> largerNumbers;
    std::vector<int> smallerNumbers;
    std::vector<int>::iterator it = _vecotrNumbers.begin();
    while (it != _vecotrNumbers.end())
    {
        std::vector<int>::iterator next = it + 1;
        if (next != _vecotrNumbers.end())
        {
            if (*it > *next)
                std::swap(*it, *next);

            largerNumbers.push_back(*next); 
            smallerNumbers.push_back(*it);
            ++it;
        }
        else
            smallerNumbers.push_back(*it);
        ++it;
    }
    std::sort(largerNumbers.begin(), largerNumbers.end());
    std::vector<int> sortedVector = largerNumbers;
    for (size_t i = 0; i < smallerNumbers.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(sortedVector.begin(), sortedVector.end(), smallerNumbers[i]);
        sortedVector.insert(pos, smallerNumbers[i]);
    }
    _vecotrNumbers = sortedVector;
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	return (duration);
}

std::chrono::nanoseconds PmergeMe::sortDeque(void)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    std::deque<int> largerNumbers;
    std::deque<int> smallerNumbers;
    std::deque<int>::iterator it = _dequeNumbers.begin();
    while (it != _dequeNumbers.end())
    {
        std::deque<int>::iterator next = it + 1;

        if (next != _dequeNumbers.end())
        {
            if (*it > *next)
                std::swap(*it, *next);
            largerNumbers.push_back(*next); 
            smallerNumbers.push_back(*it);
            ++it;
        }
        else
            smallerNumbers.push_back(*it);
        ++it;
    }
    std::sort(largerNumbers.begin(), largerNumbers.end());
    std::deque<int> sortedDeque(largerNumbers.begin(), largerNumbers.end());
    for (size_t i = 0; i < smallerNumbers.size(); ++i)
    {
        std::deque<int>::iterator pos = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), smallerNumbers[i]);
        sortedDeque.insert(pos, smallerNumbers[i]);
    }
    _dequeNumbers = sortedDeque;
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	return (duration);
}

template <typename Container>
std::chrono::nanoseconds PmergeMe::sortConiatner(Container& container)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
    Container largerNumbers;
    Container smallerNumbers;
    typename Container::iterator it = container.begin();
    while (it != container.end())
    {
        typename Container::iterator next = it + 1;
        if (next != container.end())
        {
            if (*it > *next)
                std::swap(*it, *next);

            largerNumbers.push_back(*next); 
            smallerNumbers.push_back(*it);
            ++it;
        }
        else
            smallerNumbers.push_back(*it);
        ++it;
    }
    std::sort(largerNumbers.begin(), largerNumbers.end());
    Container sortedDeque(largerNumbers.begin(), largerNumbers.end());
    for (size_t i = 0; i < smallerNumbers.size(); ++i)
    {
        typename Container::iterator  pos = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), smallerNumbers[i]);
        sortedDeque.insert(pos, smallerNumbers[i]);
    }
    container = sortedDeque;
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

	std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	return duration;
}

template <typename Container> 
void PmergeMe::printTime(Container& container, std::chrono::nanoseconds time)
{
	(void)time;
	std::cout << "Time to process a range of "  << container.size() << " elements with " << 
		ContainerTypeHelper<Container>().getType() << " : "<< time.count() << " ms"<< std::endl;
}
