/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:00:48 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 08:04:42 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/utils.hpp"

// Determines the input literal type (CHAR, INT, FLOAT, DOUBLE, PSEUDO, or
// INVALID).
Type ScalarConverter::getType(const std::string &input) {
  if (isPseudoLiteral(input))
    return PSEUDO;
  if (isChar(input))
    return CHAR;
  if (isFloat(input))
    return FLOAT;
  if (isDouble(input))
    return DOUBLE;
  if (isInt(input))
    return INT;

  return INVALID;
}

// Converts the input string literal to char, int, float, and double.
void ScalarConverter::convert(const std::string &input) {
  Type type = getType(input);
  double value = 0.0;

  if (type == INVALID) {
    colorprint("Invalid literal format", RED);
    return;
  }
  if (type == CHAR) {
    value = static_cast<double>(input[0]);
  } else {
    char *endptr = NULL;
    value = std::strtod(input.c_str(), &endptr);

    // Final safety check against invalid characters after conversion
    if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
      colorprint("Invalid characters found at the end of the literal", RED);
      return;
    }
  }

  toChar(value);
  toInt(value);
  toFloat(value);
  toDouble(value);
}
