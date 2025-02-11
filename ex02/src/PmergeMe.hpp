/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:19:16 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/11 20:58:18 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <stack>
#include <unordered_map>
#include <vector>
#include <list>


class PmergeMe
{
	private:
		std::vector<std::string>  _rawNumbers;
		std::list<int> _listNumbers;
		std::vector<int> _vecotrNumbers;
		void checkInput();
		void sortList(void);
		void sortVector(void);
		
	public:
		PmergeMe();
		PmergeMe(std::vector<std::string> rawNumbers);
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& copy);
		
		
				
};