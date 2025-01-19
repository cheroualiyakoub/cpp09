/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:37:52 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/19 22:14:29 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <list>
#include <string>

std::pair<std::string, double>  parseLineInput(std::string line)
{

	std::string dateStr = line.substr(0, 10);
	double value;
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
	return std::make_pair(dateStr, value);
}

void executeFile(std::ifstream  &file,BitcoinExchange& exchange)
{
	std::string header;
	std::string line;
	double	convertedValue;
	
	std::getline(file, header);
	std::pair<std::string, double> result;
	while (std::getline(file, line))
	{
		try
		{
			result = parseLineInput(line);
			convertedValue = exchange.convertValueByDate(result.first , result.second);
			std::cout << result.first << " => " << result.second << " = " << convertedValue << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

int main (int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::invalid_argument("program takes one paramater, 'file_name'"));
		std::ifstream file;
		BitcoinExchange exchange("data.csv");
		
		BitcoinExchange::openFile(argv[1], file);
		executeFile(file, exchange);
		file.close();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
    return 0;
}

