#include <iostream>

using namespace std;

char pos[] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int x, y;
void towers()
{
    system("clear");
    cout << "*** TOWER OF HANOI ***" << endl;
    cout << endl;
    for (int a = 0; a < 1; a++)
    {
        for (int b = 1; b <= 9; b += 3)
        {
            cout << pos[b] << " ";
            if (b == 7)
            {
                cout << endl;
                b = -1;
            }
            if (b == 8)
            {
                cout << endl;
                b = 0;
            }
        }
        cout << endl;
    }
}
void play_x()
{
    cin >> x;
    if (pos[x] != 'a' && pos[x] != 'b' && pos[x] != 'c')
    {
        cout << "Pick a number hidden by a letter! Try again: ";
        play_x();
    }
    else if (pos[x] == 'c' && pos[x - 1] == 'b' || pos[x - 1] == 'a')
    {
        cout << "Can't pick a letter that is under another! Try again: ";
        play_x();
    }
    else if (pos[x] == 'b' && pos[x - 1] == 'a')
    {
        cout << "Can't pick a letter that is under another! Try again: ";
        play_x();
    }
    else if (pos[x] == 'c' && y % 3 == 0 && pos[y] != '0' + y)
    {
        cout << "No move available for 'c'!" << endl;
        cout << "Pick a number hidden by another letter: ";
        play_x();
    }
}
void play_y()
{
    cin >> y;
    if (y < 1 || y > 9)
    {
        cout << "Enter a number from 1-9: ";
        play_y();
    }
    else if (pos[y] == 'a' || pos[y] == 'b' || pos[y] == 'c')
    {
        cout << "That square is taken! Try again: ";
        play_y();
    }
    else if (pos[y + 1] == '1' + y && y % 3 != 0)
    {
        cout << "Can't place a letter on top of a number! Try again: ";
        play_y();
    }
    else if ((y + 1) % 3 == 0 && x == y + 1 || (y + 2) % 3 == 0 && x == y + 1)
    {
        cout << "Can't move up the tower! Try again: ";
        play_y();
    }
    else if (pos[y] == 'b' || pos[y] == 'c' || pos[y + 1] == 'a')
    {
        cout << "Can't place 'b' or 'c' on top of 'a'! Try again: ";
        play_y();
    }
    else if (pos[y] == 'c' && pos[y + 1] == 'b')
    {
        cout << "Can't place 'c' on top of 'b'! Try again: ";
        play_y();
    }
}
int main()
{
    pos[1] = 'a';
    pos[2] = 'b';
    pos[3] = 'c';
    while (pos[7] != 'a' || pos[8] != 'b' || pos[9] != 'c')
    {
        towers();
        cout << endl;
        cout << "From: ";
        play_x();
        cout << "To: ";
        play_y();
        pos[y] = pos[x];
        pos[x] = '0' + x;
        towers();
    }
    cout << endl;
    cout << "Congratulations!!!" << endl;
    return 0;
}