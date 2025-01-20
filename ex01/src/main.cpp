/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:37:52 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/20 15:53:09 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
	try
	{  
		double a = 10, b = 2;
    	char op = '/';
		(void)argv;
		
		if (argc != 2)
			throw (std::invalid_argument("program takes one paramater."));
		RNP rnp;
	}
	catch(std::exception &e)
	{
		 std::cerr << "Caught an exception: " << e.what() << std::endl;
	}
    return 0;
}

