# CS 3251: Intermediate Software Design
## Programming Assignment 5


This assignment requires you to implement the Adapter pattern. The assignment integrates the ArrayList and LinkedList classes into a new QueueBase, QueueAdapter, StackBase, and StackAdapter template class hierarchy that can be used to dynamically select the type of List strategy to use in the program at runtime. The use of Adapter ensures that no changes are required to the existing ArrayList and LinkedList classes.

The shells for the assignment are available in the _/src_ and _/include_ directories. Use these provided files:

* _include/ArrayList.h_
* _include/ArrayListIter.h_
* _include/LinkedList.h_
* _include/LinkedListConstIter.h_
* _include/LinkedListIter.h_
* _include/LinkedListNode.h_
* _include/ScopedArray.h_
* _src/ArrayList.cpp_
* _src/ArrayListIter.cpp_
* _src/LinkedList.cpp_
* _src/LinkedListConstIter.cpp_
* _src/LinkedListIter.cpp_
* _src/LinkedListNode.cpp_
* _src/ScopedArray.cpp_

You may use your versions of these files, but ensure that your classes comply with the expected behavior.  You also have been given the headers for the following:

* _include/QueueBase.h_
* _include/QueueAdapter.h_
* _include/StackBase.h_
* _include/StackAdapter.h_

These will serve as the starter code for your work.

### All Students Must:

You must implement the following:

* _src/QueueAdapter.cpp_
* _src/QueueBase.cpp_
* _src/StackAdapter.cpp_
* _src/StackBase.cpp_

The _CMakeLists.txt_ and the testing files are written for you and do not require any modification.  You are NOT to edit any portions of the provided files. 

The assignment is to be submitted using the link to github.com sent out via email to all class members. DO NOT email your assignment to the professor or the TAs.  Emailed assignments ARE NOT accepted.  We will grade the last commit to your repository before the deadline date and time.  Any commits after that moment will be ignored.  If nothing has been committed at that time you will receive a zero grade. 

## Graduate Students:
 
You should take this moment to enjoy being a graduate student.  You have no additional requirements for this assignment.

### REMINDERS:

* Ensure that your name, vunetid, email address, and the honor code appear in the header comments of all files that you have altered.

* Do not alter any of the project files unless explicitly directed otherwise!  Work only on those files specified above.  You must use the supplied `CMakeLists.txt` file as is.

* All students are required to abide by the CS 3251 coding standard, [available on the course web page](https://vuse-cs3251.github.io/style-guidelines/) and provided to you on the first day of class. Points will be deducted for not following the coding standard.

* For full credit, your program must compile with recent versions of `clang` and `gcc` and run successfully with Travis CI.
  * The Travis build *will* fail if your code is not properly formatted. **This is by design.** If your code is compiling and running successfully, but the build is failing, then your build is most likely failing because your code is not passing the linter. This can be confirmed by checking if a command involving `clang-format` in the Travis build output log has an exit code of 1.

* Your program(s) should always have an exit code of 0.  A non-zero exit code (generally indicative of a segmentation fault or some other system error) is reason to worry and must be corrected for full points.
  
* When submitting the assignment, all files that are provided to you, plus your solution files have been submitted. All files necessary to compile and run your program must reside in the GitHub.com repository.
