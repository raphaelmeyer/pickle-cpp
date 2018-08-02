#pragma once

#include <iostream>

namespace pickle {

class PipeStreamBuf : public std::streambuf {
protected:
  virtual int_type underflow() override;
  virtual int_type overflow(int_type ch) override;
  virtual int sync() override;
};

class PipeStream : public std::iostream {
public:
  PipeStream(int in, int out);

private:
  PipeStreamBuf _streambuf;
};

} // namespace pickle
