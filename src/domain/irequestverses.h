#ifndef IREQUESTVERSES_H
#define IREQUESTVERSES_H

// Interface for left side port
class IRequestVerses
{
public:
    virtual std::string giveMeSomePoetry() const = 0; 
};

#endif