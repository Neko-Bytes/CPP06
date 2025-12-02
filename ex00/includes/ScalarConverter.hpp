/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:30:10 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 04:07:52 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

class ScalarConverter {
private:
  // Non-instantiable
  ScalarConverter() = delete;
  ScalarConverter(const ScalarConverter &other) = delete;
  ScalarConverter &operator=(const ScalarConverter &other) = delete;
  ~ScalarConverter() = delete;

  // Helper functions for conversion and output
  static void toChar(double d);
  static void toInt(double d);
  static void toFloat(double d);
  static void toDouble(double d);

  // Type detection utility functions
  static bool isPseudoLiteral(const std::string &input);
  static bool isChar(const std::string &input);
  static bool isInt(const std::string &input);
  static bool isFloat(const std::string &input);
  static bool isDouble(const std::string &input);

  // To determine base type
  static Type getType(const std::string &input);

public:
  static void convert(const std::string &input);
};
