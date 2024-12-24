#ifndef _SD3_Font_
#define _SD3_Font_

#include <pgmspace.h>

struct LineAtom
{
    unsigned xValue : 8; // X坐标
    unsigned yValue : 8; // Y坐标
    unsigned lValue : 8; // 长度
    LineAtom(int x, int y, int l) : xValue(x), yValue(y), lValue(l){};
};

const LineAtom _largeLineFont_0[]{
    LineAtom(10, 0, 16),
    LineAtom(8, 1, 20),
    LineAtom(6, 2, 24),
    LineAtom(5, 3, 26),
    LineAtom(4, 4, 28),
    LineAtom(3, 5, 30),
    LineAtom(2, 6, 32),
    LineAtom(2, 7, 10),
    LineAtom(24, 7, 10),
    LineAtom(1, 8, 9),
    LineAtom(26, 8, 9),
    LineAtom(1, 9, 8),
    LineAtom(27, 9, 8),
    LineAtom(0, 10, 8),
    LineAtom(28, 10, 8),
    LineAtom(0, 11, 8),
    LineAtom(28, 11, 8),
    LineAtom(0, 12, 7),
    LineAtom(29, 12, 7),
    LineAtom(0, 13, 7),
    LineAtom(29, 13, 7),
    LineAtom(0, 14, 7),
    LineAtom(29, 14, 7),
    LineAtom(0, 15, 7),
    LineAtom(29, 15, 7),
    LineAtom(0, 16, 7),
    LineAtom(29, 16, 7),
    LineAtom(0, 17, 7),
    LineAtom(29, 17, 7),
    LineAtom(0, 18, 7),
    LineAtom(29, 18, 7),
    LineAtom(0, 19, 7),
    LineAtom(29, 19, 7),
    LineAtom(0, 20, 7),
    LineAtom(29, 20, 7),
    LineAtom(0, 21, 7),
    LineAtom(29, 21, 7),
    LineAtom(0, 22, 7),
    LineAtom(29, 22, 7),
    LineAtom(0, 23, 7),
    LineAtom(29, 23, 7),
    LineAtom(0, 24, 7),
    LineAtom(29, 24, 7),
    LineAtom(0, 25, 7),
    LineAtom(29, 25, 7),
    LineAtom(0, 26, 7),
    LineAtom(29, 26, 7),
    LineAtom(0, 27, 7),
    LineAtom(29, 27, 7),
    LineAtom(0, 28, 7),
    LineAtom(29, 28, 7),
    LineAtom(0, 29, 7),
    LineAtom(29, 29, 7),
    LineAtom(0, 30, 7),
    LineAtom(29, 30, 7),
    LineAtom(0, 31, 7),
    LineAtom(29, 31, 7),
    LineAtom(0, 32, 7),
    LineAtom(29, 32, 7),
    LineAtom(0, 33, 7),
    LineAtom(29, 33, 7),
    LineAtom(0, 34, 7),
    LineAtom(29, 34, 7),
    LineAtom(0, 35, 7),
    LineAtom(29, 35, 7),
    LineAtom(0, 36, 7),
    LineAtom(29, 36, 7),
    LineAtom(0, 37, 7),
    LineAtom(29, 37, 7),
    LineAtom(0, 38, 7),
    LineAtom(29, 38, 7),
    LineAtom(0, 39, 7),
    LineAtom(29, 39, 7),
    LineAtom(0, 40, 7),
    LineAtom(29, 40, 7),
    LineAtom(0, 41, 7),
    LineAtom(29, 41, 7),
    LineAtom(0, 42, 7),
    LineAtom(29, 42, 7),
    LineAtom(0, 43, 7),
    LineAtom(29, 43, 7),
    LineAtom(0, 44, 7),
    LineAtom(29, 44, 7),
    LineAtom(0, 45, 7),
    LineAtom(29, 45, 7),
    LineAtom(0, 46, 7),
    LineAtom(29, 46, 7),
    LineAtom(0, 47, 7),
    LineAtom(29, 47, 7),
    LineAtom(0, 48, 8),
    LineAtom(28, 48, 8),
    LineAtom(0, 49, 8),
    LineAtom(28, 49, 8),
    LineAtom(1, 50, 8),
    LineAtom(27, 50, 8),
    LineAtom(1, 51, 9),
    LineAtom(26, 51, 9),
    LineAtom(2, 52, 10),
    LineAtom(24, 52, 10),
    LineAtom(2, 53, 32),
    LineAtom(3, 54, 30),
    LineAtom(4, 55, 28),
    LineAtom(5, 56, 26),
    LineAtom(6, 57, 24),
    LineAtom(8, 58, 20),
    LineAtom(10, 59, 16),
};
const LineAtom _largeLineFont_1[]{
    LineAtom(12, 0, 3),
    LineAtom(11, 1, 6),
    LineAtom(11, 2, 8),
    LineAtom(11, 3, 9),
    LineAtom(11, 4, 10),
    LineAtom(11, 5, 11),
    LineAtom(12, 6, 11),
    LineAtom(13, 7, 10),
    LineAtom(15, 8, 9),
    LineAtom(16, 9, 8),
    LineAtom(17, 10, 8),
    LineAtom(17, 11, 8),
    LineAtom(18, 12, 7),
    LineAtom(18, 13, 7),
    LineAtom(18, 14, 7),
    LineAtom(18, 15, 7),
    LineAtom(18, 16, 7),
    LineAtom(18, 17, 7),
    LineAtom(18, 18, 7),
    LineAtom(18, 19, 7),
    LineAtom(18, 20, 7),
    LineAtom(18, 21, 7),
    LineAtom(18, 22, 7),
    LineAtom(18, 23, 7),
    LineAtom(18, 24, 7),
    LineAtom(18, 25, 7),
    LineAtom(18, 26, 7),
    LineAtom(18, 27, 7),
    LineAtom(18, 28, 7),
    LineAtom(18, 29, 7),
    LineAtom(18, 30, 7),
    LineAtom(18, 31, 7),
    LineAtom(18, 32, 7),
    LineAtom(18, 33, 7),
    LineAtom(18, 34, 7),
    LineAtom(18, 35, 7),
    LineAtom(18, 36, 7),
    LineAtom(18, 37, 7),
    LineAtom(18, 38, 7),
    LineAtom(18, 39, 7),
    LineAtom(18, 40, 7),
    LineAtom(18, 41, 7),
    LineAtom(18, 42, 7),
    LineAtom(18, 43, 7),
    LineAtom(18, 44, 7),
    LineAtom(18, 45, 7),
    LineAtom(18, 46, 7),
    LineAtom(18, 47, 7),
    LineAtom(18, 48, 7),
    LineAtom(18, 49, 7),
    LineAtom(18, 50, 7),
    LineAtom(18, 51, 7),
    LineAtom(18, 52, 7),
    LineAtom(18, 53, 7),
    LineAtom(18, 54, 7),
    LineAtom(18, 55, 7),
    LineAtom(18, 56, 7),
    LineAtom(18, 57, 7),
    LineAtom(18, 58, 7),
    LineAtom(19, 59, 5),
};
const LineAtom _largeLineFont_2[]{
    LineAtom(1, 0, 25),
    LineAtom(0, 1, 28),
    LineAtom(0, 2, 30),
    LineAtom(0, 3, 31),
    LineAtom(0, 4, 32),
    LineAtom(0, 5, 33),
    LineAtom(1, 6, 33),
    LineAtom(24, 7, 10),
    LineAtom(26, 8, 9),
    LineAtom(27, 9, 8),
    LineAtom(28, 10, 8),
    LineAtom(28, 11, 8),
    LineAtom(29, 12, 7),
    LineAtom(29, 13, 7),
    LineAtom(29, 14, 7),
    LineAtom(29, 15, 7),
    LineAtom(29, 16, 7),
    LineAtom(29, 17, 7),
    LineAtom(29, 18, 7),
    LineAtom(29, 19, 7),
    LineAtom(29, 20, 7),
    LineAtom(29, 21, 7),
    LineAtom(29, 22, 7),
    LineAtom(28, 23, 8),
    LineAtom(28, 24, 8),
    LineAtom(27, 25, 8),
    LineAtom(26, 26, 9),
    LineAtom(24, 27, 10),
    LineAtom(10, 28, 24),
    LineAtom(8, 29, 25),
    LineAtom(6, 30, 26),
    LineAtom(5, 31, 26),
    LineAtom(4, 32, 26),
    LineAtom(3, 33, 25),
    LineAtom(2, 34, 24),
    LineAtom(2, 35, 10),
    LineAtom(1, 36, 9),
    LineAtom(1, 37, 8),
    LineAtom(0, 38, 8),
    LineAtom(0, 39, 8),
    LineAtom(0, 40, 7),
    LineAtom(0, 41, 7),
    LineAtom(0, 42, 7),
    LineAtom(0, 43, 7),
    LineAtom(0, 44, 7),
    LineAtom(0, 45, 7),
    LineAtom(0, 46, 7),
    LineAtom(0, 47, 7),
    LineAtom(0, 48, 7),
    LineAtom(0, 49, 7),
    LineAtom(0, 50, 7),
    LineAtom(0, 51, 7),
    LineAtom(0, 52, 7),
    LineAtom(0, 53, 35),
    LineAtom(0, 54, 36),
    LineAtom(0, 55, 36),
    LineAtom(0, 56, 36),
    LineAtom(0, 57, 36),
    LineAtom(0, 58, 36),
    LineAtom(0, 59, 35),
};
const LineAtom _largeLineFont_3[]{
    LineAtom(1, 0, 25),
    LineAtom(0, 1, 28),
    LineAtom(0, 2, 30),
    LineAtom(0, 3, 31),
    LineAtom(0, 4, 32),
    LineAtom(0, 5, 33),
    LineAtom(1, 6, 33),
    LineAtom(24, 7, 10),
    LineAtom(26, 8, 9),
    LineAtom(27, 9, 8),
    LineAtom(28, 10, 8),
    LineAtom(28, 11, 8),
    LineAtom(29, 12, 7),
    LineAtom(29, 13, 7),
    LineAtom(29, 14, 7),
    LineAtom(29, 15, 7),
    LineAtom(29, 16, 7),
    LineAtom(29, 17, 7),
    LineAtom(29, 18, 7),
    LineAtom(29, 19, 7),
    LineAtom(29, 20, 7),
    LineAtom(29, 21, 7),
    LineAtom(28, 22, 8),
    LineAtom(28, 23, 8),
    LineAtom(27, 24, 8),
    LineAtom(26, 25, 9),
    LineAtom(24, 26, 10),
    LineAtom(13, 27, 20),
    LineAtom(12, 28, 20),
    LineAtom(12, 29, 19),
    LineAtom(12, 30, 19),
    LineAtom(12, 31, 20),
    LineAtom(13, 32, 20),
    LineAtom(24, 33, 10),
    LineAtom(26, 34, 9),
    LineAtom(27, 35, 8),
    LineAtom(28, 36, 8),
    LineAtom(28, 37, 8),
    LineAtom(29, 38, 7),
    LineAtom(29, 39, 7),
    LineAtom(29, 40, 7),
    LineAtom(29, 41, 7),
    LineAtom(29, 42, 7),
    LineAtom(29, 43, 7),
    LineAtom(29, 44, 7),
    LineAtom(29, 45, 7),
    LineAtom(29, 46, 7),
    LineAtom(29, 47, 7),
    LineAtom(28, 48, 8),
    LineAtom(28, 49, 8),
    LineAtom(27, 50, 8),
    LineAtom(26, 51, 9),
    LineAtom(24, 52, 10),
    LineAtom(1, 53, 33),
    LineAtom(0, 54, 33),
    LineAtom(0, 55, 32),
    LineAtom(0, 56, 31),
    LineAtom(0, 57, 30),
    LineAtom(0, 58, 28),
    LineAtom(1, 59, 25),
};
const LineAtom _largeLineFont_4[]{
    LineAtom(1, 0, 5),
    LineAtom(27, 0, 5),
    LineAtom(0, 1, 7),
    LineAtom(26, 1, 7),
    LineAtom(0, 2, 7),
    LineAtom(26, 2, 7),
    LineAtom(0, 3, 7),
    LineAtom(26, 3, 7),
    LineAtom(0, 4, 7),
    LineAtom(26, 4, 7),
    LineAtom(0, 5, 7),
    LineAtom(26, 5, 7),
    LineAtom(0, 6, 7),
    LineAtom(26, 6, 7),
    LineAtom(0, 7, 7),
    LineAtom(26, 7, 7),
    LineAtom(0, 8, 7),
    LineAtom(26, 8, 7),
    LineAtom(0, 9, 7),
    LineAtom(26, 9, 7),
    LineAtom(0, 10, 7),
    LineAtom(26, 10, 7),
    LineAtom(0, 11, 7),
    LineAtom(26, 11, 7),
    LineAtom(0, 12, 7),
    LineAtom(26, 12, 7),
    LineAtom(0, 13, 7),
    LineAtom(26, 13, 7),
    LineAtom(0, 14, 7),
    LineAtom(26, 14, 7),
    LineAtom(0, 15, 7),
    LineAtom(26, 15, 7),
    LineAtom(0, 16, 7),
    LineAtom(26, 16, 7),
    LineAtom(0, 17, 7),
    LineAtom(26, 17, 7),
    LineAtom(0, 18, 7),
    LineAtom(26, 18, 7),
    LineAtom(0, 19, 7),
    LineAtom(26, 19, 7),
    LineAtom(0, 20, 7),
    LineAtom(26, 20, 7),
    LineAtom(0, 21, 7),
    LineAtom(26, 21, 7),
    LineAtom(0, 22, 7),
    LineAtom(26, 22, 7),
    LineAtom(0, 23, 7),
    LineAtom(26, 23, 7),
    LineAtom(0, 24, 7),
    LineAtom(26, 24, 7),
    LineAtom(0, 25, 7),
    LineAtom(26, 25, 7),
    LineAtom(0, 26, 7),
    LineAtom(26, 26, 7),
    LineAtom(0, 27, 7),
    LineAtom(26, 27, 7),
    LineAtom(0, 28, 7),
    LineAtom(26, 28, 7),
    LineAtom(0, 29, 7),
    LineAtom(26, 29, 7),
    LineAtom(0, 30, 7),
    LineAtom(26, 30, 7),
    LineAtom(0, 31, 7),
    LineAtom(26, 31, 7),
    LineAtom(0, 32, 7),
    LineAtom(26, 32, 7),
    LineAtom(0, 33, 8),
    LineAtom(26, 33, 7),
    LineAtom(0, 34, 8),
    LineAtom(26, 34, 7),
    LineAtom(1, 35, 8),
    LineAtom(26, 35, 7),
    LineAtom(1, 36, 9),
    LineAtom(26, 36, 7),
    LineAtom(2, 37, 10),
    LineAtom(26, 37, 7),
    LineAtom(2, 38, 33),
    LineAtom(3, 39, 33),
    LineAtom(4, 40, 32),
    LineAtom(5, 41, 31),
    LineAtom(6, 42, 30),
    LineAtom(8, 43, 28),
    LineAtom(10, 44, 25),
    LineAtom(26, 45, 7),
    LineAtom(26, 46, 7),
    LineAtom(26, 47, 7),
    LineAtom(26, 48, 7),
    LineAtom(26, 49, 7),
    LineAtom(26, 50, 7),
    LineAtom(26, 51, 7),
    LineAtom(26, 52, 7),
    LineAtom(26, 53, 7),
    LineAtom(26, 54, 7),
    LineAtom(26, 55, 7),
    LineAtom(26, 56, 7),
    LineAtom(26, 57, 7),
    LineAtom(26, 58, 7),
    LineAtom(27, 59, 5),
};
const LineAtom _largeLineFont_5[]{
    LineAtom(0, 0, 35),
    LineAtom(0, 1, 36),
    LineAtom(0, 2, 36),
    LineAtom(0, 3, 36),
    LineAtom(0, 4, 36),
    LineAtom(0, 5, 36),
    LineAtom(0, 6, 35),
    LineAtom(0, 7, 7),
    LineAtom(0, 8, 7),
    LineAtom(0, 9, 7),
    LineAtom(0, 10, 7),
    LineAtom(0, 11, 7),
    LineAtom(0, 12, 7),
    LineAtom(0, 13, 7),
    LineAtom(0, 14, 7),
    LineAtom(0, 15, 7),
    LineAtom(0, 16, 7),
    LineAtom(0, 17, 7),
    LineAtom(0, 18, 7),
    LineAtom(0, 19, 7),
    LineAtom(0, 20, 7),
    LineAtom(0, 21, 8),
    LineAtom(0, 22, 9),
    LineAtom(0, 23, 26),
    LineAtom(0, 24, 28),
    LineAtom(0, 25, 30),
    LineAtom(1, 26, 30),
    LineAtom(1, 27, 31),
    LineAtom(2, 28, 31),
    LineAtom(4, 29, 30),
    LineAtom(24, 30, 10),
    LineAtom(26, 31, 9),
    LineAtom(27, 32, 8),
    LineAtom(28, 33, 8),
    LineAtom(28, 34, 8),
    LineAtom(29, 35, 7),
    LineAtom(29, 36, 7),
    LineAtom(29, 37, 7),
    LineAtom(29, 38, 7),
    LineAtom(29, 39, 7),
    LineAtom(29, 40, 7),
    LineAtom(29, 41, 7),
    LineAtom(29, 42, 7),
    LineAtom(29, 43, 7),
    LineAtom(29, 44, 7),
    LineAtom(29, 45, 7),
    LineAtom(29, 46, 7),
    LineAtom(29, 47, 7),
    LineAtom(28, 48, 8),
    LineAtom(28, 49, 8),
    LineAtom(27, 50, 8),
    LineAtom(26, 51, 9),
    LineAtom(24, 52, 10),
    LineAtom(1, 53, 33),
    LineAtom(0, 54, 33),
    LineAtom(0, 55, 32),
    LineAtom(0, 56, 31),
    LineAtom(0, 57, 30),
    LineAtom(0, 58, 28),
    LineAtom(1, 59, 25),
};
const LineAtom _largeLineFont_6[]{
    LineAtom(10, 0, 25),
    LineAtom(8, 1, 28),
    LineAtom(6, 2, 30),
    LineAtom(5, 3, 31),
    LineAtom(4, 4, 32),
    LineAtom(3, 5, 33),
    LineAtom(2, 6, 33),
    LineAtom(2, 7, 10),
    LineAtom(1, 8, 9),
    LineAtom(1, 9, 8),
    LineAtom(0, 10, 8),
    LineAtom(0, 11, 8),
    LineAtom(0, 12, 7),
    LineAtom(0, 13, 7),
    LineAtom(0, 14, 7),
    LineAtom(0, 15, 7),
    LineAtom(0, 16, 7),
    LineAtom(0, 17, 7),
    LineAtom(0, 18, 7),
    LineAtom(0, 19, 7),
    LineAtom(0, 20, 7),
    LineAtom(0, 21, 7),
    LineAtom(0, 22, 7),
    LineAtom(0, 23, 26),
    LineAtom(0, 24, 28),
    LineAtom(0, 25, 30),
    LineAtom(0, 26, 31),
    LineAtom(0, 27, 32),
    LineAtom(0, 28, 33),
    LineAtom(0, 29, 34),
    LineAtom(0, 30, 12),
    LineAtom(24, 30, 10),
    LineAtom(0, 31, 10),
    LineAtom(26, 31, 9),
    LineAtom(0, 32, 9),
    LineAtom(27, 32, 8),
    LineAtom(0, 33, 8),
    LineAtom(28, 33, 8),
    LineAtom(0, 34, 8),
    LineAtom(28, 34, 8),
    LineAtom(0, 35, 7),
    LineAtom(29, 35, 7),
    LineAtom(0, 36, 7),
    LineAtom(29, 36, 7),
    LineAtom(0, 37, 7),
    LineAtom(29, 37, 7),
    LineAtom(0, 38, 7),
    LineAtom(29, 38, 7),
    LineAtom(0, 39, 7),
    LineAtom(29, 39, 7),
    LineAtom(0, 40, 7),
    LineAtom(29, 40, 7),
    LineAtom(0, 41, 7),
    LineAtom(29, 41, 7),
    LineAtom(0, 42, 7),
    LineAtom(29, 42, 7),
    LineAtom(0, 43, 7),
    LineAtom(29, 43, 7),
    LineAtom(0, 44, 7),
    LineAtom(29, 44, 7),
    LineAtom(0, 45, 7),
    LineAtom(29, 45, 7),
    LineAtom(0, 46, 7),
    LineAtom(29, 46, 7),
    LineAtom(0, 47, 7),
    LineAtom(29, 47, 7),
    LineAtom(0, 48, 7),
    LineAtom(29, 48, 7),
    LineAtom(0, 49, 8),
    LineAtom(28, 49, 8),
    LineAtom(0, 50, 8),
    LineAtom(28, 50, 8),
    LineAtom(1, 51, 8),
    LineAtom(27, 51, 8),
    LineAtom(1, 52, 9),
    LineAtom(26, 52, 9),
    LineAtom(2, 53, 10),
    LineAtom(24, 53, 10),
    LineAtom(2, 54, 32),
    LineAtom(3, 55, 30),
    LineAtom(4, 56, 28),
    LineAtom(5, 57, 26),
    LineAtom(6, 58, 24),
    LineAtom(8, 59, 20),
};
const LineAtom _largeLineFont_7[]{
    LineAtom(1, 0, 25),
    LineAtom(0, 1, 28),
    LineAtom(0, 2, 30),
    LineAtom(0, 3, 31),
    LineAtom(0, 4, 32),
    LineAtom(0, 5, 33),
    LineAtom(1, 6, 33),
    LineAtom(24, 7, 10),
    LineAtom(26, 8, 9),
    LineAtom(27, 9, 8),
    LineAtom(28, 10, 8),
    LineAtom(28, 11, 8),
    LineAtom(29, 12, 7),
    LineAtom(29, 13, 7),
    LineAtom(29, 14, 7),
    LineAtom(29, 15, 7),
    LineAtom(29, 16, 7),
    LineAtom(29, 17, 7),
    LineAtom(29, 18, 7),
    LineAtom(29, 19, 7),
    LineAtom(29, 20, 7),
    LineAtom(29, 21, 7),
    LineAtom(29, 22, 7),
    LineAtom(29, 23, 7),
    LineAtom(29, 24, 7),
    LineAtom(29, 25, 7),
    LineAtom(29, 26, 7),
    LineAtom(29, 27, 7),
    LineAtom(29, 28, 7),
    LineAtom(29, 29, 7),
    LineAtom(29, 30, 7),
    LineAtom(29, 31, 7),
    LineAtom(29, 32, 7),
    LineAtom(29, 33, 7),
    LineAtom(29, 34, 7),
    LineAtom(29, 35, 7),
    LineAtom(29, 36, 7),
    LineAtom(29, 37, 7),
    LineAtom(29, 38, 7),
    LineAtom(29, 39, 7),
    LineAtom(29, 40, 7),
    LineAtom(29, 41, 7),
    LineAtom(29, 42, 7),
    LineAtom(29, 43, 7),
    LineAtom(29, 44, 7),
    LineAtom(29, 45, 7),
    LineAtom(29, 46, 7),
    LineAtom(29, 47, 7),
    LineAtom(29, 48, 7),
    LineAtom(29, 49, 7),
    LineAtom(29, 50, 7),
    LineAtom(29, 51, 7),
    LineAtom(29, 52, 7),
    LineAtom(29, 53, 7),
    LineAtom(29, 54, 7),
    LineAtom(29, 55, 7),
    LineAtom(29, 56, 7),
    LineAtom(29, 57, 7),
    LineAtom(29, 58, 7),
    LineAtom(30, 59, 5),
};
const LineAtom _largeLineFont_8[]{
    LineAtom(10, 0, 16),
    LineAtom(8, 1, 20),
    LineAtom(6, 2, 24),
    LineAtom(5, 3, 26),
    LineAtom(4, 4, 28),
    LineAtom(3, 5, 30),
    LineAtom(2, 6, 32),
    LineAtom(2, 7, 10),
    LineAtom(24, 7, 10),
    LineAtom(1, 8, 9),
    LineAtom(26, 8, 9),
    LineAtom(1, 9, 8),
    LineAtom(27, 9, 8),
    LineAtom(0, 10, 8),
    LineAtom(28, 10, 8),
    LineAtom(0, 11, 8),
    LineAtom(28, 11, 8),
    LineAtom(0, 12, 7),
    LineAtom(29, 12, 7),
    LineAtom(0, 13, 7),
    LineAtom(29, 13, 7),
    LineAtom(0, 14, 7),
    LineAtom(29, 14, 7),
    LineAtom(0, 15, 7),
    LineAtom(29, 15, 7),
    LineAtom(0, 16, 7),
    LineAtom(29, 16, 7),
    LineAtom(0, 17, 7),
    LineAtom(29, 17, 7),
    LineAtom(0, 18, 7),
    LineAtom(29, 18, 7),
    LineAtom(0, 19, 7),
    LineAtom(29, 19, 7),
    LineAtom(0, 20, 7),
    LineAtom(29, 20, 7),
    LineAtom(0, 21, 7),
    LineAtom(29, 21, 7),
    LineAtom(0, 22, 8),
    LineAtom(28, 22, 8),
    LineAtom(0, 23, 8),
    LineAtom(28, 23, 8),
    LineAtom(1, 24, 8),
    LineAtom(27, 24, 8),
    LineAtom(1, 25, 9),
    LineAtom(26, 25, 9),
    LineAtom(2, 26, 10),
    LineAtom(24, 26, 10),
    LineAtom(3, 27, 30),
    LineAtom(4, 28, 28),
    LineAtom(5, 29, 26),
    LineAtom(5, 30, 26),
    LineAtom(4, 31, 28),
    LineAtom(3, 32, 30),
    LineAtom(2, 33, 10),
    LineAtom(24, 33, 10),
    LineAtom(1, 34, 9),
    LineAtom(26, 34, 9),
    LineAtom(1, 35, 8),
    LineAtom(27, 35, 8),
    LineAtom(0, 36, 8),
    LineAtom(28, 36, 8),
    LineAtom(0, 37, 8),
    LineAtom(28, 37, 8),
    LineAtom(0, 38, 7),
    LineAtom(29, 38, 7),
    LineAtom(0, 39, 7),
    LineAtom(29, 39, 7),
    LineAtom(0, 40, 7),
    LineAtom(29, 40, 7),
    LineAtom(0, 41, 7),
    LineAtom(29, 41, 7),
    LineAtom(0, 42, 7),
    LineAtom(29, 42, 7),
    LineAtom(0, 43, 7),
    LineAtom(29, 43, 7),
    LineAtom(0, 44, 7),
    LineAtom(29, 44, 7),
    LineAtom(0, 45, 7),
    LineAtom(29, 45, 7),
    LineAtom(0, 46, 7),
    LineAtom(29, 46, 7),
    LineAtom(0, 47, 7),
    LineAtom(29, 47, 7),
    LineAtom(0, 48, 8),
    LineAtom(28, 48, 8),
    LineAtom(0, 49, 8),
    LineAtom(28, 49, 8),
    LineAtom(1, 50, 8),
    LineAtom(27, 50, 8),
    LineAtom(1, 51, 9),
    LineAtom(26, 51, 9),
    LineAtom(2, 52, 10),
    LineAtom(24, 52, 10),
    LineAtom(2, 53, 32),
    LineAtom(3, 54, 30),
    LineAtom(4, 55, 28),
    LineAtom(5, 56, 26),
    LineAtom(6, 57, 24),
    LineAtom(8, 58, 20),
    LineAtom(10, 59, 16),
};
const LineAtom _largeLineFont_9[]{
    LineAtom(8, 0, 20),
    LineAtom(6, 1, 24),
    LineAtom(5, 2, 26),
    LineAtom(4, 3, 28),
    LineAtom(3, 4, 30),
    LineAtom(2, 5, 32),
    LineAtom(2, 6, 10),
    LineAtom(24, 6, 10),
    LineAtom(1, 7, 9),
    LineAtom(26, 7, 9),
    LineAtom(1, 8, 8),
    LineAtom(27, 8, 8),
    LineAtom(0, 9, 8),
    LineAtom(28, 9, 8),
    LineAtom(0, 10, 8),
    LineAtom(28, 10, 8),
    LineAtom(0, 11, 7),
    LineAtom(29, 11, 7),
    LineAtom(0, 12, 7),
    LineAtom(29, 12, 7),
    LineAtom(0, 13, 7),
    LineAtom(29, 13, 7),
    LineAtom(0, 14, 7),
    LineAtom(29, 14, 7),
    LineAtom(0, 15, 7),
    LineAtom(29, 15, 7),
    LineAtom(0, 16, 7),
    LineAtom(29, 16, 7),
    LineAtom(0, 17, 7),
    LineAtom(29, 17, 7),
    LineAtom(0, 18, 7),
    LineAtom(29, 18, 7),
    LineAtom(0, 19, 7),
    LineAtom(29, 19, 7),
    LineAtom(0, 20, 7),
    LineAtom(29, 20, 7),
    LineAtom(0, 21, 7),
    LineAtom(29, 21, 7),
    LineAtom(0, 22, 7),
    LineAtom(29, 22, 7),
    LineAtom(0, 23, 7),
    LineAtom(29, 23, 7),
    LineAtom(0, 24, 7),
    LineAtom(29, 24, 7),
    LineAtom(0, 25, 8),
    LineAtom(28, 25, 8),
    LineAtom(0, 26, 8),
    LineAtom(28, 26, 8),
    LineAtom(1, 27, 8),
    LineAtom(27, 27, 9),
    LineAtom(1, 28, 9),
    LineAtom(26, 28, 10),
    LineAtom(2, 29, 10),
    LineAtom(24, 29, 12),
    LineAtom(2, 30, 34),
    LineAtom(3, 31, 33),
    LineAtom(4, 32, 32),
    LineAtom(5, 33, 31),
    LineAtom(6, 34, 30),
    LineAtom(8, 35, 28),
    LineAtom(10, 36, 26),
    LineAtom(29, 37, 7),
    LineAtom(29, 38, 7),
    LineAtom(29, 39, 7),
    LineAtom(29, 40, 7),
    LineAtom(29, 41, 7),
    LineAtom(29, 42, 7),
    LineAtom(29, 43, 7),
    LineAtom(29, 44, 7),
    LineAtom(29, 45, 7),
    LineAtom(29, 46, 7),
    LineAtom(29, 47, 7),
    LineAtom(28, 48, 8),
    LineAtom(28, 49, 8),
    LineAtom(27, 50, 8),
    LineAtom(26, 51, 9),
    LineAtom(24, 52, 10),
    LineAtom(1, 53, 33),
    LineAtom(0, 54, 33),
    LineAtom(0, 55, 32),
    LineAtom(0, 56, 31),
    LineAtom(0, 57, 30),
    LineAtom(0, 58, 28),
    LineAtom(1, 59, 25),
};

const LineAtom _smallLineFont_0[]{
    LineAtom(2, 0, 5),
    LineAtom(1, 1, 7),
    LineAtom(0, 2, 3),
    LineAtom(6, 2, 3),
    LineAtom(0, 3, 2),
    LineAtom(7, 3, 2),
    LineAtom(0, 4, 2),
    LineAtom(7, 4, 2),
    LineAtom(0, 5, 2),
    LineAtom(7, 5, 2),
    LineAtom(0, 6, 2),
    LineAtom(7, 6, 2),
    LineAtom(0, 7, 2),
    LineAtom(7, 7, 2),
    LineAtom(0, 8, 2),
    LineAtom(7, 8, 2),
    LineAtom(0, 9, 2),
    LineAtom(7, 9, 2),
    LineAtom(0, 10, 2),
    LineAtom(7, 10, 2),
    LineAtom(0, 11, 3),
    LineAtom(6, 11, 3),
    LineAtom(1, 12, 7),
    LineAtom(2, 13, 5),
};
const LineAtom _smallLineFont_1[]{
    LineAtom(5, 0, 3),
    LineAtom(5, 1, 4),
    LineAtom(6, 2, 3),
    LineAtom(7, 3, 2),
    LineAtom(7, 4, 2),
    LineAtom(7, 5, 2),
    LineAtom(7, 6, 2),
    LineAtom(7, 7, 2),
    LineAtom(7, 8, 2),
    LineAtom(7, 9, 2),
    LineAtom(7, 10, 2),
    LineAtom(7, 11, 2),
    LineAtom(7, 12, 2),
    LineAtom(7, 13, 2),
};
const LineAtom _smallLineFont_2[]{
    LineAtom(0, 0, 7),
    LineAtom(0, 1, 8),
    LineAtom(6, 2, 3),
    LineAtom(7, 3, 2),
    LineAtom(7, 4, 2),
    LineAtom(7, 5, 2),
    LineAtom(6, 6, 3),
    LineAtom(2, 7, 6),
    LineAtom(1, 8, 6),
    LineAtom(0, 9, 3),
    LineAtom(0, 10, 2),
    LineAtom(0, 11, 2),
    LineAtom(0, 12, 9),
    LineAtom(0, 13, 9),
};
const LineAtom _smallLineFont_3[]{
    LineAtom(0, 0, 7),
    LineAtom(0, 1, 8),
    LineAtom(6, 2, 3),
    LineAtom(7, 3, 2),
    LineAtom(7, 4, 2),
    LineAtom(6, 5, 3),
    LineAtom(2, 6, 6),
    LineAtom(2, 7, 6),
    LineAtom(6, 8, 3),
    LineAtom(7, 9, 2),
    LineAtom(7, 10, 2),
    LineAtom(6, 11, 3),
    LineAtom(0, 12, 8),
    LineAtom(0, 13, 7),
};
const LineAtom _smallLineFont_4[]{
    LineAtom(0, 0, 2),
    LineAtom(7, 0, 2),
    LineAtom(0, 1, 2),
    LineAtom(7, 1, 2),
    LineAtom(0, 2, 2),
    LineAtom(7, 2, 2),
    LineAtom(0, 3, 2),
    LineAtom(7, 3, 2),
    LineAtom(0, 4, 2),
    LineAtom(7, 4, 2),
    LineAtom(0, 5, 2),
    LineAtom(7, 5, 2),
    LineAtom(0, 6, 3),
    LineAtom(7, 6, 2),
    LineAtom(1, 7, 8),
    LineAtom(2, 8, 7),
    LineAtom(7, 9, 2),
    LineAtom(7, 10, 2),
    LineAtom(7, 11, 2),
    LineAtom(7, 12, 2),
    LineAtom(7, 13, 2),
};
const LineAtom _smallLineFont_5[]{
    LineAtom(0, 0, 9),
    LineAtom(0, 1, 9),
    LineAtom(0, 2, 2),
    LineAtom(0, 3, 2),
    LineAtom(0, 4, 2),
    LineAtom(0, 5, 7),
    LineAtom(0, 6, 8),
    LineAtom(6, 7, 3),
    LineAtom(7, 8, 2),
    LineAtom(7, 9, 2),
    LineAtom(7, 10, 2),
    LineAtom(6, 11, 3),
    LineAtom(0, 12, 8),
    LineAtom(0, 13, 7),
};
const LineAtom _smallLineFont_6[]{
    LineAtom(2, 0, 7),
    LineAtom(1, 1, 8),
    LineAtom(0, 2, 3),
    LineAtom(0, 3, 2),
    LineAtom(0, 4, 2),
    LineAtom(0, 5, 7),
    LineAtom(0, 6, 8),
    LineAtom(0, 7, 2),
    LineAtom(6, 7, 3),
    LineAtom(0, 8, 2),
    LineAtom(7, 8, 2),
    LineAtom(0, 9, 2),
    LineAtom(7, 9, 2),
    LineAtom(0, 10, 2),
    LineAtom(7, 10, 2),
    LineAtom(0, 11, 3),
    LineAtom(6, 11, 3),
    LineAtom(1, 12, 7),
    LineAtom(2, 13, 5),
};
const LineAtom _smallLineFont_7[]{
    LineAtom(0, 0, 7),
    LineAtom(0, 1, 8),
    LineAtom(6, 2, 3),
    LineAtom(7, 3, 2),
    LineAtom(7, 4, 2),
    LineAtom(7, 5, 2),
    LineAtom(7, 6, 2),
    LineAtom(7, 7, 2),
    LineAtom(7, 8, 2),
    LineAtom(7, 9, 2),
    LineAtom(7, 10, 2),
    LineAtom(7, 11, 2),
    LineAtom(7, 12, 2),
    LineAtom(7, 13, 2),
};
const LineAtom _smallLineFont_8[]{
    LineAtom(2, 0, 5),
    LineAtom(1, 1, 7),
    LineAtom(0, 2, 3),
    LineAtom(6, 2, 3),
    LineAtom(0, 3, 2),
    LineAtom(7, 3, 2),
    LineAtom(0, 4, 2),
    LineAtom(7, 4, 2),
    LineAtom(0, 5, 3),
    LineAtom(6, 5, 3),
    LineAtom(1, 6, 7),
    LineAtom(1, 7, 7),
    LineAtom(0, 8, 3),
    LineAtom(6, 8, 3),
    LineAtom(0, 9, 2),
    LineAtom(7, 9, 2),
    LineAtom(0, 10, 2),
    LineAtom(7, 10, 2),
    LineAtom(0, 11, 3),
    LineAtom(6, 11, 3),
    LineAtom(1, 12, 7),
    LineAtom(2, 13, 5),
};
const LineAtom _smallLineFont_9[]{
    LineAtom(2, 0, 5),
    LineAtom(1, 1, 7),
    LineAtom(0, 2, 3),
    LineAtom(6, 2, 3),
    LineAtom(0, 3, 2),
    LineAtom(7, 3, 2),
    LineAtom(0, 4, 2),
    LineAtom(7, 4, 2),
    LineAtom(0, 5, 2),
    LineAtom(7, 5, 2),
    LineAtom(0, 6, 3),
    LineAtom(7, 6, 2),
    LineAtom(1, 7, 8),
    LineAtom(2, 8, 7),
    LineAtom(7, 9, 2),
    LineAtom(7, 10, 2),
    LineAtom(6, 11, 3),
    LineAtom(0, 12, 8),
    LineAtom(0, 13, 7),
};

const LineAtom _middleLineFont_0[]{
    LineAtom(4, 0, 10),
    LineAtom(2, 1, 13),
    LineAtom(1, 2, 15),
    LineAtom(1, 3, 5),
    LineAtom(12, 3, 5),
    LineAtom(0, 4, 4),
    LineAtom(13, 4, 4),
    LineAtom(0, 5, 4),
    LineAtom(14, 5, 4),
    LineAtom(0, 6, 3),
    LineAtom(14, 6, 4),
    LineAtom(0, 7, 3),
    LineAtom(14, 7, 4),
    LineAtom(0, 8, 3),
    LineAtom(14, 8, 4),
    LineAtom(0, 9, 3),
    LineAtom(14, 9, 4),
    LineAtom(0, 10, 3),
    LineAtom(14, 10, 4),
    LineAtom(0, 11, 3),
    LineAtom(14, 11, 4),
    LineAtom(0, 12, 3),
    LineAtom(14, 12, 4),
    LineAtom(0, 13, 3),
    LineAtom(14, 13, 4),
    LineAtom(0, 14, 3),
    LineAtom(14, 14, 4),
    LineAtom(0, 15, 3),
    LineAtom(14, 15, 4),
    LineAtom(0, 16, 3),
    LineAtom(14, 16, 4),
    LineAtom(0, 17, 3),
    LineAtom(14, 17, 4),
    LineAtom(0, 18, 3),
    LineAtom(14, 18, 4),
    LineAtom(0, 19, 3),
    LineAtom(14, 19, 4),
    LineAtom(0, 20, 3),
    LineAtom(14, 20, 4),
    LineAtom(0, 21, 3),
    LineAtom(14, 21, 4),
    LineAtom(0, 22, 3),
    LineAtom(14, 22, 4),
    LineAtom(0, 23, 3),
    LineAtom(14, 23, 4),
    LineAtom(0, 24, 4),
    LineAtom(14, 24, 4),
    LineAtom(0, 25, 5),
    LineAtom(13, 25, 4),
    LineAtom(1, 26, 16),
    LineAtom(2, 27, 14),
    LineAtom(3, 28, 12),
    LineAtom(5, 29, 8),
};
const LineAtom _middleLineFont_1[]{
    LineAtom(5, 0, 3),
    LineAtom(5, 1, 5),
    LineAtom(5, 2, 6),
    LineAtom(6, 3, 5),
    LineAtom(8, 4, 4),
    LineAtom(8, 5, 4),
    LineAtom(9, 6, 3),
    LineAtom(9, 7, 3),
    LineAtom(9, 8, 3),
    LineAtom(9, 9, 3),
    LineAtom(9, 10, 3),
    LineAtom(9, 11, 3),
    LineAtom(9, 12, 3),
    LineAtom(9, 13, 3),
    LineAtom(9, 14, 3),
    LineAtom(9, 15, 3),
    LineAtom(9, 16, 3),
    LineAtom(9, 17, 3),
    LineAtom(9, 18, 3),
    LineAtom(9, 19, 3),
    LineAtom(9, 20, 3),
    LineAtom(9, 21, 3),
    LineAtom(9, 22, 3),
    LineAtom(9, 23, 3),
    LineAtom(9, 24, 3),
    LineAtom(9, 25, 3),
    LineAtom(9, 26, 3),
    LineAtom(9, 27, 3),
    LineAtom(9, 28, 3),
    LineAtom(9, 29, 3),
};
const LineAtom _middleLineFont_2[]{
    LineAtom(0, 0, 14),
    LineAtom(0, 1, 15),
    LineAtom(0, 2, 16),
    LineAtom(12, 3, 5),
    LineAtom(13, 4, 4),
    LineAtom(14, 5, 4),
    LineAtom(14, 6, 4),
    LineAtom(14, 7, 4),
    LineAtom(14, 8, 4),
    LineAtom(14, 9, 4),
    LineAtom(14, 10, 4),
    LineAtom(14, 11, 4),
    LineAtom(13, 12, 4),
    LineAtom(12, 13, 5),
    LineAtom(4, 14, 12),
    LineAtom(2, 15, 13),
    LineAtom(1, 16, 13),
    LineAtom(1, 17, 5),
    LineAtom(0, 18, 4),
    LineAtom(0, 19, 4),
    LineAtom(0, 20, 3),
    LineAtom(0, 21, 3),
    LineAtom(0, 22, 3),
    LineAtom(0, 23, 3),
    LineAtom(0, 24, 3),
    LineAtom(0, 25, 3),
    LineAtom(0, 26, 17),
    LineAtom(0, 27, 18),
    LineAtom(0, 28, 18),
    LineAtom(0, 29, 17),
};
const LineAtom _middleLineFont_3[]{
    LineAtom(0, 0, 14),
    LineAtom(0, 1, 15),
    LineAtom(0, 2, 16),
    LineAtom(12, 3, 5),
    LineAtom(13, 4, 4),
    LineAtom(14, 5, 4),
    LineAtom(14, 6, 4),
    LineAtom(14, 7, 4),
    LineAtom(14, 8, 4),
    LineAtom(14, 9, 4),
    LineAtom(14, 10, 4),
    LineAtom(14, 11, 4),
    LineAtom(13, 12, 4),
    LineAtom(6, 13, 10),
    LineAtom(6, 14, 9),
    LineAtom(6, 15, 10),
    LineAtom(12, 16, 5),
    LineAtom(13, 17, 4),
    LineAtom(14, 18, 4),
    LineAtom(14, 19, 4),
    LineAtom(14, 20, 4),
    LineAtom(14, 21, 4),
    LineAtom(14, 22, 4),
    LineAtom(14, 23, 4),
    LineAtom(14, 24, 4),
    LineAtom(13, 25, 4),
    LineAtom(0, 26, 17),
    LineAtom(0, 27, 16),
    LineAtom(0, 28, 15),
    LineAtom(0, 29, 13),
};
const LineAtom _middleLineFont_4[]{
    LineAtom(0, 0, 3),
    LineAtom(13, 0, 3),
    LineAtom(0, 1, 3),
    LineAtom(13, 1, 3),
    LineAtom(0, 2, 3),
    LineAtom(13, 2, 3),
    LineAtom(0, 3, 3),
    LineAtom(13, 3, 3),
    LineAtom(0, 4, 3),
    LineAtom(13, 4, 3),
    LineAtom(0, 5, 3),
    LineAtom(13, 5, 3),
    LineAtom(0, 6, 3),
    LineAtom(13, 6, 3),
    LineAtom(0, 7, 3),
    LineAtom(13, 7, 3),
    LineAtom(0, 8, 3),
    LineAtom(13, 8, 3),
    LineAtom(0, 9, 3),
    LineAtom(13, 9, 3),
    LineAtom(0, 10, 3),
    LineAtom(13, 10, 3),
    LineAtom(0, 11, 3),
    LineAtom(13, 11, 3),
    LineAtom(0, 12, 3),
    LineAtom(13, 12, 3),
    LineAtom(0, 13, 3),
    LineAtom(13, 13, 3),
    LineAtom(0, 14, 3),
    LineAtom(13, 14, 3),
    LineAtom(0, 15, 3),
    LineAtom(13, 15, 3),
    LineAtom(0, 16, 4),
    LineAtom(13, 16, 3),
    LineAtom(0, 17, 4),
    LineAtom(13, 17, 3),
    LineAtom(1, 18, 5),
    LineAtom(13, 18, 3),
    LineAtom(1, 19, 17),
    LineAtom(2, 20, 16),
    LineAtom(4, 21, 14),
    LineAtom(13, 22, 3),
    LineAtom(13, 23, 3),
    LineAtom(13, 24, 3),
    LineAtom(13, 25, 3),
    LineAtom(13, 26, 3),
    LineAtom(13, 27, 3),
    LineAtom(13, 28, 3),
    LineAtom(13, 29, 3),
};
const LineAtom _middleLineFont_5[]{
    LineAtom(0, 0, 18),
    LineAtom(0, 1, 18),
    LineAtom(0, 2, 18),
    LineAtom(0, 3, 3),
    LineAtom(0, 4, 3),
    LineAtom(0, 5, 3),
    LineAtom(0, 6, 3),
    LineAtom(0, 7, 3),
    LineAtom(0, 8, 3),
    LineAtom(0, 9, 3),
    LineAtom(0, 10, 4),
    LineAtom(0, 11, 13),
    LineAtom(0, 12, 15),
    LineAtom(0, 13, 16),
    LineAtom(2, 14, 15),
    LineAtom(13, 15, 4),
    LineAtom(14, 16, 4),
    LineAtom(14, 17, 4),
    LineAtom(14, 18, 4),
    LineAtom(14, 19, 4),
    LineAtom(14, 20, 4),
    LineAtom(14, 21, 4),
    LineAtom(14, 22, 4),
    LineAtom(14, 23, 4),
    LineAtom(14, 24, 4),
    LineAtom(13, 25, 4),
    LineAtom(0, 26, 17),
    LineAtom(0, 27, 16),
    LineAtom(0, 28, 15),
    LineAtom(0, 29, 13),
};
const LineAtom _middleLineFont_6[]{
    LineAtom(4, 0, 14),
    LineAtom(2, 1, 16),
    LineAtom(1, 2, 17),
    LineAtom(1, 3, 5),
    LineAtom(0, 4, 4),
    LineAtom(0, 5, 4),
    LineAtom(0, 6, 3),
    LineAtom(0, 7, 3),
    LineAtom(0, 8, 3),
    LineAtom(0, 9, 3),
    LineAtom(0, 10, 3),
    LineAtom(0, 11, 13),
    LineAtom(0, 12, 15),
    LineAtom(0, 13, 16),
    LineAtom(0, 14, 17),
    LineAtom(0, 15, 5),
    LineAtom(13, 15, 4),
    LineAtom(0, 16, 4),
    LineAtom(14, 16, 4),
    LineAtom(0, 17, 3),
    LineAtom(14, 17, 4),
    LineAtom(0, 18, 3),
    LineAtom(14, 18, 4),
    LineAtom(0, 19, 3),
    LineAtom(14, 19, 4),
    LineAtom(0, 20, 3),
    LineAtom(14, 20, 4),
    LineAtom(0, 21, 3),
    LineAtom(14, 21, 4),
    LineAtom(0, 22, 3),
    LineAtom(14, 22, 4),
    LineAtom(0, 23, 3),
    LineAtom(14, 23, 4),
    LineAtom(0, 24, 4),
    LineAtom(14, 24, 4),
    LineAtom(0, 25, 4),
    LineAtom(13, 25, 4),
    LineAtom(1, 26, 5),
    LineAtom(12, 26, 5),
    LineAtom(1, 27, 15),
    LineAtom(2, 28, 13),
    LineAtom(4, 29, 10),
};
const LineAtom _middleLineFont_7[]{
    LineAtom(0, 0, 14),
    LineAtom(0, 1, 15),
    LineAtom(0, 2, 16),
    LineAtom(12, 3, 5),
    LineAtom(13, 4, 4),
    LineAtom(14, 5, 4),
    LineAtom(14, 6, 4),
    LineAtom(14, 7, 4),
    LineAtom(14, 8, 4),
    LineAtom(14, 9, 4),
    LineAtom(14, 10, 4),
    LineAtom(14, 11, 4),
    LineAtom(14, 12, 4),
    LineAtom(14, 13, 4),
    LineAtom(14, 14, 4),
    LineAtom(14, 15, 4),
    LineAtom(14, 16, 4),
    LineAtom(14, 17, 4),
    LineAtom(14, 18, 4),
    LineAtom(14, 19, 4),
    LineAtom(14, 20, 4),
    LineAtom(14, 21, 4),
    LineAtom(14, 22, 4),
    LineAtom(14, 23, 4),
    LineAtom(14, 24, 4),
    LineAtom(14, 25, 4),
    LineAtom(14, 26, 4),
    LineAtom(14, 27, 4),
    LineAtom(14, 28, 4),
    LineAtom(15, 29, 2),
};
const LineAtom _middleLineFont_8[]{
    LineAtom(4, 0, 10),
    LineAtom(2, 1, 13),
    LineAtom(1, 2, 15),
    LineAtom(1, 3, 5),
    LineAtom(12, 3, 5),
    LineAtom(0, 4, 4),
    LineAtom(13, 4, 4),
    LineAtom(0, 5, 4),
    LineAtom(14, 5, 4),
    LineAtom(0, 6, 3),
    LineAtom(14, 6, 4),
    LineAtom(0, 7, 3),
    LineAtom(14, 7, 4),
    LineAtom(0, 8, 3),
    LineAtom(14, 8, 4),
    LineAtom(0, 9, 3),
    LineAtom(14, 9, 4),
    LineAtom(0, 10, 3),
    LineAtom(14, 10, 4),
    LineAtom(0, 11, 4),
    LineAtom(14, 11, 4),
    LineAtom(0, 12, 5),
    LineAtom(13, 12, 4),
    LineAtom(1, 13, 15),
    LineAtom(2, 14, 13),
    LineAtom(2, 15, 14),
    LineAtom(1, 16, 5),
    LineAtom(12, 16, 5),
    LineAtom(0, 17, 4),
    LineAtom(13, 17, 4),
    LineAtom(0, 18, 4),
    LineAtom(14, 18, 4),
    LineAtom(0, 19, 3),
    LineAtom(14, 19, 4),
    LineAtom(0, 20, 3),
    LineAtom(14, 20, 4),
    LineAtom(0, 21, 3),
    LineAtom(14, 21, 4),
    LineAtom(0, 22, 3),
    LineAtom(14, 22, 4),
    LineAtom(0, 23, 3),
    LineAtom(14, 23, 4),
    LineAtom(0, 24, 4),
    LineAtom(14, 24, 4),
    LineAtom(0, 25, 5),
    LineAtom(13, 25, 4),
    LineAtom(1, 26, 16),
    LineAtom(2, 27, 14),
    LineAtom(3, 28, 12),
    LineAtom(5, 29, 8),
};
const LineAtom _middleLineFont_9[]{
    LineAtom(3, 0, 12),
    LineAtom(2, 1, 14),
    LineAtom(1, 2, 16),
    LineAtom(0, 3, 5),
    LineAtom(13, 3, 4),
    LineAtom(0, 4, 4),
    LineAtom(14, 4, 4),
    LineAtom(0, 5, 3),
    LineAtom(14, 5, 4),
    LineAtom(0, 6, 3),
    LineAtom(14, 6, 4),
    LineAtom(0, 7, 3),
    LineAtom(14, 7, 4),
    LineAtom(0, 8, 3),
    LineAtom(14, 8, 4),
    LineAtom(0, 9, 3),
    LineAtom(14, 9, 4),
    LineAtom(0, 10, 3),
    LineAtom(14, 10, 4),
    LineAtom(0, 11, 3),
    LineAtom(14, 11, 4),
    LineAtom(0, 12, 4),
    LineAtom(14, 12, 4),
    LineAtom(0, 13, 4),
    LineAtom(13, 13, 5),
    LineAtom(1, 14, 5),
    LineAtom(12, 14, 6),
    LineAtom(1, 15, 17),
    LineAtom(2, 16, 16),
    LineAtom(4, 17, 14),
    LineAtom(14, 18, 4),
    LineAtom(14, 19, 4),
    LineAtom(14, 20, 4),
    LineAtom(14, 21, 4),
    LineAtom(14, 22, 4),
    LineAtom(14, 23, 4),
    LineAtom(14, 24, 4),
    LineAtom(13, 25, 4),
    LineAtom(0, 26, 17),
    LineAtom(0, 27, 16),
    LineAtom(0, 28, 15),
    LineAtom(0, 29, 13),
};

const LineAtom *smallLineFont[10]{
    _smallLineFont_0,
    _smallLineFont_1,
    _smallLineFont_2,
    _smallLineFont_3,
    _smallLineFont_4,
    _smallLineFont_5,
    _smallLineFont_6,
    _smallLineFont_7,
    _smallLineFont_8,
    _smallLineFont_9,
};

const uint32_t smallLineFont_size[10]{
    24,
    14,
    14,
    14,
    21,
    14,
    19,
    14,
    22,
    19,
};

const LineAtom *middleLineFont[10]{
    _middleLineFont_0,
    _middleLineFont_1,
    _middleLineFont_2,
    _middleLineFont_3,
    _middleLineFont_4,
    _middleLineFont_5,
    _middleLineFont_6,
    _middleLineFont_7,
    _middleLineFont_8,
    _middleLineFont_9,
};

const uint32_t middleLineFont_size[10]{
    53,
    30,
    30,
    30,
    49,
    30,
    42,
    30,
    50,
    42,
};

const LineAtom *largeLineFont[10]{
    _largeLineFont_0,
    _largeLineFont_1,
    _largeLineFont_2,
    _largeLineFont_3,
    _largeLineFont_4,
    _largeLineFont_5,
    _largeLineFont_6,
    _largeLineFont_7,
    _largeLineFont_8,
    _largeLineFont_9,
};

const uint32_t largeLineFont_size[10]{
    106,
    60,
    60,
    60,
    98,
    60,
    84,
    60,
    100,
    84,
};
#endif