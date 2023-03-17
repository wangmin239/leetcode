







#define IS_EXTENSION_ID(byte)  (((byte) & ASN_EXTENSION_ID) == ASN_EXTENSION_ID)

struct counter64 {
#if     __SIZEOF_POINTER__ == 4   
        unsigned long        high;
        unsigned long        low;
#elif   __SIZEOF_POINTER__ == 8
        unsigned int         high;
        unsigned int         low;
#endif
};