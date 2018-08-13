#include "pipestream.h"

#include <algorithm>
#include <memory>

#include <unistd.h>

namespace pickle {

PipeStreamBuf::PipeStreamBuf(int in, int out)
  : _buffer()
  , _in(in)
  , _out(out)
{
  setp(_buffer.begin(), _buffer.end() - 1);
  setg(_read_buffer.begin(), _read_buffer.begin(), _read_buffer.begin());
}

PipeStreamBuf::~PipeStreamBuf()
{
  sync();
}

std::streambuf::int_type PipeStreamBuf::underflow()
{
  if(gptr() == egptr()) {
    auto const done = ::read(_out, eback(), _read_buffer.size());
    setg(eback(), eback(), eback() + std::max<decltype(done)>(0, done));
  }

  if(gptr() != egptr()) {
    return static_cast<int_type>(*gptr());
  }
  return traits_type::eof();
}

std::streambuf::int_type PipeStreamBuf::overflow(std::streambuf::int_type ch)
{
  if(!traits_type::eq_int_type(ch, traits_type::eof())) {
    *pptr() = traits_type::to_char_type(ch);
    pbump(1);
  }

  if(sync() == 0) {
    return traits_type::not_eof(ch);
  }

  return traits_type::eof();
}

int PipeStreamBuf::sync()
{
  if(pbase() != pptr()) {
    auto const size = pptr() - pbase();
    auto const done = ::write(_in, _buffer.data(), size);
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
  , _streambuf(in, out)
{
}

} // namespace pickle
