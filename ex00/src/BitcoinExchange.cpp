/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:03:49 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/18 19:21:47 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	this->_file = BitcoinExchange::openFile(filename);
	loadData(this->_file);
	this->_file.close();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this == &obj)
		return *this;
	_data = obj._data;
	return *this;
}

std::fstream& BitcoinExchange::openFile(const std::string &filename)
{
	std::fstream file;
	file.open(filename, std::ios::in);
	if (!file.is_open())
		throw std::invalid_argument("Data file not found.");
	return file;
}

void BitcoinExchange::loadData(std::fstream &file)
{
	std::string line;
	while (std::getline(file, line))
		parseLine(line);
}


