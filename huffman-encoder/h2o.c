#include <stdint.h>


typedef struct {
    uint32_t nbits;
    uint32_t code;
} h2o_huff_sym;

static const h2o_huff_sym h2o_huff_sym_table[] = {
    {13, 0x1ff8u},    {23, 0x7fffd8u},   {28, 0xfffffe2u}, {28, 0xfffffe3u},  {28, 0xfffffe4u}, {28, 0xfffffe5u}, {28, 0xfffffe6u},
    {28, 0xfffffe7u}, {28, 0xfffffe8u},  {24, 0xffffeau},  {30, 0x3ffffffcu}, {28, 0xfffffe9u}, {28, 0xfffffeau}, {30, 0x3ffffffdu},
    {28, 0xfffffebu}, {28, 0xfffffecu},  {28, 0xfffffedu}, {28, 0xfffffeeu},  {28, 0xfffffefu}, {28, 0xffffff0u}, {28, 0xffffff1u},
    {28, 0xffffff2u}, {30, 0x3ffffffeu}, {28, 0xffffff3u}, {28, 0xffffff4u},  {28, 0xffffff5u}, {28, 0xffffff6u}, {28, 0xffffff7u},
    {28, 0xffffff8u}, {28, 0xffffff9u},  {28, 0xffffffau}, {28, 0xffffffbu},  {6, 0x14u},       {10, 0x3f8u},     {10, 0x3f9u},
    {12, 0xffau},     {13, 0x1ff9u},     {6, 0x15u},       {8, 0xf8u},        {11, 0x7fau},     {10, 0x3fau},     {10, 0x3fbu},
    {8, 0xf9u},       {11, 0x7fbu},      {8, 0xfau},       {6, 0x16u},        {6, 0x17u},       {6, 0x18u},       {5, 0x0u},
    {5, 0x1u},        {5, 0x2u},         {6, 0x19u},       {6, 0x1au},        {6, 0x1bu},       {6, 0x1cu},       {6, 0x1du},
    {6, 0x1eu},       {6, 0x1fu},        {7, 0x5cu},       {8, 0xfbu},        {15, 0x7ffcu},    {6, 0x20u},       {12, 0xffbu},
    {10, 0x3fcu},     {13, 0x1ffau},     {6, 0x21u},       {7, 0x5du},        {7, 0x5eu},       {7, 0x5fu},       {7, 0x60u},
    {7, 0x61u},       {7, 0x62u},        {7, 0x63u},       {7, 0x64u},        {7, 0x65u},       {7, 0x66u},       {7, 0x67u},
    {7, 0x68u},       {7, 0x69u},        {7, 0x6au},       {7, 0x6bu},        {7, 0x6cu},       {7, 0x6du},       {7, 0x6eu},
    {7, 0x6fu},       {7, 0x70u},        {7, 0x71u},       {7, 0x72u},        {8, 0xfcu},       {7, 0x73u},       {8, 0xfdu},
    {13, 0x1ffbu},    {19, 0x7fff0u},    {13, 0x1ffcu},    {14, 0x3ffcu},     {6, 0x22u},       {15, 0x7ffdu},    {5, 0x3u},
    {6, 0x23u},       {5, 0x4u},         {6, 0x24u},       {5, 0x5u},         {6, 0x25u},       {6, 0x26u},       {6, 0x27u},
    {5, 0x6u},        {7, 0x74u},        {7, 0x75u},       {6, 0x28u},        {6, 0x29u},       {6, 0x2au},       {5, 0x7u},
    {6, 0x2bu},       {7, 0x76u},        {6, 0x2cu},       {5, 0x8u},         {5, 0x9u},        {6, 0x2du},       {7, 0x77u},
    {7, 0x78u},       {7, 0x79u},        {7, 0x7au},       {7, 0x7bu},        {15, 0x7ffeu},    {11, 0x7fcu},     {14, 0x3ffdu},
    {13, 0x1ffdu},    {28, 0xffffffcu},  {20, 0xfffe6u},   {22, 0x3fffd2u},   {20, 0xfffe7u},   {20, 0xfffe8u},   {22, 0x3fffd3u},
    {22, 0x3fffd4u},  {22, 0x3fffd5u},   {23, 0x7fffd9u},  {22, 0x3fffd6u},   {23, 0x7fffdau},  {23, 0x7fffdbu},  {23, 0x7fffdcu},
    {23, 0x7fffddu},  {23, 0x7fffdeu},   {24, 0xffffebu},  {23, 0x7fffdfu},   {24, 0xffffecu},  {24, 0xffffedu},  {22, 0x3fffd7u},
    {23, 0x7fffe0u},  {24, 0xffffeeu},   {23, 0x7fffe1u},  {23, 0x7fffe2u},   {23, 0x7fffe3u},  {23, 0x7fffe4u},  {21, 0x1fffdcu},
    {22, 0x3fffd8u},  {23, 0x7fffe5u},   {22, 0x3fffd9u},  {23, 0x7fffe6u},   {23, 0x7fffe7u},  {24, 0xffffefu},  {22, 0x3fffdau},
    {21, 0x1fffddu},  {20, 0xfffe9u},    {22, 0x3fffdbu},  {22, 0x3fffdcu},   {23, 0x7fffe8u},  {23, 0x7fffe9u},  {21, 0x1fffdeu},
    {23, 0x7fffeau},  {22, 0x3fffddu},   {22, 0x3fffdeu},  {24, 0xfffff0u},   {21, 0x1fffdfu},  {22, 0x3fffdfu},  {23, 0x7fffebu},
    {23, 0x7fffecu},  {21, 0x1fffe0u},   {21, 0x1fffe1u},  {22, 0x3fffe0u},   {21, 0x1fffe2u},  {23, 0x7fffedu},  {22, 0x3fffe1u},
    {23, 0x7fffeeu},  {23, 0x7fffefu},   {20, 0xfffeau},   {22, 0x3fffe2u},   {22, 0x3fffe3u},  {22, 0x3fffe4u},  {23, 0x7ffff0u},
    {22, 0x3fffe5u},  {22, 0x3fffe6u},   {23, 0x7ffff1u},  {26, 0x3ffffe0u},  {26, 0x3ffffe1u}, {20, 0xfffebu},   {19, 0x7fff1u},
    {22, 0x3fffe7u},  {23, 0x7ffff2u},   {22, 0x3fffe8u},  {25, 0x1ffffecu},  {26, 0x3ffffe2u}, {26, 0x3ffffe3u}, {26, 0x3ffffe4u},
    {27, 0x7ffffdeu}, {27, 0x7ffffdfu},  {26, 0x3ffffe5u}, {24, 0xfffff1u},   {25, 0x1ffffedu}, {19, 0x7fff2u},   {21, 0x1fffe3u},
    {26, 0x3ffffe6u}, {27, 0x7ffffe0u},  {27, 0x7ffffe1u}, {26, 0x3ffffe7u},  {27, 0x7ffffe2u}, {24, 0xfffff2u},  {21, 0x1fffe4u},
    {21, 0x1fffe5u},  {26, 0x3ffffe8u},  {26, 0x3ffffe9u}, {28, 0xffffffdu},  {27, 0x7ffffe3u}, {27, 0x7ffffe4u}, {27, 0x7ffffe5u},
    {20, 0xfffecu},   {24, 0xfffff3u},   {20, 0xfffedu},   {21, 0x1fffe6u},   {22, 0x3fffe9u},  {21, 0x1fffe7u},  {21, 0x1fffe8u},
    {23, 0x7ffff3u},  {22, 0x3fffeau},   {22, 0x3fffebu},  {25, 0x1ffffeeu},  {25, 0x1ffffefu}, {24, 0xfffff4u},  {24, 0xfffff5u},
    {26, 0x3ffffeau}, {23, 0x7ffff4u},   {26, 0x3ffffebu}, {27, 0x7ffffe6u},  {26, 0x3ffffecu}, {26, 0x3ffffedu}, {27, 0x7ffffe7u},
    {27, 0x7ffffe8u}, {27, 0x7ffffe9u},  {27, 0x7ffffeau}, {27, 0x7ffffebu},  {28, 0xffffffeu}, {27, 0x7ffffecu}, {27, 0x7ffffedu},
    {27, 0x7ffffeeu}, {27, 0x7ffffefu},  {27, 0x7fffff0u}, {26, 0x3ffffeeu},  {30, 0x3fffffffu}};

int
h2o_hpack_encode_huffman(const uint8_t *src, int len, unsigned char *_dst, int UNUSED)
{
    uint8_t *dst = _dst, *dst_end = dst + len;
    const uint8_t *src_end = src + len;
    uint64_t bits = 0;
    int bits_left = 40;

    while (src != src_end) {
        const h2o_huff_sym *sym = h2o_huff_sym_table + *src++;
        bits |= (uint64_t)sym->code << (bits_left - sym->nbits);
        bits_left -= sym->nbits;
        while (bits_left <= 32) {
            *dst++ = bits >> 32;
            bits <<= 8;
            bits_left += 8;
            if (dst == dst_end) {
                return -1;
            }
        }
    }

    if (bits_left != 40) {
        bits |= ((uint64_t)1 << bits_left) - 1;
        *dst++ = bits >> 32;
    }
    if (dst == dst_end) {
        return -1;
    }

    return dst - _dst;
}
