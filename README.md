#Testcases for Project 2 (threads)
####test1
tests for correct behavior for the runqueue order
####test2
tests for correct behavior with multiple yields
####test3
tests for correct behavior with multiple yields with only one thread
####test4
is a little fun. Does fibonacci numbers and squares. Tests for not corrupting the local variables on the call stack I suppose.
####test5
very simple argument passing test with an int
####test6
simple argument passing test with an array
####test7
multiple threads combined with argument passing
####test8
ping pong, passing an arg between threads

##TODO
###cases:
- ~~runqueue ordering~~
- ~~multi yield~~
- ~~stack preservation~~
- ~~cases testing arguments passed to the functions~~
- case testing two creates in a row
- cases for dispatch/schedule
- case for adding a thread to the runqueue multiple times in a row
- case for adding a thread to the runqueue multiple times between yields
- case for thread_exit twice in a row (should exit the first time)
- case for exit then yield (should exit upon exit)
- case for exit then create (should exit upon exit)
- case for no thread_exit (see if the call stack pops the ret address succesfully)

####maybe make a script to run diff
