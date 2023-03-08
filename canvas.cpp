#include "canvas.h"
#include<STDARG.H>
#include<iostream>

using namespace std;

Canvas::Canvas(int lines, int columns)
{
	Lines = lines;
	Columns = columns;
    Canvas:clear();
}
void Canvas::set_pixel(int x, int y, char value)
{
	matrix[x][y] = value;
}


void Canvas::set_pixels(int count, ...)
{
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; ++i)
	{
		int x = va_arg(args, int);
		int y = va_arg(args, int);
		char v = va_arg(args, char);
		Canvas::set_pixel(x, y, v);
	}

	va_end(args);
}

void Canvas::clear()
{
	for (int i = 1; i <= Lines; i++)
		for (int j = 1; j <= Columns; j++)
			matrix[i][j] = 32;
}

void Canvas::print() const
{
	for (int i = 1; i <= Lines; i++)
	{
		for (int j = 1; j <= Columns; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}

}