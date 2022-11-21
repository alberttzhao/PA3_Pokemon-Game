

#include <iostream>
#include "View.h"
#include "GameObject.h"

View::View()
{

}

void View::Draw()
{
    for(int j = size-1; j >= -1; j--)
    {
        for(int i = -1; i <= size-1; i++)
        {
            //grid axis
            if(i == -1 && j%2 == 0)
            {
                cout << j*2;
                if(j/5 == 0)
                {
                    cout << " ";
                }
            }
            else if(j == -1 && j%2 != 0)
            {
                cout << " ";
            }
            else if(j == -1 && i%2 == 0)
            {
                cout << i*2;
                if(i/5 == 0)
                {
                    cout << " ";
                }
                cout << " ";
            }
            //draw objects
            if(i >= 0 && j >= 0)
            {
                cout << grid[i][j][0] << grid[i][j][1];
            }
        }
        cout << endl;
    }
}