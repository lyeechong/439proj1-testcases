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
####~~test9~~
~~adding a thread to the runqueue multiple times~~
threw out test 9 since it was too implementation specific on how they implemented the runqueue (either as a separate structure or within the thread struct)
####test10
running a thread which was passed as an argument to another thread
####test11
testing to see if a thread exits cleanly without the use of thread_exit
####test12
testing that thread_exit actually exits the thread

###Let me know if you think any of these are too much of a corner case?

##TODO
####cases:
- ~~runqueue ordering~~
- ~~multi yield~~
- ~~stack preservation~~
- ~~cases testing arguments passed to the functions~~
- ~~case testing two creates in a row~~
- ~~case for checking that thread_exit does exit~~
- ~~case for no thread_exit (see if the call stack pops the ret address succesfully)~~

####make a script to run diff..?
