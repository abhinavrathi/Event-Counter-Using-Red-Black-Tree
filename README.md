# Event-Counter-Using-Red-Black-Tree

Creation of an Event Counter tool that gives a logarithmic time complexity for operations including but not limited to insertions, deletions and range search queries. The BBST developed gave great results for data even in the range of 100 mil records.

## Summary

Language Used: c++<br>Compiler Used: g++ (xcode)<br><br>
All available test cases passed.<br><br>
Running Time for 100 records file: <1 msec on local machine<br>
Running Time for 1000000 records file: <1 sec on local machine<br>
Running Time for 10000000 records file: around 5-6 seconds on local machine<br>
Running Time for 100000000 records file: around 60-70 seconds on local machine<br>

## Source Code Description

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
Here we define the structure of a “node” of Red Black Tree<br>
It contains:<br>
<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Table1.png" width=533 title="Table1.png"></img><br>
We also define a constructor to initialize node with given ID and count, and to color it to ‘b’. Also pointers p, l and r are set to NULL.<br>
Also the class definition of red_black_tree has following members:<br>
Data Member:<br>
<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Table2.png" width=545 title="Table2.png"></img><br>
Member Functions:<br>
<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Table3.png" width=772 title="Table3.png"></img><br>
Note: Functions 17,18,19 are extra implementations.<br>

### 4. red_black_tree.cpp

This class defines all the functions defined in the header file above. Short Description of each function follows:

1. red_black_tree::red_black_tree()<br>
Constructor: Initializes the root to NULL

2. void red_black_tree::insert_from_sorted_list(int id[],int count[],int start,int end,int height)<br>
Tree Initialization. Call to Function sorted_insert with arrays "id" and "count" to build the tree; "start" & "end" indicate the length of list to be put in the tree; "height" represents the maximum height of the tree

3. node* red_black_tree::sorted_insert(int i[],int c[],int s,int e,int h)<br>
Sorted_insert: Recursive function to build tree and return its root

4. int red_black_tree::increase(int id,int m)<br>
User Command: Increase count of "id" by "m", if present else insert

5. void red_black_tree::insert(node *t)<br>
Insert: Insert single node "t" into Red-Black-Tree with "root"<br>
All cases discussed are exactly what was discussed in class. The appropriate reference is given.

6. int red_black_tree::reduce(int id,int m)<br>
User Command: reduce count of "id" by "m", if present (removes node if count becomes 0 or less)

7. void red_black_tree::remove(node *t)<br>
Remove: Deletes node "t" from Red-Black-Tree with "root"<br>
All cases discussed are exactly what was discussed in class. The appropriate reference is given.

8. int red_black_tree::count(int id)<br>
User Command: count of "id", if present we return thr count else we return 0

9. int red_black_tree::inrange(int id1,int id2)<br>
User Command: inrange between "id1" & "id2", if present we all counts between these two id's (inclusive)

10. int red_black_tree::inrange_recursive(node *t,int i1,int i2)<br>
Recursive function to sum up all counts between "i1" and "i2"

11. node* red_black_tree::search(int id)<br>
Search for "id" in Red-Black-Tree

12. node* red_black_tree::search_next(int id)<br>
Search next of "id", given "id" is not present in Tree

13. node* red_black_tree::search_previous(int id)<br>
Search previous of "id", given "id" is not present in Tree

14. node* red_black_tree::getroot()<br>
Function returns root of the red-black-tree

15. node* red_black_tree::next(node *t)<br>
User Command: next of node t, return NULL if t is righmost leaf child

16. node* red_black_tree::previous(node *t)<br>
User Command: previous of node t, return NULL if t is leftmost leaf child

17. void red_black_tree::display(node *t,int n,char c)<br>
Function displays the red-black-tree as a stair-case (also lists count, color, parent and children)

18. int red_black_tree::max_height(node *t)<br>
Function calculates maximum height of any binary tree

19. void red_black_tree::color(node *t,int h)<br>
Function colors a Balanced Binary Search Tree according to red-black tree properties, given its maximum height h

Detailed description pertaining to each function is mentioned as Comments in the source code.

## Installation

Download Source Code files into a diectory.

## Execution and Results

Now, lets look at the Structure of our Program by Running through the following steps:<br>
Step 1: Execute “make” at terminal window (our current directory is the folder containing source code files)<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Executable file bbst will be created.<br>

Step 2: Execute “./bbst input_file.txt < commands_file.txt > output_file.txt<br>

Step 3: By executing ./bbst, main function will be called.<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;i) It will first check if “input_file.txt” is valid. If not, display error message and end program.<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;ii) Now we read the first line of file to store in n, the number of data points.<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;iii) We then compute levels for a Balanced Binary Search Tree, given n.<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;iv) Here on we initialize two arrays id & count (both of size n) by reading n sets of data from file<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;v) Now we call for a function in red_black_tree class using its object “T”.<br>

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Initialization from Sorted List:<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Diagram1.png" width=724 title="Diagram1.png"></img><br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;The control comes back to main.cpp

Step 4: Now we have various controls available for standard input to exercise following queries:<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;i) increase id m<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Diagram2.png" width=733 title="Diagram2.png"></img><br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Increase function will return count plus m if ID was found, else return m after inserting.

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;ii) reduce id m<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Diagram3.png" width=748 title="Diagram3.png"></img><br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Reduce function will return count minus m if ID was found, else 0 (0 for deletion too).

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;iii) count id<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Diagram4.png" width=501 title="Diagram4.png"></img>

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;iv) inrange id1 id2<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Diagram5.png" width=682 title="Diagram5.png"></img>

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;v) next id<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Diagram6.png" width=764 title="Diagram6.png"></img>

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;vi) previous id<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<img src="https://raw.githubusercontent.com/abhinavrathi/Event-Counter-Using-Red-Black-Tree/master/images/Diagram7.png" width=756 title="Diagram7.png"></img>

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;vii) quit<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Quits the main.cpp and ends the program.

## Contributors

Univeristy: University of Florida<br>
Course: Advanced Data Structures - COP5536<br>
Member: Abhinav Rathi<br>
Submisstion Date: 22nd March, 2016
