#pragma once
#include "Icrypto.h"

class Magma :
    public Icrypto<unsigned __int64*>
{
public:
    Magma(unsigned __int32* new_key = 0, unsigned __int8* substitution = 0);

    virtual void Encrypt(unsigned __int64*);
    virtual void Decrypt(unsigned __int64*);
    virtual void substitutions_reNew(unsigned __int8* substitutions);
    virtual void keys_reNew(unsigned __int32* new_keys);

protected:
    unsigned __int32* keys;
    unsigned __int8* subst;

    virtual void init(unsigned __int32* new_key, unsigned __int8* substitution);
    virtual void t(unsigned __int32* block);
    virtual void g(unsigned __int32* block, unsigned __int32* key);
    virtual void G(unsigned __int32* blocks, unsigned __int32* key);
    virtual void Gx(unsigned __int64* block, unsigned __int32* key);
};
