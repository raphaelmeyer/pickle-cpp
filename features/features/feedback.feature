Feature: Scenario validation
  In order to delevop behavior driven
  As a C++ developer
  I want to get feedback about success or failure in steps and scenarios

  @wip
  Scenario: A passing step
  Given the following feature:
    """
    Feature: feature
      Scenario: scenario
        Given a passing step
    """
  When I run the example-pickle
  Then the output should contain:
    """
    1 scenario (1 passed)
    1 step (1 passed)
    """
