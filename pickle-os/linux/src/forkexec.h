#pragma once

#include "pipestream.h"

#include <pickle/os/subprocess.h>

#include <iostream>
#include <memory>

namespace pickle {

struct Error;
class PipeStream;

class ForkExec : public Subprocess {
public:
  ForkExec(pid_t child, int to, int from);

  std::iostream & io() const;

private:
  std::unique_ptr<PipeStream> _io;
};


} // namespace pickle
