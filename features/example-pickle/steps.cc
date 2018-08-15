#include <pickle-cpp/cucumber.h>

using namespace cucumber;

namespace {

Define steps {

  Given("a pending step", [](Pickle const & pickle){
    pickle.pending();
  }),

  When("a passing step", [](Pickle const & pickle){
    pickle.assert(true);
  }),

  Then("a failing step", [](Pickle const & pickle){
    pickle.fail();
  })

};

} // namespace
