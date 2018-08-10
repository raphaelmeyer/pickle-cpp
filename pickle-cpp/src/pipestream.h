#pragma once

#include <array>
#include <iostream>

namespace pickle {

class PipeStreamBuf : public std::streambuf {
public:
  PipeStreamBuf(int in);
  virtual ~PipeStreamBuf();

protected:
  virtual int_type underflow() override;
  virtual int_type overflow(int_type ch) override;
  virtual int sync() override;

private:
  constexpr static std::size_t _size = 256;
  std::array<char_type, _size> _buffer;
  int _in;
};

class PipeStream : public std::iostream {
public:
  PipeStream(int in, int out);

private:
  PipeStreamBuf _streambuf;
};

} // namespace pickle
