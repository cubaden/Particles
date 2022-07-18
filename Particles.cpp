/*
 A collection of particles is contained in a linear chamber. They all have the same speed, but some are headed toward the right and others are headed toward the left.
 These particles can pass through each other without disturbing the  motion of the particles,
 so all the particles will leave the chamber relatively quickly.
 We will be given the initial conditions by a String init containing at each position an 'L' for a leftward moving particle,
 an 'R' for a rightward moving particle, or a '.' for an empty location. init shows all the positions in the chamber.
 Initially, no location in the chamber contains two particles passing through each other.

 We would like an animation of the process. At each unit of time, we want a string showing occupied locations with an 'X' and unoccupied locations with a '.'.

 Implement “animate” function which takes int - speed and std::string (or vector) containing initial condition. The speed is the number of positions each particle moves in one time unit.

 The method will return a std::vector of std::string in which each successive element shows the
 occupied locations at the next time unit. The first element of the return should show the occupied locations at the initial instant (at time = 0) in the 'X','.' format.
 The last element in the return should show the empty chamber at the first time that it becomes empty.

 Constraints
 - speed will be between 1 and 10 inclusive
 - init will contain between 1 and 50 characters inclusive
 - each character in init will be '.' or 'L' or 'R'
 */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cout << "You passed in only " << argc << "argument(s). 3 is needed" << endl;
    }

    string s = argv[1];

    const int speed = stoi(argv[2]);

    /*std::regex re("-");
    string result = std::regex_replace(s, re, "");*/

    int i = 0;
    string result = s;

    auto nFindR = result.find('R');
    auto nFindL = result.find('L');

    cout << s << endl;

    while ((result.find('R') != string::npos) || (result.find('L') != string::npos))
    {
        s = result;
        i = 0;
        for (char c : s)
        {
            if (c == 'R')
            {                
                if ((i + speed) < s.length())
                {
                    result[i] = '.';
                    result[i + speed] = 'R';
                }
                else
                    result[i] = '.';

                //cout << "new pos i's R = " << i + speed << endl;
            }
            else if (c == 'L')
            {
                
                if ((i - speed) >= 0)
                {
                    result[i] = '.';
                    result[i - speed] = 'L';
                }
                else
                    result[i] = '.';
                //cout << "new pos i's L = " << i - speed << endl;
            }
            else
            {
            }
            ++i;
        }
        cout << result << endl;
    }
    exit(0);
}
