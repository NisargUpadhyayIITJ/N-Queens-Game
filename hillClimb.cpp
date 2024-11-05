#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

// randomised n-queens solving approach

void configureRandom(int **board, int *state, int N)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        state[i] = rand() % N;
        board[state[i]][i] = 1;
    }
}

void printBoard(int **board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void printState(int *state, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << state[i] << " ";
    }
    cout << endl;
}

bool compareStates(int *state1, int *state2, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (state1[i] != state2[i])
            return false;
    }
    return true;
}

void fill(int **board, int N, int value)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = value;
        }
    }
}

int calcAttack(int **board, int *state, int N)
{
    int attack = 0;
    int row, col;

    for (int i = 0; i < N; i++)
    {
        // left of same row
        row = state[i];
        col = i - 1;
        while (col >= 0 && board[row][col] != 1)
        {
            col--;
        }
        if (col >= 0 && board[row][col] == 1)
        {
            attack++;
        }

        // right of same row
        row = state[i];
        col = i + 1;
        while (col < N && board[row][col] != 1)
        {
            col++;
        }
        if (col < N && board[row][col] == 1)
        {
            attack++;
        }

        // upper left diagonal
        row = state[i] - 1;
        col = i - 1;
        while (col >= 0 && row >= 0 && board[row][col] != 1)
        {
            col--;
            row--;
        }
        if (col >= 0 && row >= 0 && board[row][col] == 1)
        {
            attack++;
        }

        // lower left diagonal
        row = state[i] + 1;
        col = i - 1;
        while (col >= 0 && row < N && board[row][col] != 1)
        {
            col--;
            row++;
        }
        if (col >= 0 && row < N && board[row][col] == 1)
        {
            attack++;
        }

        // lower right diagonal
        row = state[i] + 1;
        col = i + 1;
        while (col < N && row < N && board[row][col] != 1)
        {
            col++;
            row++;
        }
        if (col < N && row < N && board[row][col] == 1)
        {
            attack++;
        }

        // upper right diagonal
        row = state[i] - 1;
        col = i + 1;
        while (col < N && row >= 0 && board[row][col] != 1)
        {
            col++;
            row--;
        }
        if (col < N && row >= 0 && board[row][col] == 1)
        {
            attack++;
        }
    }
    return attack / 2;
}

void generateBoard(int **board, int *state, int N)
{
    fill(board, N, 0);
    for (int i = 0; i < N; i++)
    {
        board[state[i]][i] = 1;
    }
}

void copyState(int *state1, int *state2, int N)
{
    for (int i = 0; i < N; i++)
    {
        state1[i] = state2[i];
    }
}

void getNeighbour(int **board, int *state, int N)
{
    int **opBoard = new int*[N];
    int *opState = new int[N];
    for (int i = 0; i < N; i++)
        opBoard[i] = new int[N];

    copyState(opState, state, N);
    generateBoard(opBoard, opState, N);
    int opObjective = calcAttack(opBoard, opState, N);

    int **tempBoard = new int*[N];
    int *tempState = new int[N];
    for (int i = 0; i < N; i++)
        tempBoard[i] = new int[N];

    copyState(tempState, state, N);
    generateBoard(tempBoard, tempState, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j != state[i])
            {
                tempState[i] = j;
                tempBoard[tempState[i]][i] = 1;
                tempBoard[state[i]][i] = 0;

                int temp = calcAttack(tempBoard, tempState, N);
                if (temp <= opObjective)
                {
                    opObjective = temp;
                    copyState(opState, tempState, N);
                    generateBoard(opBoard, opState, N);
                }
                tempBoard[tempState[i]][i] = 0;
                tempState[i] = state[i];
                tempBoard[state[i]][i] = 1;
            }
        }
    }

    copyState(state, opState, N);
    fill(board, N, 0);
    generateBoard(board, state, N);
}

void hillClimbing(int **board, int *state, int N)
{
    int **tempBoard = new int*[N];
    int *tempState = new int[N];
    for (int i = 0; i < N; i++)
        tempBoard[i] = new int[N];

    copyState(tempState, state, N);
    generateBoard(tempBoard, tempState, N);

    do
    {
        copyState(state, tempState, N);
        generateBoard(board, state, N);

        getNeighbour(tempBoard, tempState, N);

        if (compareStates(state, tempState, N))
        {
            printBoard(board, N);
            break;
        }
        else if (calcAttack(board, state, N) == calcAttack(tempBoard, tempState, N))
        {
            tempState[rand() % N] = rand() % N;
            generateBoard(tempBoard, tempState, N);
        }

    } while (true);

    for (int i = 0; i < N; i++)
    {
        delete[] tempBoard[i];
    }
    delete[] tempBoard;
    delete[] tempState;
}

int main()
{
    int N;
    cin >> N;

    int **board = new int*[N];
    int *state = new int[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[N];

    configureRandom(board, state, N);
    hillClimbing(board, state, N);

    return 0;
}