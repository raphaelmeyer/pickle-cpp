#include "pipestream.h"

#include <memory>

namespace pickle {

std::streambuf::int_type PipeStreamBuf::underflow()
{
  return std::streambuf::underflow();
}

std::streambuf::int_type PipeStreamBuf::overflow(std::streambuf::int_type ch)
{
  return std::streambuf::overflow(ch);
}

int PipeStreamBuf::sync()
{
  return std::streambuf::sync();
}

PipeStream::PipeStream(int in, int out)
  : std::iostream(&_streambuf)
{
}

} // namespace pickle
