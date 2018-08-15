#pragma once

#include <iostream>
#include <memory>
#include <variant>

namespace pickle {

struct OSError;

class Subprocess {
public:
  virtual ~Subprocess() = default;
  virtual std::iostream & io() const = 0;
};

std::variant<OSError, std::shared_ptr<Subprocess>> create_subprocess(std::string const & path);

} // namespace pickle
