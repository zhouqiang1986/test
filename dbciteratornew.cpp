/*
 * dbctree.cpp
 *
 *  Created on: 04.10.2013
 *      Author: downtimes
 */

#include "header/dbciterator.hpp"

#include <dirent.h>
#include <iostream>
#include <regex>
#include <string>
#include <limits>
#include <fstream>
#include <stdexcept>

DBCIterator::DBCIterator(const std::string& filePath) {

	getFiles(filePath);
	/*
	std::ifstream file(filePath);
	if (file) {
		init(file);
	} else {
		throw std::invalid_argument("The File could not be opened");
	}
	file.close(); */
}

DBCIterator::DBCIterator(std::istream& stream) {
	init(stream);
}

void DBCIterator::getFiles(const std::string& path) {
	//fileList.clear;
	DIR *dp;
	struct dirent *dirp;
	if((dp = opendir(path.c_str())) == NULL)
	{
		std::cout << "Can not open dir:" << path << std::endl;
		return ;
	}
	std::regex reg_obj(".dbc", std::regex::icase);
	while((dirp = readdir(dp)) != NULL)
	{
		if( strcmp( dirp->d_name , "." ) == 0 ||
				strcmp( dirp->d_name , "..") == 0    )
			continue;
			std::string sFilename(dirp->d_name);
	    std::string suffixStr = sFilename.substr(sFilename.find_last_of('.') + 1);//获取文件后缀

	        if (suffixStr.compare(".dbc") == 0) {//根据后缀筛选文件

	            std::cout<< dirp->d_name <<std::endl;
	            //++number;
	        }
					/*
		if(dirp -> d_type == 8) // 4 means catalog; 8 means file; 0 means unknown
		{
			if(std::regex_match(dirp->d_name, reg_obj))
			{
				//                cout << dirp->d_name << endl;
				std::string all_path = path + dirp->d_name;
				fileList.push_back(all_path);
				std::cout << dirp->d_name << " " << dirp->d_ino << " " << dirp->d_off << " " << dirp->d_reclen << " " << dirp->d_type << std::endl;
			}
			else
			{
				std::cout << "dir has not dbc files" << std::endl;
			}
		}
		else
		{
			std::cout << "dir is empty" << std::endl;
		}*/
	}
	closedir(dp);

}

void DBCIterator::init(std::istream& stream) {
	messageList.clear();
	std::vector<Message> messages;
	do {
		Message msg;
		stream >> msg;
		if (stream.fail()) {
			stream.clear();
			stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			messages.push_back(msg);
		}
	} while (!stream.eof());
	messageList.insert(messageList.begin(), messages.begin(), messages.end());
}
