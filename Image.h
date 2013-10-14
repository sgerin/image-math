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
	
	int get_pixel(int, int) const;
	int get_pixel(int) const;
	void set_pixel(int, int, int);
	void write_to_file(std::string) const;
	int get_lines() const;
	int get_columns() const; 
	int get_max_value() const; 
	int get_min_value() const; 
	
	
private:
	int* pixels;
	int lines;
	int columns; 
	int max_value; 
	int min_value; 
};

#endif