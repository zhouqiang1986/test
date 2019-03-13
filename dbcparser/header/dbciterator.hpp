#ifndef DBCITERATOR_HPP_
#define DBCITERATOR_HPP_

#include <vector>

#include "message.hpp"

class DBCIterator {
  typedef std::vector<Message> messages_t;
  messages_t messageList;

public:
  typedef messages_t::const_iterator const_iterator;

  //explicit DBCIterator(std::istream& stream);

  const_iterator begin() const {return messageList.begin();}
  const_iterator end() const {return messageList.end();}

};

#endif
