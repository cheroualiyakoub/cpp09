/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:19:16 by ycheroua          #+#    #+#             */
/*   Updated: 2025/01/20 15:50:24 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <stack>
#include <unordered_map>

class RNP
{
	public :
		RNP(void);
		RNP(const RNP& copy);
		~RNP();
		RNP& operator=(const RNP& copy);
		void fillOperations(void);
		std::unordered_map<char, std::function<double(double, double)> > _operationFunctions;
		
	private:
		std::string _input;
		std::stack<int> _stack;
		
		void setOperationFuncitons();
		static double add(double a, double b);
		static double subtract(double a, double b);
		static double multiply(double a, double b);
		static double divide(double a, double b);
};
