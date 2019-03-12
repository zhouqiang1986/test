#include <iostream>
#include <stdexcept>

#include "header/dbciterator.hpp"

const std::string usage = ""
        "example:\n"
        "   ./dbcparser  dbc_directory\n"
        "   dbc_directory means the filePath of dbc files\n";

int main(int argc, char *argv[])
{
  if(argc < 2) {
    std::cout << usage << std::endl;
    return 0;
  }

  try {
    DBCIterator dbc(argv[1]);
  } catch (std::invalid_argument& ex) {
    std::cout << ex.what() << std::endl;
  }

}
