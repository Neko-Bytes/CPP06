/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:50:20 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 09:50:42 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Base {
public:
  virtual ~Base();
};

// It randomly instantiates A, B, or C and returns the instance as a Base
// pointer.
Base *generate(void);

// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base *p);

// It prints the actual type of the object referenced by p: "A", "B", or "C".
void identify(Base &p);
