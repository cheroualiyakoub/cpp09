/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:03:44 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/19 22:14:59 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <string>
#include <regex>
#include <sstream>
#include <iostream>
#include <stdexcept>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string	&filename);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		
		static void openFile(const std::string &filename, std::ifstream& file);
		static bool isValidDate(const std::string &dateStr);
		static bool isValidValue(const double &value);
		double convertValueByDate(const std::string date,const double Value);
	
	private:
		std::ifstream _file;
		std::map<const std::string, const double>  _data;
		
		void loadData(std::ifstream &file);
		void parseLine(const std::string &line);
		void addData(const std::string date, const double value);
		void printData(void);
		double getPriceByClosestDate(const std::string date);
};
#endif

