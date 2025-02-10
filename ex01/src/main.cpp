/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:37:52 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/10 15:21:24 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
	try
	{  
		if (argc != 2)
			throw (std::invalid_argument("program takes one paramater."));
		std::string _expression(argv[1]);
		RPN rnp(_expression);
	}
	catch(std::exception &e)
	{
		 std::cerr << e.what() << std::endl;
	}
    return 0;
}

