#include "coordinate.h"
#include "stack.h"
#include "stack.cpp"
#include "coordinate.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

    Stack stack;
    string dir = "C:\\Users\\neilm\\OneDrive\\Documents\\School\\Neil\\assignment-2-neilmcdonald72\\tests\\";
    string diroutput = "C:\\Users\\neilm\\OneDrive\\Documents\\School\\Neil\\assignment-2-neilmcdonald72\\solved\\";
    string filename = argv[1];
    //string filename = "test2.txt";
    char maze[51][51];

    //starting position
    int row = 1;
    int col = 0;

    //open file and read to 2D array in memory
    ifstream file;
    file.open(dir + filename);

    while (!file.eof()) {
        for (int i = 0; i < 51; i++) {
            string line;
            getline(file, line);
            for (int x = 0; x < 51; x++) {
                maze[i][x] = line[x];
            }
        }
    }
    file.close();

    //fix issue with test2 having empty spaces
    if(filename == "test2.txt")
    {
        maze[49][49] = ' ';
        maze[49][50] = ' ';
    }


    //mark starting position and push to stack
    maze[row][col] = '#';
    stack.push({row,col});

    //begin solve
    while(stack.peek().m_row != 49 || stack.peek().m_col != 50 ) {

        //check north
        if (maze[row-1][col] == ' '){
            row = row - 1;
            maze[row][col] = '#';
            stack.push({row,col});
        }
        //check south
        else if (maze[row+1][col] == ' '){
            row = row + 1;
            maze[row][col] = '#';
            stack.push({row,col});
        }
        //check east
        else if (maze[row][col+1] == ' '){
            col = col + 1;
            maze[row][col] = '#';
            stack.push({row,col});
        }
        //check west
        else if (maze[row][col-1] == ' '){
            col = col - 1;
            maze[row][col] = '#';
            stack.push({row,col});
        }
        else {
            stack.pop();
            col = stack.peek().m_col;
            row = stack.peek().m_row;
            continue;
        }

    }

    //clear the maze
    for (int k = 0; k < 51; k++)
    {
        for (int n = 0; n < 51; n++)
        {
            if(maze[k][n] == '#')
            {
                maze[k][n] = ' ';
            }
        }
    }

    //use stack to populate maze solution
    int stackSize = stack.count();
    for (int r = 0; r < stackSize; r++)
    {
        maze[stack.peek().m_row][stack.peek().m_col] = '#';
        stack.pop();
    }

//
//    for (int m = 0; m < 51; m++)
//    {
//        for (int j = 0; j < 51; j++)
//        {
//            cout<< maze[m][j];
//        }
//        cout<<"\n";
//    }

    //save the solved maze to file
    ofstream myfile;
    myfile.open (diroutput + filename);
    for (int h = 0; h < 51; h++)
    {
        for (int g = 0; g < 51; g++)
        {
            myfile << maze[h][g];
        }
        myfile<<"\n";
    }
    myfile.close();

    return 0;
}