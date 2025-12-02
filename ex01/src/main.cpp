/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:35:30 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 08:36:59 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main() {
  Data test;
  Data *result_data;

  //	Setup
  test.ivalue = 42;
  test.fvalue = 42.42f;
  test.svalue = "This is the test string!";
  test.cvalue = 'c';

  //	Serialize and Deserialize
  result_data = Serializer::deserialize(Serializer::serialize(&test));

  //	Check
  std::cout << "\033[35m";
  std::cout << "Test data:\t" << &test << std::endl;
  std::cout << "New data:\t" << result_data << std::endl;
  std::cout << "\033[0m";
  return (0);
}
