/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:57:12 by kmummadi          #+#    #+#             */
/*   Updated: 2025/12/02 07:57:53 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

void colorprint(const std::string &str, const std::string &color) {
  if (color == RED)
    std::cerr << colortxt("[Error]: ", RED) << str << std::endl;
  else if (color == GREEN)
    std::cout << colortxt("[Success]: ", GREEN) << str << std::endl;
  else
    std::cout << colortxt(str, color);
}

std::string colortxt(const std::string &str, const std::string &color) {
  return (color + str + RESET);
}

// Section marker
void section(const std::string &title) {
  std::cout << std::endl;
  colorprint("==================== ", ORANGE);
  colorprint(title, ITALIC);
  colorprint(" ====================\n", ORANGE);
}
