#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>

class Image
{
public:
	Image();
	Image(std::string);
	Image(const Image&);
	~Image();
	
	int get_pixel(int, int);
	int get_pixel(int);
	void set_pixel(int, int, int);
	void write_to_file(std::string);
	int get_lines();
	int get_columns(); 
	int get_max_value(); 
	int get_min_value(); 
	
	
private:
	int* pixels;
	int lines;
	int columns; 
	int max_value; 
	int min_value; 
};

#endif