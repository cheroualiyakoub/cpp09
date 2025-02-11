/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:37:52 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/11 20:57:10 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	try
	{  
		(void)argv;
		if (argc <= 1)
			throw std::invalid_argument("Error: No input sequence provided.");
		std::vector<std::string> arguments(argv + 1, argv + argc);

	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
    return 0;
}

