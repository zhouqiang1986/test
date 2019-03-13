#ifndef SIGNAL_HPP_
#define SIGNAL_HPP_

#include <string>
#include <set>

enum class ByteOrder {
  MOTOROLA,
  INTEL
};

enum class Sign {
  UNSIGNED,
  SIGNED
};

enum class Multiplexor {
  NONE,
  MULTIPLEXED,
  MULTIPLEXOR
};

class Signal {
  typedef std::set<std::string> toList;
  std::string name;   //The name of the SIGNAL
  unsigned short startBit;    //start bit   0~63
  unsigned short length;    //Signal size   1~64
  ByteOrder order;    //ByteOrder
  Sign sign;
  double factor;    //Physical value: phys = digits * factor + offset
  double offset;
  double minimum;
  double maximum;
  std::string unit;
  Multiplexor Multiplexor;
  unsigned short multiplexNum;
  toList to;

public:
  std::string getName() const {return name;}
  unsigned short getStartbit() const {return startBit;}
  unsigned short getLength() const {return length;}
  ByteOrder getByteOrder() const {return order;}
  Sign getSign() const {return sign;}
  double getFactor() const {return factor;}
  double getOffset() const {return offset;}
  double getMinimum() const {return minimum;}
  double getMaximum() const {return maximum;}
  std::string getUnit() const {return unit;}
  Multiplexor getMultiplexor() const {return multiplexor;}
  unsigned short getMultiplexedNumber() const {return multiplexNum;}
  toList getTo() const {return to;}

};
#endif
