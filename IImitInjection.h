#pragma once
#include "Icrypto.h"

template<class T>
class IImitInjection :
    public Icrypto<T>
{
public:
    virtual void ImitInjection(T blocks,T result) = 0;
protected:
    virtual void Ts() = 0;
};