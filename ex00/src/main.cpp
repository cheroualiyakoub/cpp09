/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:37:52 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/18 18:07:07 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <list>
#include <string>
#include <regex>


struct bitconValue
{
	std::tm date;
	double value;
}; 

bool isValidDate(const std::string &dateStr)
{
    std::regex datePattern("(^\\d{4}-\\d{2}-\\d{2}$)");
    return std::regex_match(dateStr, datePattern);
}


int main (int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::invalid_argument("program takes one paramater, 'file_name'"));
		std::fstream file(argv[1]);
		if(!(file.is_open()))
			throw (std::invalid_argument("Error opening file."));
		std::string line;
		std::list<std::string> file_list;
		while (std::getline(file, line))
			file_list.push_back(line);
		file.close();

		std::list<bitconValue> data_list;
		bitconValue data;
		for (std::list<std::string>::iterator it = ++(file_list.begin()); it != file_list.end(); ++it)
		{
            std::cout << *it << std::endl;
			std::tm date;
			std::string dateStr = (*it).substr(0, 10);
			std::cout << dateStr <<  ";" << std::endl;
			if (!isValidDate(dateStr))
                throw std::invalid_argument("Invalid date format. Expected YYYY-MM-DD.");
			double value;
			sscanf(line.c_str(), "%d-%d-%d %lf", &date.tm_year, &date.tm_mon, &date.tm_mday, &value);
			data.date = date;
			data.value =  value;
			data_list.push_back(data);
			std::cout << value << std::endl;
		}
		
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
    return 0;
}

