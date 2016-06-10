# Event-Counter-Using-Red-Black-Tree

## Summary
Language Used: c++<br>Compiler Used: g++ (xcode)<br><br>
All available test cases passed.<br><br>
Running Time for test_100.txt file: <1 msec on local machine<br>
Running Time for test_1000000.txt file: <1 sec on local machine<br>
Running Time for test_10000000.txt file: around 5-6 seconds on local machine<br>
Running Time for test_100000000.txt file: around 60-70 seconds on local machine<br>

## Files Description
Following files are provided as Source Code:<br>
### 1. Makefile<br>
Compiles main.cpp, red_black_tree.cpp and creates executable file bbst Also use “make cl” to delete all object files and executable file bbst.<br>
Using Makefile we get our executable file as "bbst".<br>
We then execute by: ./bbst "file_to_read" < "user_commands_file" > "my_program's_output_file"

### 2. main.cpp<br>
Here we initially read the contents of a sorted input file and initialize the tree with it. Next we wait for User command line arguments to provide various commands and the corresponding output in each case is displayed, until the user inputs "quit".<br>
Command Line Functions available: increase id m<br>
reduce id m<br>
count id<br>
inrange id1 id2 next id previous id quit<br>

### 3. red_black_tree.hpp
Here we define the structure of a “node” of Red Black Tree It contains:

