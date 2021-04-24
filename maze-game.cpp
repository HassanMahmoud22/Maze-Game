#include <bits/stdc++.h>
using namespace std;
int i = 2;
int j = 0;
const int N = 12;
char grid[N][N] =
      { { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
		{ '#', '.', '.', '.', '#', '.', '.', '.', '.', '.','.','#' },
		{ '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#' },
		{ '#', '#', '#', '.', '#','.', '.', '.', '.', '#', '.', '#' },
		{ '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#' },
		{ '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '.' },
		{ '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
		{ '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
		{ '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#' },
		{ '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#' },
		{ '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
		{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };

void clear_game()
{
    grid[2][0] = 'X';
    grid[5][11] = '.';
}

void print_grid()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool check_input(int input)
{
    if(input == 8 || input == 4 || input == 5 || input == 6)
        return true;
    return false;
}

bool valid_move(int input)
{
    if(input == 8)
    {
        if(grid[i-1][j] == '.')
            return true;
    }

    else if(input == 4)
    {
        if(grid[i][j-1] == '.')
            return true;
    }

    else if(input == 6)
    {
        if(grid[i][j+1] == '.')
            return true;
    }

    else if(input == 5)
    {
        if(grid[i+1][j] == '.')
            return true;
    }
    return false;

}

void read_input(int& input)
{
    cout << "----------------" << endl;
    cout << "Enter the position" << endl;
    cin >> input;
    while(!valid_move(input))
    {
        cout << "Enter valid number" << endl;
        cin >> input;
    }
}


void set_position(int input)
{
     grid[i][j] = '.';
     if(input == 8)
     {
        grid[i-1][j] = 'X';
        i = i-1;
     }

     else if(input == 4)
     {
        grid[i][j-1] = 'X';
        j = j - 1;
     }

    else if(input == 6)
    {
        grid[i][j+1] = 'X';
        j = j + 1;
    }

    else if(input == 5)
    {
        grid[i+1][j] = 'X';
        i = i + 1;
    }
}

bool check_win()
{
    if(i == 5 && j == 11)
        return true;
    return false;
}

void play()
{
    int input = 0;

    while(true)
    {
        print_grid();
        read_input(input);
        while(!valid_move(input))
        {
            cout << "you can't move to this direction";
            read_input(input);
        }
        set_position(input);
        if(check_win())
        {
            print_grid();
            cout << "Winner!!" << endl;
            break;
        }

    }
}
int main()
{
    cout<<"Welcome to the Maze Game....."<<endl;
    while(true)
    {
      clear_game();
      play();
      char c;
      cout<<"Play Again [Y/N]";
      cin>>c;
      if(c != 'y' && c!= 'Y')
        break;
    }

}
