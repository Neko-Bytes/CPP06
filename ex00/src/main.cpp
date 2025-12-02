/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:07:22 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 08:09:01 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/utils.hpp"
#include <cstdlib>

void run_test(const std::string &literal) {
  std::cout << "\n===============================" << std::endl;
  std::cout << "Testing input: \"" << literal << "\"" << std::endl;
  std::cout << "===============================" << std::endl;
  ScalarConverter::convert(literal);
}

int main(int argc, char **argv) {
  if (argc == 2) {
    run_test(argv[1]);
    return 0;
  }

  colorprint("No command line argument provided. Running default tests.", RED);

  // --- Char Literal Examples ---
  run_test("a");
  run_test("!");

  // --- Int Literal Examples ---
  run_test("0");
  run_test("42");
  run_test("-42");

  // --- Float Literal Examples ---
  run_test("0.0f");
  run_test("4.2f");
  run_test("-4.2f");
  run_test("12345.0f");

  // --- Double Literal Examples ---
  run_test("0.0");
  run_test("4.2");
  run_test("-4.2");

  // --- Pseudo-Literal Examples ---
  run_test("nan");
  run_test("+inf");
  run_test("-inff");
  run_test("nanf");

  // --- Boundary and Edge Cases ---

  // ASCII 7 (Non-displayable char value)
  run_test("7");

  // Large number (int overflow/impossible)
  run_test("2147483648");

  // Number too large for double (Inf/Inf)
  run_test("1.79769e+309");

  // Invalid literal
  run_test("hello");

  return 1;
}
