/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:19:05 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/10 16:59:53 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	this->setOperationFuncitons();
}

RPN::RPN(std::string &expression)
{
	try
	{
		this->setOperationFuncitons();
		this->_expression = expression;
		this->isValidExpression();
		this->calculaiton();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN& RPN::operator=(const RPN& copy)
{
	this->_expression = copy._expression;
	this->_operationFunctions = copy._operationFunctions;
	this->_stack = copy._stack;
	return (*this);
}


RPN::~RPN() {}

void RPN::setOperationFuncitons(void)
{
	this->_operationFunctions.insert(std::make_pair('+', add));
	this->_operationFunctions.insert(std::make_pair('-', subtract));
	this->_operationFunctions.insert(std::make_pair('*', multiply));
	this->_operationFunctions.insert(std::make_pair('/', divide));
} 

double RPN::add(double a, double b)
{
    return a + b;
}

double RPN::subtract(double a, double b)
{
    return a - b;
}

double RPN::multiply(double a, double b)
{
    return a * b;
}

double RPN::divide(double a, double b)
{
    if (b == 0)
	{
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}
bool RPN::isOperationChar(char c)
{
	if ( this->_operationFunctions.count(c) != 0)
		return (true);
	return (false);
}

void RPN::isValidExpression()
{
	if (this->_expression.empty())
		throw ("Error: expression empty");
	for (std::size_t i = 0; i < this->_expression.size(); ++i)
	{
		char c = this->_expression[i];
		if (!std::isdigit(c) && c != ' ' && !isOperationChar(c))
			throw std::invalid_argument("Error: expression contains invalid characters");
	}
}

void RPN::doOperaiton(char operation)
{
	if (this->_stack.size() < 2)
		throw::std::invalid_argument("Error: invalid expression");
	int b = this->_stack.top(); this->_stack.pop();
	int a = this->_stack.top(); this->_stack.pop();
	this->_stack.push(this->_operationFunctions[operation](a, b));
}

void RPN::calculaiton()
{
	for (std::size_t i = 0; i < this->_expression.size(); ++i)
	{
		if (std::isdigit(this->_expression[i]))
			this->_stack.push(atoi(std::string(1, this->_expression[i]).c_str()));
		else if (isOperationChar(this->_expression[i]))
			doOperaiton(this->_expression[i]);
	}
	std::cout << this->_stack.top() << std::endl;
}
