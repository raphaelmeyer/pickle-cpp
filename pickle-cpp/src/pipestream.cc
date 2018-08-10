#include "pipestream.h"

#include <memory>

#include <unistd.h>

namespace pickle {

PipeStreamBuf::PipeStreamBuf(int in)
  : _buffer()
  , _in(in)
{
  setp(_buffer.begin(), _buffer.end() - 1);
}

PipeStreamBuf::~PipeStreamBuf()
{
  sync();
}

std::streambuf::int_type PipeStreamBuf::underflow()
{
  return std::streambuf::underflow();
}

std::streambuf::int_type PipeStreamBuf::overflow(std::streambuf::int_type ch)
{
  if(!traits_type::eq_int_type(ch, traits_type::eof())) {
    *pptr() = traits_type::to_char_type(ch);
    pbump(1);
  }
  return (sync() == -1) ? traits_type::eof() : traits_type::not_eof(ch);
}

int PipeStreamBuf::sync()
{
  if(pbase() != pptr()) {
    std::streamsize size(pptr() - pbase());
    std::streamsize done(::write(_in, _buffer.data(), size));
    if(done > 0) {
      std::copy(pbase() + done, pptr(), pbase());
      setp(pbase(), epptr());
      pbump(size - done);
    }
  }
  return (pptr() != epptr()) ? 0 : -1;
}

PipeStream::PipeStream(int in, int out)
  : std::iostream(&_streambuf)
  , _streambuf(in)
{
}

} // namespace pickle
