/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:19:16 by ycheroua          #+#    #+#             */
/*   Updated: 2025/02/10 14:56:47 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <stack>
#include <unordered_map>

class RPN
{
	public :
		RPN(void);
		RPN( std::string &expression);
		RPN(const RPN& copy);
		~RPN();
		RPN& operator=(const RPN& copy);
		void calculaiton(void);
		std::unordered_map<char, std::function<double(double, double)> > _operationFunctions;
		void isValidExpression();
		bool isOperationChar(char c);
		
	private:
		std::string _expression;
		std::stack<int> _stack;
		void setOperationFuncitons();
		void doOperaiton(char operation);
		static double add(double a, double b);
		static double subtract(double a, double b);
		static double multiply(double a, double b);
		static double divide(double a, double b);
};
