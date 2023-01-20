#ifndef IOBTAINPOEMS_H
#define IOBTAINPOEMS_H

// Interface for right side port
class IObtainPoems {
 public:
  virtual std::string getMeAPoem() const = 0;
};

#endif