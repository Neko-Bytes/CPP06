/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeChecker.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:42:41 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 07:44:51 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

// Checks if the input is a pseudo-literal (nan, inf, nanf, inff).
bool ScalarConverter::isPseudoLiteral(const std::string &input) {
  return (input == "nan" || input == "nanf" || input == "+inf" ||
          input == "-inf" || input == "+inff" || input == "-inff");
}

// Checks if the input is a char literal (single non-digit character).
bool ScalarConverter::isChar(const std::string &input) {
  return ((input.length() == 1 && !std::isdigit(input[0])) ||
          (input.length() == 3 && input[0] == '\'' && input[2] == '\''));
}

// Checks if the input has the structure of a float literal (contains '.' and
// ends with 'f').
bool ScalarConverter::isFloat(const std::string &input) {
  return (input.find('f') == input.length() - 1 &&
          input.find('.') != std::string::npos);
}

// Checks if the input has the structure of a double literal (contains '.' but
// no 'f').
bool ScalarConverter::isDouble(const std::string &input) {
  return (input.find('f') == std::string::npos &&
          input.find('.') != std::string::npos);
}

// Checks if the input has the structure of an int literal (no '.' and no 'f').
bool ScalarConverter::isInt(const std::string &input) {
  return (input.find('.') == std::string::npos &&
          input.find('f') == std::string::npos);
}
