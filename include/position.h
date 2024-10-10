#include <format>
#include <string>

#pragma once

class Position {
public:
  unsigned int line;
  unsigned int column;
  Position(unsigned int lineInput = 1, unsigned int columnInput = 1) {
    line = lineInput;
    column = columnInput;
  }

  std::string getColonRepresentation() {
    std::string str =
        std::format("{}:{}", std::to_string(line), std::to_string(column));
    return str;
  }
};
