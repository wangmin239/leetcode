







#define IS_EXTENSION_ID(byte)  (((byte) & ASN_EXTENSION_ID) == ASN_EXTENSION_ID)

struct counter64 {
    unsigned long        high;
    unsigned long        low;
};