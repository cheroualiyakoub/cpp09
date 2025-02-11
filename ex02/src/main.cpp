/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:37:52 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/11 21:37:05 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::string> splitString(const std::string &str)
{
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (iss >> token)
        tokens.push_back(token);
    return tokens;
}

int main (int argc, char **argv)
{
	try
	{  
		if (argc <= 1)
			throw std::invalid_argument("Error: No input sequence provided.");
		std::vector<std::string> arguments;
		if (argc != 2)
			arguments.assign(argv + 1, argv + argc);
		else
			arguments = splitString(argv[1]);
		PmergeMe pmergeMe(arguments);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
    return 0;
}

