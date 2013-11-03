#include "Histogramme.h"


Histogramme::Histogramme()
{
	min_value = 0; 
	max_value = 255;
	values = std::vector<unsigned int>(max_value, 0);
	//values = new int[0];
}

Histogramme::Histogramme(const Image& img)
{
	min_value = 0; 
	max_value = img.get_max_value();
	values = std::vector<unsigned int>(max_value, 0);
	
	for(int i=0; i<img.get_lines()*img.get_columns(); ++i)
	{
		int val = img.get_pixel(i);
		++values.at(val);
	}
}

Histogramme::Histogramme(std::string s)
{
	std::fstream file;
	file.open(s.c_str(), std::fstream::out|std::fstream::in);
	std::string line; 
	//int i = 0;
	//int j = 0;
	if(file.is_open())
	{
		while(getline(file, line))
		{
		    std::istringstream iss(line);
			std::vector<std::string> tokens;
			copy(std::istream_iterator<std::string>(iss),
				std::istream_iterator<std::string>(),
				std::back_inserter<std::vector<std::string> >(tokens));
			//for(unsigned int j=0; j<tokens.size(); ++j)
			//{
			//	std::cout << tokens[j] << std::endl;
				//}
			if(tokens.size() != 2)
			{
				std::cout << "Values don't match when reading Histogramme from file. Program will exit" << std::endl;
				exit(1);
			}				
			//std::stringstream(tokens[0]) >> columns;
			int val = 0;
			std::stringstream(tokens[1]) >> val;
			values.push_back(val);
		}
		max_value = values.size()-1;
		min_value = 0;
	}
	else
	{
		std::cout << "Couldn't read Histogramme file. Program will exit" << std::endl;
		exit(1);
	}
}

Histogramme::Histogramme(const Histogramme& histo)
{
	min_value = histo.get_min_value();
	max_value = histo.get_max_value();
	values = histo.get_values();
	
}

Histogramme::~Histogramme()
{
}

std::vector<unsigned int> Histogramme::get_values() const
{
	return values; 
}

unsigned int Histogramme::get_value(unsigned int i) const
{
	if(i>=0 && i<values.size())
		return values[i];
	else
		return 0;
}

void Histogramme::set_value(unsigned int i, unsigned int v)
{
	if(i>=0 && i<values.size())
		values[i] = v;
}

void Histogramme::write_to_file(std::string s) const
{
	std::fstream file;
	file.open(s.c_str(), std::fstream::out);
	if(file.is_open())
	{
		for(unsigned int i=min_value; i<=max_value; ++i)
		{
			file << i << " " << values[i] << std::endl; 
		}
	}
}

unsigned int Histogramme::get_max_value() const
{
	return max_value;
}

unsigned int Histogramme::get_min_value() const
{
	return min_value;
}
