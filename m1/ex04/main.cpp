#include <iostream>
#include <fstream>
#include <string>

void	replaceOccurencesInLine(std::string &line, const std::string &to_replace, const std::string &new_str)
{
	std::string	new_line;
	size_t		pos;
	size_t		found_id;

	if (to_replace.empty())
		return ;
	pos = 0;
	while (1)
	{
		found_id = line.find(to_replace, pos);
		if (found_id == std::string::npos)
			break ;
		new_line.append(line, pos, found_id - pos);
		new_line.append(new_str);
		pos = found_id + to_replace.length();
	}
	new_line.append(line, pos, std::string::npos);
	line = new_line;
}

void	replaceInFile(std::ifstream &src, std::ofstream &dst, char **argv)
{
	std::string	line;

	while (std::getline(src, line))
	{
		replaceOccurencesInLine(line, argv[2], argv[3]);
		dst << line;
		if (!src.eof())
			dst << "\n";
	}
}

int	main(int argc, char *argv[])
{
	std::string		new_filename;

	if (argc != 4)
		return (1);

	new_filename = ((std::string) argv[1]).append(".replace");
	std::ifstream src_file(argv[1]);

	if (!src_file.is_open())
	{
		std::cout << "Error : file cannot be opened" << std::endl;
		return (1);
	}
	std::ofstream dst_file(new_filename.c_str());
	if (!dst_file.is_open())
	{
		std::cout << "Error : .replace file cannot be opened" << std::endl;
		return (1);
	}
	replaceInFile(src_file, dst_file, argv);
	return (0);
}

