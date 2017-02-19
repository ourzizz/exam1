#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
class SubJect
{
    public:
        virtual void Attach(Observer *)=0;
        virtual void Detach(Observer *)=0;
        virtual void Notify(bool *)=0;
};
#endif
