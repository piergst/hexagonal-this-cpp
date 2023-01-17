#ifndef POETRYLIBRARY_H
#define POETRYLIBRARY_H
#include "iobtainpoems.h"


// Adapters for right side port
class PoetryLibrary: public IObtainPoems
{
public: 
  std::string getMeAPoem() const override {
    return "If you could read a leaf or tree\r\nyou’d have no need of books.\r\n-- © Alistair Cockburn (1987)";  
  } 
}; 

class HardCodedPoetryLibrary: public IObtainPoems 
{
public: 
  std::string getMeAPoem() const override {
    return "I want to sleep\r\nSwat the flies\r\nSoftly, please.\r\n\r\n-- Masaoka Shiki (1867-1902)";  
  } 
}; 

#endif