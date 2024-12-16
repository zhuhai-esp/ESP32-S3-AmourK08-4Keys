#ifndef OPENSSL_TEST_LAB_KUWODES_H
#define OPENSSL_TEST_LAB_KUWODES_H

#include <array>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

using namespace std;

static const char* URL_KW_DAILY = "http://mobi.kuwo.cn/mobi.s?type=rcm_discover&devid=2659776214";

constexpr static char base64_chars[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
constexpr static uint64_t g_arrayMask[] = {
    0x0000000000000001, 0x0000000000000002, 0x0000000000000004,
    0x0000000000000008, 0x0000000000000010, 0x0000000000000020,
    0x0000000000000040, 0x0000000000000080, 0x0000000000000100,
    0x0000000000000200, 0x0000000000000400, 0x0000000000000800,
    0x0000000000001000, 0x0000000000002000, 0x0000000000004000,
    0x0000000000008000, 0x0000000000010000, 0x0000000000020000,
    0x0000000000040000, 0x0000000000080000, 0x0000000000100000,
    0x0000000000200000, 0x0000000000400000, 0x0000000000800000,
    0x0000000001000000, 0x0000000002000000, 0x0000000004000000,
    0x0000000008000000, 0x0000000010000000, 0x0000000020000000,
    0x0000000040000000, 0x0000000080000000, 0x0000000100000000,
    0x0000000200000000, 0x0000000400000000, 0x0000000800000000,
    0x0000001000000000, 0x0000002000000000, 0x0000004000000000,
    0x0000008000000000, 0x0000010000000000, 0x0000020000000000,
    0x0000040000000000, 0x0000080000000000, 0x0000100000000000,
    0x0000200000000000, 0x0000400000000000, 0x0000800000000000,
    0x0001000000000000, 0x0002000000000000, 0x0004000000000000,
    0x0008000000000000, 0x0010000000000000, 0x0020000000000000,
    0x0040000000000000, 0x0080000000000000, 0x0100000000000000,
    0x0200000000000000, 0x0400000000000000, 0x0800000000000000,
    0x1000000000000000, 0x2000000000000000, 0x4000000000000000,
    0x8000000000000000};
constexpr static int g_arrayIP[] = {
    57, 49, 41, 33, 25, 17, 9,  1, 59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7,
    56, 48, 40, 32, 24, 16, 8,  0, 58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6};
constexpr static int g_arrayE[] = {
    31, 0,  1,  2,  3,  4,  -1, -1, 3,  4,  5,  6,  7,  8,  -1, -1,
    7,  8,  9,  10, 11, 12, -1, -1, 11, 12, 13, 14, 15, 16, -1, -1,
    15, 16, 17, 18, 19, 20, -1, -1, 19, 20, 21, 22, 23, 24, -1, -1,
    23, 24, 25, 26, 27, 28, -1, -1, 27, 28, 29, 30, 31, 30, -1, -1};
constexpr static char g_matrixNSBox[][64] = {
    {14, 4,  3,  15, 2,  13, 5, 3,  13, 14, 6,  9,  11, 2,  0, 5,
     4,  1,  10, 12, 15, 6,  9, 10, 1,  8,  12, 7,  8,  11, 7, 0,
     0,  15, 10, 5,  14, 4,  9, 10, 7,  8,  12, 3,  13, 1,  3, 6,
     15, 12, 6,  11, 2,  9,  5, 0,  4,  2,  11, 14, 1,  7,  8, 13},
    {15, 0,  9,  5,  6,  10, 12, 9, 8,  7,  2,  12, 3,  13, 5,  2,
     1,  14, 7,  8,  11, 4,  0,  3, 14, 11, 13, 6,  4,  1,  10, 15,
     3,  13, 12, 11, 15, 3,  6,  0, 4,  10, 1,  7,  8,  4,  11, 14,
     13, 8,  0,  6,  2,  15, 9,  5, 7,  1,  10, 12, 14, 2,  5,  9},
    {10, 13, 1,  11, 6, 8,  11, 5,  9,  4,  12, 2,  15, 3, 2,  14,
     0,  6,  13, 1,  3, 15, 4,  10, 14, 9,  7,  12, 5,  0, 8,  7,
     13, 1,  2,  4,  3, 6,  12, 11, 0,  13, 5,  14, 6,  8, 15, 2,
     7,  10, 8,  15, 4, 9,  11, 5,  9,  0,  14, 3,  10, 7, 1,  12},
    {7,  10, 1, 15, 0,  12, 11, 5,  14, 9, 8,  3,  9,  7,  4,  8,
     13, 6,  2, 1,  6,  11, 12, 2,  3,  0, 5,  14, 10, 13, 15, 4,
     13, 3,  4, 9,  6,  10, 1,  12, 11, 0, 2,  5,  0,  13, 14, 2,
     8,  15, 7, 4,  15, 1,  10, 7,  5,  6, 12, 11, 3,  8,  9,  14},
    {2,  4,  8, 15, 7,  10, 13, 6,  4,  1,  3,  12, 11, 7,  14, 0,
     12, 2,  5, 9,  10, 13, 0,  3,  1,  11, 15, 5,  6,  8,  9,  14,
     14, 11, 5, 6,  4,  1,  3,  10, 2,  12, 15, 0,  13, 2,  8,  5,
     11, 8,  0, 15, 7,  14, 9,  4,  12, 7,  10, 9,  1,  13, 6,  3},
    {12, 9,  0,  7,  9,  2, 14, 1,  10, 15, 3,  4,  6, 12, 5,  11,
     1,  14, 13, 0,  2,  8, 7,  13, 15, 5,  4,  10, 8, 3,  11, 6,
     10, 4,  6,  11, 7,  9, 0,  6,  4,  2,  13, 1,  9, 15, 3,  8,
     15, 3,  1,  14, 12, 5, 11, 0,  2,  12, 14, 7,  5, 10, 8,  13},
    {4,  1,  3,  10, 15, 12, 5,  0,  2,  11, 9,  6,  8,  7,  6, 9,
     11, 4,  12, 15, 0,  3,  10, 5,  14, 13, 7,  8,  13, 14, 1, 2,
     13, 6,  14, 9,  4,  1,  2,  14, 11, 13, 5,  0,  1,  10, 8, 3,
     0,  11, 3,  5,  9,  4,  15, 2,  7,  8,  12, 15, 10, 7,  6, 12},
    {13, 7,  10, 0,  6,  9,  5,  15, 8,  4,  3,  10, 11, 14, 12, 5,
     2,  11, 9,  6,  15, 12, 0,  3,  4,  1,  14, 13, 1,  2,  7,  8,
     1,  2,  12, 15, 10, 4,  0,  3,  13, 14, 6,  9,  7,  8,  9,  6,
     15, 1,  5,  12, 3,  10, 14, 5,  8,  7,  11, 0,  4,  13, 2,  11}};
constexpr static int g_arrayP[] = {15, 6, 19, 20, 28, 11, 27, 16, 0,  14, 22,
                                   25, 4, 17, 30, 9,  1,  7,  23, 13, 31, 26,
                                   2,  8, 18, 12, 29, 5,  21, 10, 3,  24};
constexpr static int g_arrayIP_1[] = {
    39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9,  49, 17, 57, 25, 32, 0, 40, 8,  48, 16, 56, 24};
constexpr static int g_arrayPC_1[] = {
    56, 48, 40, 32, 24, 16, 8,  0,  57, 49, 41, 33, 25, 17, 9,  1,  58, 50, 42,
    34, 26, 18, 10, 2,  59, 51, 43, 35, 62, 54, 46, 38, 30, 22, 14, 6,  61, 53,
    45, 37, 29, 21, 13, 5,  60, 52, 44, 36, 28, 20, 12, 4,  27, 19, 11, 3};
constexpr static int g_arrayPC_2[] = {
    13, 16, 10, 23, 0,  4,  -1, -1, 2,  27, 14, 5,  20, 9,  -1, -1,
    22, 18, 11, 3,  25, 7,  -1, -1, 15, 6,  26, 19, 12, 1,  -1, -1,
    40, 51, 30, 36, 46, 54, -1, -1, 29, 39, 50, 44, 32, 47, -1, -1,
    43, 48, 38, 55, 33, 52, -1, -1, 45, 41, 49, 35, 28, 31, -1, -1};
constexpr static int g_arrayLs[] = {1, 1, 2, 2, 2, 2, 2, 2,
                                    1, 2, 2, 2, 2, 2, 2, 1};
constexpr static uint64_t g_arrayLsMask[] = {
    0x0000000000000000ll, 0x0000000000100001ll, 0x0000000000300003l};

class KwWork {
private:
  static vector<char> crypt(vector<char> &src) {
    uint64_t CRYPT_KEY = 0x6D776B78737A6C79;
    int len = (int)src.size();
    int num = len / 8;
    array<uint64_t, 16> subKey = {0};
    vector<uint64_t> pSrc(num);
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < 8; j++) {
        pSrc[i] |= (uint64_t)(src[i * 8 + j]) << (j * 8);
      }
    }
    vector<uint64_t> pEncyrpt(((num + 1) * 8 + 1) / 8, 0);
    DESSubKeys(CRYPT_KEY, subKey.data(), 0);
    for (int i = 0; i < num; i++) {
      pEncyrpt[i] = DES64(subKey.data(), pSrc[i]);
    }
    int tail_num = len % 8;
    vector<char> szTail(len - num * 8);
    copy(src.begin() + num * 8, src.end(), szTail.begin());
    uint64_t tail64 = 0;
    for (int i = 0; i < tail_num; i++) {
      tail64 |= (uint64_t)(szTail[i]) << (i * 8);
    }
    pEncyrpt[num] = DES64(subKey.data(), tail64);
    vector<char> result(pEncyrpt.size() * 8);
    int temp = 0;
    for (const auto &value : pEncyrpt) {
      for (int j = 0; j < 8; ++j) {
        result[temp++] = (char)((0xff & (value >> (j * 8))));
      }
    }
    return result;
  }

  static uint64_t BitTransform(const int array[], int len, uint64_t source) {
    uint64_t bts = source;
    int bti;
    uint64_t dest = 0;
    for (bti = 0; bti < len; ++bti) {
      if (array[bti] >= 0 && (bts & g_arrayMask[array[bti]]) != 0) {
        dest |= g_arrayMask[bti];
      }
    }
    return dest;
  }

  static void DESSubKeys(uint64_t key, uint64_t K[], int mode) {
    uint64_t temp;
    int j;
    temp = BitTransform(g_arrayPC_1, 56, key);
    for (j = 0; j < 16; ++j) {
      {
        uint64_t source = temp;
        temp = ((source & g_arrayLsMask[g_arrayLs[j]]) << (28 - g_arrayLs[j])) |
               ((source & ~g_arrayLsMask[g_arrayLs[j]]) >> g_arrayLs[j]);
      }
      K[j] = BitTransform(g_arrayPC_2, 64, temp);
    }
    if (mode == 1) {
      uint64_t t1;
      for (j = 0; j < 8; ++j) {
        t1 = K[j];
        K[j] = K[15 - j];
        K[15 - j] = t1;
      }
    }
  }

  static uint64_t DES64(const uint64_t subKeys[], uint64_t data) {
    static uint64_t out, L, R;
    static int pSource[2];
    static char pR[8];
    static int SOut;
    static int t;
    static int sbi;
    out = BitTransform(g_arrayIP, 64, data);
    pSource[0] = (int)(out & 0x00000000ffffffffLL);
    pSource[1] = (int)((out & 0xffffffff00000000LL) >> 32);
    for (int i = 0; i < 16; ++i) {
      R = pSource[1];
      R = BitTransform(g_arrayE, 64, R);
      R ^= subKeys[i];
      for (int k = 0; k < 8; ++k) {
        pR[k] = (char)(0xff & (R >> (k * 8)));
      }
      SOut = 0;
      for (sbi = 7; sbi >= 0; --sbi) {
        SOut <<= 4;
        SOut |= g_matrixNSBox[sbi][(uint8_t)(pR[sbi])];
      }
      R = SOut;
      R = BitTransform(g_arrayP, 32, R);
      L = pSource[0];
      pSource[0] = pSource[1];
      pSource[1] = (int)(L ^ R);
    }
    t = pSource[0];
    pSource[0] = pSource[1];
    pSource[1] = t;
    out = ((long long)pSource[1] << 32 & 0xffffffff00000000LL) |
          (long long)(0x00000000ffffffffLL & pSource[0]);
    out = BitTransform(g_arrayIP_1, 64, out);
    return out;
  }

public:
  static char base64_encode_value(int value_in) {
    return base64_chars[value_in & 0x3F];
  }

  static string final(const vector<char> &src) {
    std::string result;
    size_t padding = 0;
    size_t len = src.size();
    size_t full_groups = len / 3;     // 完整的3字节组
    size_t last_group_size = len % 3; // 最后一组的大小

    if (last_group_size != 0) {
      padding = 4 - last_group_size;
    }
    result.resize((full_groups * 4) + (last_group_size > 0 ? 4 : 0));
    for (size_t i = 0; i < full_groups * 3; i += 3) {
      int triple = (src[i] << 16) | (src[i + 1] << 8) | src[i + 2];
      result[i / 3 * 4] = base64_encode_value(triple >> 18);
      result[i / 3 * 4 + 1] = base64_encode_value(triple >> 12 & 0x3F);
      result[i / 3 * 4 + 2] = base64_encode_value(triple >> 6 & 0x3F);
      result[i / 3 * 4 + 3] = base64_encode_value(triple & 0x3F);
    }
    if (last_group_size == 1) {
      int last_byte = src[len - 1];
      result[full_groups * 4] = base64_encode_value(last_byte >> 2);
      result[full_groups * 4 + 1] = base64_encode_value(last_byte << 4 & 0x3F);
      result[full_groups * 4 + 2] = '=';
      result[full_groups * 4 + 3] = '=';
    } else if (last_group_size == 2) {
      int last_two_bytes = (src[len - 2] << 8) | src[len - 1];
      result[full_groups * 4] = base64_encode_value(last_two_bytes >> 10);
      result[full_groups * 4 + 1] =
          base64_encode_value(last_two_bytes >> 4 & 0x3F);
      result[full_groups * 4 + 2] =
          base64_encode_value(last_two_bytes << 2 & 0x3F);
      result[full_groups * 4 + 3] = '=';
    }
    return result;
  }

  static string encrypt(const string &txt) {
    vector<char> src(txt.begin(), txt.end());
    vector<char> result = crypt(src);
    return final(result);
  }

  static string getUrl(long id) {
    stringstream ss;
    ss << "user=583781442410&prod=kwplayerhd_ar_5.1.0.0&corp=kuwo&vipver=5.1.0."
          "0&source=kwplayerhd_ar_5.1.0.0_B_jiakong_vh.apk&packageName=cn.kuwo."
          "kwmusiccar&packageSign=61ed377e85d386a8dfee6b864bd85b0bfaa5af81&"
          "type=convert_url2&br=100kmp3&format=mp3|aac&sig=0&rid="
       << id << "&priority=bitrate&loginUid=0";
    string en = KwWork::encrypt(ss.str());
    ss.str("");
    ss << "http://mobi.kuwo.cn/mobi.s?f=kuwo&q=" << en;
    return ss.str();
  }
};

#ifdef __cplusplus
}
#endif

#endif // OPENSSL_TEST_LAB_KUWODES_H
