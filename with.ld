with {
  (:ok, value) = might_fail ()
  (:ok, next_value) = might_fail_again (value)
  x if gte? (x, value) = get_a_thing_with (next_value)
}
then do_something_with (x)
else {
  (:err, :oops) -> "I made an oopsie"
  x if lte? (x, 12) -> "x is too small!"
}
