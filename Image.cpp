#include "Image.h"

Image::Image()
{
	lines = 0; 
	columns = 0; 
	min_value = 0;
	max_value = 255; 
	pixels = new int[lines*columns];
}

Image::Image(std::string)
{
	
}

Image::Image(const Image& image)
{
	lines = image.get_lines();
	columns = image.get_columns();
	min_value = image.get_min_value();
	max_value = image.get_max_value();
	for(int i=0; i<lines*columns; ++i)
	{
		pixels[i] = image.get_pixel(i);
	}
}

Image::~Image()
{
	delete[] pixels; 
}


int Image::get_pixel(int i)
{
	if(height < columns * height)
		return pixels[i];
	else
		return -1;
}

int Image::get_pixel(int height, int width)
{
	if(height <= lines && width <= columns && height > 0 && width > 0)
		return pixels[columns*height-1 + width-1];
	else
		return -1;		
}

void Image::set_pixel(int height, int width, int value)
{
	if(height <= lines && width <= columns && height > 0 && width > 0)
	{
		if(value > max_value)
		{
			pixels[columns*height-1 + width-1] = max_value;
		}
		else if(value < min_value)
		{
			pixels[columns*height-1 + width-1] = min_value;
		}
		else
		{
			pixels[columns*height-1 + width-1] = value;
		}
	}
}

void Image::write_to_file(std::string)
{
}

int Image::get_lines()
{
	return lines; 
}

int Image::get_columns()
{
	return columns; 
} 

int Image::get_max_value()
{
	return max_value;
}

int Image::get_min_value()
{
	return min_value; 
}
