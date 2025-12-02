/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:10:28 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 10:11:44 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include <iostream>

void run_test(int test_num) {
  std::cout << "\n--- Test " << test_num << " ---" << std::endl;

  // 1. Generate a random object
  Base *p = generate();

  // 2. Identify using pointer
  std::cout << "  -> Identifying by pointer:" << std::endl;
  identify(p);

  // 3. Identify using reference
  std::cout << "  -> Identifying by reference:" << std::endl;
  identify(*p);

  // Clean up
  delete p;
  std::cout << "Test " << test_num << " finished." << std::endl;
}

int main() {
  std::cout << "C++ Module 06 - Exercise 02: Identify Real Type" << std::endl;

  // Run multiple tests to ensure randomness and correctness
  for (int i = 1; i <= 5; ++i) {
    run_test(i);
  }

  return 0;
}
