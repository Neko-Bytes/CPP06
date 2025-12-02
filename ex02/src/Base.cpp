/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:55:00 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 10:09:08 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base() {}

/**
 * Randomly instantiates A, B, or C and returns the instance as a Base
 * pointer.
 * return: A pointer to a newly allocated A, B, or C object.
 */
Base *generate(void) {
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(NULL)); // sets starting point for pseudorandom list
    seeded = true; // cause we need to change the starting point only once.
  }

  int random_value = std::rand() % 3; // gives a random small to large number.

  if (random_value == 0) {
    std::cout << "Generated type A" << std::endl;
    return new A;
  } else if (random_value == 1) {
    std::cout << "Generated type B" << std::endl;
    return new B;
  } else {
    std::cout << "Generated type C" << std::endl;
    return new C;
  }
}

/**
 * Prints the actual type of the object pointed to by p using
 * dynamic_cast with pointers.
 */
void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL) {
    std::cout << "Identified type A (Pointer)" << std::endl;
  } else if (dynamic_cast<B *>(p) != NULL) {
    std::cout << "Identified type B (Pointer)" << std::endl;
  } else if (dynamic_cast<C *>(p) != NULL) {
    std::cout << "Identified type C (Pointer)" << std::endl;
  } else {
    std::cout << "Identified unknown type (Pointer)" << std::endl;
  }
}

/**
 *Prints the actual type of the object referenced by p using
 * dynamic_cast with references.
 */
void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "Identified type A (Reference)" << std::endl;
    return;
  } catch (const std::exception &e) {
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "Identified type B (Reference)" << std::endl;
    return;
  } catch (const std::exception &e) {
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "Identified type C (Reference)" << std::endl;
    return;
  } catch (const std::exception &e) {
    std::cout << "Identified unknown type (Reference)" << std::endl;
  }
}
