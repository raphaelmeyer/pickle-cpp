#pragma once

#include <iostream>

namespace pickle {

class Runner {
public:
  Runner(std::string feature_path);

  void run(std::iostream & pickle_runner);

private:
  std::string _feature_path;
};

} // namespace pickle
