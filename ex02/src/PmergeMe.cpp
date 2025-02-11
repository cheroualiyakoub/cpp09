/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:12:55 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/11 21:40:13 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	
}

PmergeMe::PmergeMe(std::vector<std::string>  rawNumbers) : _rawNumbers(rawNumbers)
{
	fillContainerFromRawNumbers(rawNumbers, this->_vecotrNumbers);	
	fillContainerFromRawNumbers(rawNumbers, this->_listNumbers);	
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
	this->_listNumbers = copy._listNumbers;
	this->_vecotrNumbers = copy._vecotrNumbers;
	return *this;
}


template <typename Container>
void PmergeMe::fillContainerFromRawNumbers(const std::vector<std::string>& rawNumbers, Container& container)
{
    for (typename std::vector<std::string>::const_iterator it = rawNumbers.begin();
         it != rawNumbers.end(); ++it)
    {
		if (!std::isdigit(it->c_str()))
			throw std::invalid_argument ("invalid character");
        int value = std::atoi(it->c_str());
        container.push_back(value);
    }
}