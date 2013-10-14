#ifndef IMAGE_H_
#define IMAGE_H_

#include <string>

class Image
{
public:
	Image();
	Image(std::string);
	Image(Image);
	~Image();
	
	int get_pixel(int, int);
	void set_pixel(int, int, int);
	void write_to_file(std::string);
	
	
private:
	int* pixels;
	int lines;
	int columns; 
	int max_value; 
	int min_value; 
};

#endif