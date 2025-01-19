/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:03:44 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/19 17:13:14 by ycheroua         ###   ########.fr       */
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
	static bool isValidDate(const std::string &dateStr);
	static void openFile(const std::string &filename, std::fstream& file);
	
private:
	std::fstream _file;
	std::map<const std::string, const double>  _data;
	void addData(const std::string date, const double value);
	void parseLine(const std::string &line);
	void printData();
	void loadData(std::fstream &file);
};
#endif

