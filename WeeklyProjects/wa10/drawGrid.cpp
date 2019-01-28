#include "drawGrid.h"

/// Draw a filled rectangle.  The filled parameter choses filled or unfilled
void DrawRectangle( float x1, float y1, float x2, float y2, const float color[], bool filled )
{
    glColor3fv( color );
    if (filled)
       glBegin( GL_POLYGON );
    else
       glBegin( GL_LINE_LOOP );

    glVertex2f( x1, y1 );
    glVertex2f( x2, y1 );
    glVertex2f( x2, y2 );
    glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

/// Draw a text string in the window
void DrawTextString(std::string str, int x, int y, const float color[] )
{
    glColor3fv( color );
    glRasterPos2i( x, y );
    for (auto x : str)
       glutBitmapCharacter( GLUT_BITMAP_8_BY_13, x );
    glutSwapBuffers();
}

/// Draw an individual cell with it's status
void drawCell(int whichCell, CellStatus cs, int size)
{
    int sWidth = glutGet(GLUT_WINDOW_WIDTH);
    int sHeight = glutGet(GLUT_WINDOW_HEIGHT);

    unsigned int N = sqrt(size);
    int cellWidth = min((sHeight - 20)/N, (sWidth-20)/N);
    int cellHeight = cellWidth;

    int x = 10 + (whichCell % N)*cellWidth, y = 10 + (whichCell / N) * cellHeight;

    DrawRectangle(x, y, x+cellWidth, y+cellHeight, Colors[cs], true);
    if (cs == BLOCKED_CELL)
       DrawRectangle(x, y, x+cellWidth, y+cellHeight, Colors[OPEN_CELL]);
    else
       DrawRectangle(x, y, x+cellWidth, y+cellHeight, Colors[BLOCKED_CELL]);
}

/// Draw the entire grid
void drawGrid(vector<CellStatus> grid, DisjointSet& ds, int top_set, bool full)
{
    for (unsigned int i = 0 ; i < grid.size() ; i++)
    {
       if (full)
          drawCell(i, grid[i], grid.size());
       if (ds.findSet(i) == ds.findSet(top_set))
          drawCell(i, CONNECTED_CELL, grid.size());
    }

    if (full)
    {
        int sHeight = glutGet(GLUT_WINDOW_HEIGHT);
        int sWidth = glutGet(GLUT_WINDOW_WIDTH);
        unsigned int N = sqrt(grid.size());
        int cellWidth = min((sHeight - 20) / N, (sWidth-20)/N);
        int cellHeight = cellWidth;
        int x = cellWidth * N + 40;
        int y = sHeight / 2;
        DrawTextString("Blocked Cell", x+cellWidth*2, y+cellHeight/2, Colors[OPEN_CELL]);
        DrawRectangle(x, y, x+cellWidth, y+cellHeight, Colors[BLOCKED_CELL], true);
        DrawRectangle(x, y, x+cellWidth, y+cellHeight+1, Colors[OPEN_CELL]);
        DrawTextString("Open Cell", x+cellWidth*2, y+cellHeight*2+cellHeight/2, Colors[OPEN_CELL]);
        DrawRectangle(x, y+cellHeight*2, x+cellWidth, y+cellHeight*3, Colors[OPEN_CELL], true);
        DrawRectangle(x, y+cellHeight, x+cellWidth, y+cellHeight*2, Colors[BLOCKED_CELL]);
        DrawTextString("Connected Cell", x+cellWidth*2, y+cellHeight*4+cellHeight/2, Colors[OPEN_CELL]);
        DrawRectangle(x, y+cellHeight*4, x+cellWidth, y+cellHeight*5, Colors[CONNECTED_CELL], true);
        DrawRectangle(x, y+cellHeight*4, x+cellWidth, y+cellHeight*5, Colors[BLOCKED_CELL]);
    }
}
