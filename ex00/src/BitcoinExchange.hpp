/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:03:44 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/18 19:20:48 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange(const std::string	&filename);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &obj);
private:
	std::fstream& _file;
	std::map<std::tm, double> _data;
	
	static std::fstream& openFile(const std::string &filename);
	void parseLine(const std::string &line);
	void addData(const std::string &date, double value);
	void loadData(std::fstream &file);
	
};
#endif

