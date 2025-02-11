/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:12:55 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/11 21:00:16 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	
}
PmergeMe::PmergeMe(std::vector<std::string>  rawNumbers) : _rawNumbers(rawNumbers)
{
	
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

