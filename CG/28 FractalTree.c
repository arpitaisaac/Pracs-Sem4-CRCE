#include<Windows.h>
#include<GL/gl.h>
#include<GL/GLU.h>
#include<gl/glut.h>

#include <stdio.h>
#include <math.h>
void WriteFunctionName ()
{
   //Use pixel plotting in glBegin and glEnd
   glBegin (GL_POINTS);
   //glVertex2f(x,y); //Sample for ploting pixel at (x,y)
   glEnd ();
}
double DegreeToRadians (double angle)
{
   return (angle * 3.14159) / 180.0;
}
void DrawFractalTree (int x0, int y0, int length, int angle, int count)
{
   int xn = x0 + length * cos (DegreeToRadians (angle));
   int yn = y0 + length * sin (DegreeToRadians (angle));
   if (count == 5)
      return;
   glBegin (GL_LINES);
   glVertex2i (x0, y0);
   glVertex2i (xn, yn);
   glEnd ();
   printf ("%d %d\n", x0, y0);
   // Draw Next Line at 30
   DrawFractalTree (xn, yn, length * 0.6, angle + 30, count + 1);
   DrawFractalTree (xn, yn, length * 0.6, angle + 60, count + 1);
   DrawFractalTree (xn, yn, length * 0.6, angle - 30, count + 1);
   DrawFractalTree (xn, yn, length * 0.6, angle - 60, count + 1);
   //   DrawFractalTree (xn, yn, length, -45);
}
void disp ()
{
   glClearColor (1, 1, 1, 1);
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (0, 0, 0);
   //call your function define at beginning
   //for example WriteFunctionName();
   DrawFractalTree (0, 0, 45, 90, 0);
   glFlush ();
}//disp
int main (int argv, char** argc)
{
   glutInit (&argv, argc);
   glutInitWindowSize (300, 300);
   glutCreateWindow ("window");
   gluOrtho2D (-150, 150, -150, 150);
   glutDisplayFunc (disp);
   glutMainLoop ();
   return 0;
}