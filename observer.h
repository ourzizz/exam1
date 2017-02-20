#ifndef OBSERVER_H
#define OBSERVER_H
#include "status.h"
class Observer
{
    public:
        virtual void loadpage(Status *sts)=0;
};
#endif
