/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:12:55 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/12 16:10:44 by ycheroua         ###   ########.fr       */
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
	std::cout << "before:   ";
	// printContainer(_vecotrNumbers);
	// sortVector();
	std::cout << "After     ";
	// printContainer(_vecotrNumbers);
	// sortDeque();

	sortConiatner(_vecotrNumbers);
	sortConiatner(this->_dequeNumbers);
	printContainer(_dequeNumbers);
	printContainer(_vecotrNumbers);
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
void PmergeMe::fillContainerFromRawNumbers(const std::vector<std::string>& rawNumbers, Container& container)
{
    for (typename std::vector<std::string>::const_iterator it = rawNumbers.begin();
         it != rawNumbers.end(); ++it)
    {
		size_t i = (it->c_str()[0] == '-') ? 1 : 0;
    	for (; i < it->size(); ++i)
		{
        	if (!std::isdigit(it->c_str()[i])) 
				throw std::invalid_argument("Invalid input character");
		}
        int value = std::atoi(it->c_str());
        container.push_back(value);
    }
}

template <typename Container>
void PmergeMe::printContainer(Container& container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
	std::cout <<  "  " << ContainerTypeHelper<Container>::getType();
	std::cout << std::endl;	
}

void PmergeMe::sortVector(void)
{
    if (_vecotrNumbers.size() < 2)
        return;

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
}

void PmergeMe::sortDeque(void)
{
    if (_dequeNumbers.size() < 2)
        return;
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
}

template <typename Container>
void PmergeMe::sortConiatner(Container& container)
{
    if (container.size() < 2)
        return;

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
        {
            smallerNumbers.push_back(*it);
        }
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
}
