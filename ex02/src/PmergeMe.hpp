/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:19:16 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/12 16:03:55 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <stack>
#include <unordered_map>
#include <vector>
#include <list>
#include <deque>
#include <sstream>

class PmergeMe
{
	private:
		std::vector<std::string>  _rawNumbers;
		std::deque<int> _dequeNumbers;
		std::vector<int> _vecotrNumbers;

	public:
		PmergeMe();
		PmergeMe(std::vector<std::string> rawNumbers);
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& copy);
		
		template <typename Container>
		void fillContainerFromRawNumbers(const std::vector<std::string>& rawNumbers, Container& container);
		template <typename Container>
		void printContainer(Container& container);
		template <typename Container>
		void sortConiatner(Container& container);
		
		void sortVector(void);
		void sortDeque(void);

};

template <typename Container>
struct ContainerTypeHelper
{
	static std::string getType() { return "Unknown Container"; }
};

template <>
struct ContainerTypeHelper<std::vector<int> >
{
	static std::string getType() { return "std::vector<int>"; }
};

template <>
struct ContainerTypeHelper<std::deque<int> >
{
	static std::string getType() { return "std::deque<int>"; }
};

template <>
struct ContainerTypeHelper<std::list<int> >
{
	static std::string getType() { return "std::list<int>"; }
};

#endif