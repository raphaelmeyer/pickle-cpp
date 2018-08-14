#pragma once

#include "pipestream.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <variant>

namespace pickle {

struct Error;
class PipeStream;

class Subprocess {
public:
  Subprocess(pid_t child, int to, int from);

  std::iostream & io();

private:
  std::unique_ptr<PipeStream> _io;
};

std::variant<Error, Subprocess> create_subprocess(std::string const & path);

} // namespace pickle
