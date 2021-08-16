#pragma once
#include "Icrypto.h"
template<class T>
class Icrypto_chaining :
    public Icrypto<T>
{
public:
    virtual void cr_chaining_encrypt(T init_val, T blocks)=0;
    virtual void cr_chaining_decrypt(T init_val, T blocks) = 0;
protected:
    virtual void R_IV() = 0;
    virtual void split_IV() = 0;
    virtual void X(T init_val_after_Ts, T block) = 0;
};

