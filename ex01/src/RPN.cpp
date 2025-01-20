/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:19:05 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/20 15:48:19 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RNP::RNP()
{
	this->setOperationFuncitons();
	
}

RNP::~RNP() {}

void RNP::setOperationFuncitons(void)
{
	this->_operationFunctions.insert(std::make_pair('+', add));
	this->_operationFunctions.insert(std::make_pair('-', subtract));
	this->_operationFunctions.insert(std::make_pair('*', multiply));
	this->_operationFunctions.insert(std::make_pair('/', divide));
} 

double RNP::add(double a, double b)
{
    return a + b;
}

double RNP::subtract(double a, double b)
{
    return a - b;
}

double RNP::multiply(double a, double b)
{
    return a * b;
}

double RNP::divide(double a, double b)
{
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}