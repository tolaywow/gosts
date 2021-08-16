#pragma once
#include "Icrypto.h"

class GrassHopper :
    public Icrypto<unsigned __int8*>
{
public:

    GrassHopper(unsigned __int8* key=0);
    virtual void Encrypt(unsigned __int8* block);
    virtual void Decrypt(unsigned __int8* block);
    virtual void key_reNew(unsigned __int8* key);
    virtual ~GrassHopper();
protected:
    unsigned __int8* key;
    unsigned __int8 keys[0xa0];
    virtual unsigned __int8 l(unsigned __int8* block);
    virtual void S(unsigned __int8* block);
    virtual void L(unsigned __int8* block);//have no method R, therefore L=16R
    virtual void X(unsigned __int8* key, unsigned __int8* block);
    virtual void notS(unsigned __int8* block);
    virtual void notL(unsigned __int8* block);
    virtual void generation_of_keys();
};



