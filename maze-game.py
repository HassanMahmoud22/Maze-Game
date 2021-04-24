N = 12
M = 12
i = 2
j = 0
grid = [['#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'],
        ['#', '.', '.', '.', '#', '.', '.', '.', '.', '.','.','#'],
        ['.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'],
        ['#', '#', '#', '.', '#','.', '.', '.', '.', '#', '.', '#'],
        ['#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#'],
        ['#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '.'],
        ['#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'],
        ['#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'],
        ['#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'],
        ['#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'],
        ['#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'],
        ['#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#']]
def clear_game():
    grid[2][0] = 'X'
    grid[5][11] = '.'
def check_input(c):
    if(c == 8 or c == 4 or c == 5 or c == 6):
        return True
    return False
def valid_move(c):
    global grid
    global i
    global j
    if(c == 8):
        if(grid[i-1][j] == '.'):
            return True
    elif(c == 4):
        if(grid[i][j-1] == '.'):
            return True
    elif(c== 6):
        if(grid[i][j+1] == '.'):
            return True
    elif(c == 5):
        if(grid[i+1][j] == '.'):
            return True
    return False
def set_position(c):
     global grid
     global i
     global j
     grid[i][j] = '.'
     if(c == 8):
        grid[i-1][j] = 'X'
        i = i-1
     elif(c == 4):
        grid[i][j-1] = 'X'
        j = j - 1
     elif(c == 6):
        grid[i][j+1] = 'X'
        j = j + 1
     elif(c == 5):
        grid[i+1][j] = 'X'
        i = i + 1
def print_grid():
    global grid
    for i in range(N):
        for j in range(M):
            print (grid[i][j], end = ' ')
        print()
def read_input():
    print("----------------")
    print("Enter the position: ", end = ' ')
    c = int(input())
    while(not valid_move(c)):
        print("Enter valid number")
        c = int(input())
    return c
def check_win():
    global i
    global j
    if(i == 5 and j == 11):
        return True
def play():
    c = 0
    while True:
        print_grid()
        c = read_input()
        while not valid_move(c):
            print("you can't move to this direction")
            c = read_input()
        set_position(c)
        if(check_win()):
            print_grid()
            print("Winner!!")
            break
while True:
    print("Welcome to the Maze Game.....")
    while True:
      clear_game()
      play()
      c = input('Play Again [Y/N] ')
      if c not in 'yY':
        break
