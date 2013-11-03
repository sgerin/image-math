#ifndef HISTOGRAMME_H_
#define HISTOGRAMME_H_

#include "Image.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

class Histogramme
{
public:
	Histogramme();
	Histogramme(const Image&);
	Histogramme(std::string);
	Histogramme(const Histogramme&);
	~Histogramme();
	
	std::vector<unsigned int> get_values() const;
	unsigned int get_value(unsigned int) const;
	void set_value(unsigned int, unsigned int);
	void write_to_file(std::string) const;
	unsigned int get_max_value() const; 
	unsigned int get_min_value() const; 
 	
	
private:
	std::vector<unsigned int> values;
	unsigned int max_value; 
	unsigned int min_value; 
};

#endif
