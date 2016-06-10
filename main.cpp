//
//  main.cpp
//  ADS Project
//
//  Created by Abhinav Rathi on 3/22/16.
//  Copyright © 2016 Abhinav Rathi. All rights reserved.
//

/* 
 The following Code is for main function.
 
 Using Makefile our executable is "bbst".
 We then execute by: ./bbst "file_to_read" < "user_commands_file" > "this_program's_output_file"
 
 Here we initially read the contents of a sorted input file and initialize the tree with it.
 
 Next we wait for User command line arguments to provide various commands and the corresponding output in each case is displayed, until the user inputs "quit"
 
 Command Line Functions available:
 
 increase id m
 reduce id m
 count id
 inrange id1 id2
 next id
 previous id
 quit
 */

#include <iostream>             // For I/O Handling
#include <fstream>              // For File Handling
#include <stdlib.h>             // Dynamic Memory Allocation
#include <cmath>                // Power Function Used to Calculate No. of Levels, given total Nodes

#include "red_black_tree.hpp"   // Including red_black_tree Class

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Variable Declarations
    red_black_tree T;           // Creating object T of class red_black_tree
    fstream ifs;                // Filereader object ifs
    int n,save_n,levels,x,y;    // Various integer variables
    string input;               // input to store user command line entry
    node *temp;                 // Temporary variable of type node
    
    ifs.open(argv[1],fstream::in);  // Initiate File Read
    
    if(!ifs.good()){                // Check if file doesn't exist
        cout<<"File doesn't Exists! Exiting Program.\n";
        exit(1);
    }
    
    ifs>>n;                         // Read No. of Nodes in File
    
    // This code calculates no. of levels int the Tree for O(n) recursive initialization from Sorted List
    save_n=n;
    levels=0;
    while(save_n>0){
        levels++;
        save_n=n;
        save_n/=pow(2,levels);
        
    }
    
    /*
        IGNORE : Code to Initialize with Assorted List (Directly from File)
     
        while(n){
            ifs>>x>>y;
            temp=new node(id,count);
            T.insert(temp);
            --n;
        }
    */
    
    // Code to Initialize with Sorted List
    
    int *id=(int*)malloc(sizeof(int)*n);        // Declaring 2 Nos. arrays to hold data from file
    int *count=(int*)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;++i){                       // Reading file data into arrays "id" & "count"
        ifs>>id[i]>>count[i];
    }
    
    // Following function call will create a red-black tree with sorted lists id & count
    T.insert_from_sorted_list(id,count,0,n-1,levels);
    
    // Deleting id & count arrays to free space
    delete(id);
    delete(count);
    
    // User Input Commands
    do{
        cin>>input;
        
        if(input=="increase"){              // increase id m
            cin>>x>>y;
            cout<<T.increase(x,y)<<"\n";
        }
        else if(input=="reduce"){           // reduce id m
            cin>>x>>y;
            cout<<T.reduce(x,y)<<"\n";
        }
        else if(input=="count"){            // count id
            cin>>x;
            cout<<T.count(x)<<"\n";
        }
        else if(input=="inrange"){          // inrange id1 id2
            cin>>x>>y;
            cout<<T.inrange(x,y)<<"\n";
        }
        else if(input=="next"){             // next id
            cin>>x;
            temp=T.next(T.search(x));
            if(temp)                        // Case when x exists in orignal tree
                cout<<temp->ID<<" "<<temp->count<<"\n";
            else{                           // Case when x didn't exist in orignal tree
                temp=T.search_next(x);
                if(temp)
                    cout<<temp->ID<<" "<<temp->count<<"\n";
                else
                    cout<<"0 0\n";
            }
        }
        else if(input=="previous"){         // previous id
            cin>>x;
            temp=T.previous(T.search(x));
            if(temp)                        // Case when x exists in orignal tree
                cout<<temp->ID<<" "<<temp->count<<"\n";
            else{                           // Case when x didn't exist in orignal tree
                temp=T.search_previous(x);
                if(temp)
                    cout<<temp->ID<<" "<<temp->count<<"\n";
                else
                    cout<<"0 0\n";
            }
        }
        else if(input=="display"){          // IGNORE : Displays the tree
            T.display(T.getroot(),0,'X');
        }
    }while(input!="quit");
    return 0;
}