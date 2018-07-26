#pragma once

namespace cucumber {

class Pickle {
public:
  void pending() const;
  void fail() const;
  void assert(bool condition) const;
};

} // namespace cucumber
