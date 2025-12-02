/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:20:03 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 08:31:42 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <iostream>
#include <string>

struct Data {
  std::string svalue;
  float fvalue;
  double dvalue;
  char cvalue;
  int ivalue;
};

class Serializer {
private:
  // Enforce non-instantiability
  Serializer() = delete;
  Serializer(const Serializer &other) = delete;
  Serializer &operator=(const Serializer &other) = delete;
  ~Serializer() = delete;

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
