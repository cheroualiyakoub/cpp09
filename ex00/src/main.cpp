/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:37:52 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/19 21:25:13 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <list>
#include <string>

struct bitconValue
{
	std::tm date;
	double value;
};

void parseLineInput(std::string line, BitcoinExchange exchange)
{
	try
	{

		std::string dateStr = line.substr(0, 10);
		double value;
		double	convertedValue;
		std::tm date;

		sscanf(line.c_str(), "%d-%d-%d | %lf", &date.tm_year, &date.tm_mon, &date.tm_mday, &value);
		if (!BitcoinExchange::isValidDate(dateStr))
			throw std::invalid_argument("Error: bad input => " + dateStr);
		if(!BitcoinExchange::isValidValue(value))
		{
			if (value < 0 )
				throw (std::invalid_argument("Error: not a positive number."));
			if (value > 1000)
				throw (std::invalid_argument("Error: too large a number." ));
		}
		convertedValue = exchange.convertValueByDate(dateStr , value);
		std::cout << dateStr << " => " << value << " = " << convertedValue << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void readingFileToContainerString(std::fstream  &file,BitcoinExchange& exchange)
{
	std::string header;
	std::string line;

	std::getline(file, header);
	while (std::getline(file, line))
		parseLineInput(line, exchange);
}
void fileListToStructList(std::list<std::string> &fileList, std::list<bitconValue> &data_list)
{
	bitconValue data;
	for (std::list<std::string>::iterator it = ++(fileList.begin()); it != fileList.end(); it++)
	{
		std::cout << *it << std::endl;
		std::tm date;
		std::string dateStr = (*it).substr(0, 10);
		if (!BitcoinExchange::isValidDate(dateStr))
			throw std::invalid_argument("Invalid date format. Expected YYYY-MM-DD.");
		double value;
		sscanf((*it).c_str(), "%d-%d-%d | %lf", &date.tm_year, &date.tm_mon, &date.tm_mday, &value);
		data.date = date;
		data.value =  value;
		std::cout << data.date.tm_year << ";" << data.date.tm_mon << ";" << data.date.tm_mday  << std::endl;
		std::cout << value << std::endl;
		data_list.push_back(data);
	}
}

int main (int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::invalid_argument("program takes one paramater, 'file_name'"));
		std::list<bitconValue> data_list;
		std::fstream file;

		BitcoinExchange exchange("data.csv");
		BitcoinExchange::openFile(argv[1], file);
		readingFileToContainerString(file, exchange);
		file.close();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
    return 0;
}

