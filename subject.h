#ifndef SUBJECT_H
#define SUBJECT_H
#include "status.h"
#include "observer.h"
class SubJect
{
    public:
        virtual void Attach(Observer *)=0;
        virtual void Detach(Observer *)=0;
        virtual void Notify()=0;
};
#endif
