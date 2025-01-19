/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:03:49 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/19 17:13:22 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	try
	{
		BitcoinExchange::openFile(filename, _file);
		loadData(this->_file);
		// printData();
		this->_file.close();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
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

 void BitcoinExchange::openFile(const std::string &filename, std::fstream &file)
{
	
	file.open(filename, std::ios::in);
	if (!file.is_open())
		throw std::invalid_argument("Data file not found.");
}

void BitcoinExchange::loadData(std::fstream &file)
{
	try
	{
		std::string header;
		std::getline(file, header);
		
		std::string line;
		while (std::getline(file, line))
			parseLine(line);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

bool BitcoinExchange::isValidDate(const std::string &dateStr)
{
    std::regex datePattern("(^\\d{4}-\\d{2}-\\d{2}$)");
    return std::regex_match(dateStr, datePattern);
}

void BitcoinExchange::parseLine(const std::string &line)
{
	try
	{
		std::string date;
		double value;

		std::istringstream stream(line);
		std::getline(stream, date , ',');
		stream >> value;
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		if(!BitcoinExchange::isValidDate(date))
			throw (("Invalid date format: " + date));
		this->addData(date, value);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


void BitcoinExchange::addData(const std::string date, const double value)
{
	this->_data.insert(std::make_pair(date, value));
}

void BitcoinExchange::printData()
{
    for (std::map<const std::string, const double>::const_iterator it = this->_data.begin(); it != this->_data.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}