/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:47:43 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 08:05:37 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

// Outputs the converted value as a char with boundary and display checks.
void ScalarConverter::toChar(double d) {
  std::cout << "char: ";
  if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
    std::cout << "impossible" << std::endl;
  } else if (d < 32 || d > 126) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
  }
}

// Outputs the converted value as an int with overflow checks.
void ScalarConverter::toInt(double d) {
  std::cout << "int: ";
  if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() ||
      d > std::numeric_limits<int>::max()) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << static_cast<int>(d) << std::endl;
  }
}

// Outputs the converted value as a float with correct formatting for whole
// numbers.
void ScalarConverter::toFloat(double d) {
  std::cout << "float: ";
  if (std::isnan(d)) {
    std::cout << "nanf" << std::endl;
  } else if (std::isinf(d)) {
    std::cout << (d > 0 ? "+" : "-") << "inff" << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d)
              << "f" << std::endl;
  }
}

// Outputs the converted value as a double with correct formatting for whole
// numbers.
void ScalarConverter::toDouble(double d) {
  std::cout << "double: ";
  if (std::isnan(d)) {
    std::cout << "nan" << std::endl;
  } else if (std::isinf(d)) {
    std::cout << (d > 0 ? "+" : "-") << "inf" << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
  }
}
