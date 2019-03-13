#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <string>
#include <vector>
#include <set>

#include "signal.hpp"

class Message {
  typeef std::vector<Signal> signals_t;
  std::uint32_t id;
  std::string name;
  std::size_t dlc;  //0~8 bytes
  std::string from;
  signals_t signals;

public:
  typedef signals_t::const_iterator const_iterator;
  std::uint32_t getId() const {return id;}
  std::string getName() const {return name;}
  std::size_t getDlc() const {return dlc;}
  std::string getFrom() const {return from;}
  std::set<std::string> getTo() const;
  const_iterator begin() const {return signals.begin();}
  const_iterator end() const {return signals.end();}
};

#endif
