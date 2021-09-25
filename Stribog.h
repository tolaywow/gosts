#pragma once
#include"ISignature.h"

namespace strb_const
{
    unsigned __int8 tetta[] = {
        0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38,
        0x01, 0x09, 0x11, 0x19, 0x21, 0x29, 0x31, 0x39,
        0x02, 0x0a, 0x12, 0x1a, 0x22, 0x2a, 0x32, 0x3a,
        0x03, 0x0b, 0x13, 0x1b, 0x23, 0x2b, 0x33, 0x3b,
        0x04, 0x0c, 0x14, 0x1c, 0x24, 0x2c, 0x34, 0x3c,
        0x05, 0x0d, 0x15, 0x1d, 0x25, 0x2d, 0x35, 0x3d,
        0x06, 0x0e, 0x16, 0x1e, 0x26, 0x2e, 0x36, 0x3e,
        0x07, 0x0f, 0x17, 0x1f, 0x27, 0x2f, 0x37, 0x3f
    };

    unsigned __int64 A[] = {
        0x8e20faa72ba0b470, 0x47107ddd9b505a38, 0xad08b0e0c3282d1c, 0xd8045870ef14980e,
        0x6c022c38f90a4c07, 0x3601161cf205268d, 0x1b8e0b0e798c13c8, 0x83478b07b2468764,
        0xa011d380818e8f40, 0x5086e740ce47c920, 0x2843fd2067adea10, 0x14aff010bdd87508,
        0x0ad97808d06cb404, 0x05e23c0468365a02, 0x8c711e02341b2d01, 0x46b60f011a83988e,
        0x90dab52a387ae76f, 0x486dd4151c3dfdb9, 0x24b86a840e90f0d2, 0x125c354207487869,
        0x092e94218d243cba, 0x8a174a9ec8121e5d, 0x4585254f64090fa0, 0xaccc9ca9328a8950,
        0x9d4df05d5f661451, 0xc0a878a0a1330aa6, 0x60543c50de970553, 0x302a1e286fc58ca7,
        0x18150f14b9ec46dd, 0x0c84890ad27623e0, 0x0642ca05693b9f70, 0x0321658cba93c138,
        0x86275df09ce8aaa8, 0x439da0784e745554, 0xafc0503c273aa42a, 0xd960281e9d1d5215,
        0xe230140fc0802984, 0x71180a8960409a42, 0xb60c05ca30204d21, 0x5b068c651810a89e,
        0x456c34887a3805b9, 0xac361a443d1c8cd2, 0x561b0d22900e4669, 0x2b838811480723ba,
        0x9bcf4486248d9f5d, 0xc3e9224312c8c1a0, 0xeffa11af0964ee50, 0xf97d86d98a327728,
        0xe4fa2054a80b329c, 0x727d102a548b194e, 0x39b008152acb8227, 0x9258048415eb419d,
        0x492c024284fbaec0, 0xaa16012142f35760, 0x550b8e9e21f7a530, 0xa48b474f9ef5dc18,
        0x70a6a56e2440598e, 0x3853dc371220a247, 0x1ca76e95091051ad, 0x0edd37c48a08a6d8,
        0x07e095624504536c, 0x8d70c431ac02a736, 0xc83862965601dd1b, 0x641c314b2b8ee083
    };
}

class Stribog :
    public ISignature<unsigned __int8*>
{
public:
    virtual void form_signature(unsigned __int8* message, unsigned __int8* signature, unsigned __int8* key);
    virtual bool verification_signature(unsigned __int8* message, unsigned __int8* signature, unsigned __int8* key);
    Stribog(unsigned __int16* size = 0);
    Stribog();
    ~Stribog();
protected:
    virtual unsigned __int64 multiplicate(unsigned __int64* b);
    virtual void X(unsigned __int8* key, unsigned __int8* block);//X512
    virtual void S(unsigned __int8* block);//S512
    virtual void P(unsigned __int8* block);//P512
    virtual void gN(unsigned __int8* h, unsigned __int8* m);//TODO
    unsigned __int8* IV;
    /*unsigned __int8* h;
    unsigned __int8 N[0x40] = { 0 };
    unsigned __int8 Esumm[0x40] = { 0 };*/
};
