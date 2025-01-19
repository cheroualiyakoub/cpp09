/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:03:49 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/19 22:28:26 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	try
	{
		BitcoinExchange::openFile(filename, _file);
		loadData(this->_file);
		this->_file.close();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {*this = copy;}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this == &obj)
		return *this;
	_data = obj._data;
	return *this;
}

 void BitcoinExchange::openFile(const std::string &filename, std::ifstream &file)
{
	file.open(filename, std::ios::in);
	if (!file.is_open())
		throw std::invalid_argument("file not found.");
}

void BitcoinExchange::loadData(std::ifstream &file)
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

void BitcoinExchange::printData(void)
{
    for (std::map<const std::string, const double>::const_iterator it = this->_data.begin(); it != this->_data.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string &dateStr)
{
    std::regex datePattern("(^\\d{4}-\\d{2}-\\d{2}$)");
    tm date;
	
   if (sscanf(dateStr.c_str(), "%d-%d-%d", &date.tm_year, &date.tm_mon, &date.tm_mday) != 3)
			return (false);
    if (!std::regex_match(dateStr, datePattern))
        return false;
    if (date.tm_mon < 1 || date.tm_mon > 12)
        return false;
    if (date.tm_mday < 1 || date.tm_mday > 31)
        return false;
    if (date.tm_mon == 2) 
	{
        bool isLeapYear = (date.tm_year % 4 == 0 && date.tm_year % 100 != 0) || (date.tm_year % 400 == 0);
        if (isLeapYear && date.tm_mday > 29)
            return false;
        if (!isLeapYear && date.tm_mday > 28)
            return false;
    }
    if ((date.tm_mon == 4 || date.tm_mon == 6 || date.tm_mon == 9 || date.tm_mon == 11) && date.tm_mday > 30)
        return false;
    return (true);
}

bool BitcoinExchange::isValidValue(const double &value)
{
	return (value >= 0.0 && value <= 1000.0);
}

double BitcoinExchange::getPriceByClosestDate(const std::string date)
{
    std::map<const std::string, const double>::const_iterator it = this->_data.lower_bound(date);
	
	if (it != this->_data.end() && date == it->first)
		return it->second;
	if (it != this->_data.begin())
	{
		--it;
		return it->second;
	}
	throw (std::invalid_argument("Date too early => " + date));
}

double BitcoinExchange::convertValueByDate(const std::string date, const double value)
{
	
	double priceDay = getPriceByClosestDate(date);
	return priceDay * value;
}
