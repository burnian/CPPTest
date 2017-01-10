#pragma once
#include <xmmintrin.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>


#define _SHUFFLE_PARAM(x, y, z, w) ((x) | ((y) << 2) | ((z) << 4) | ((w) << 6))
#define _mm_replicate_x_ps(v) (_mm_shuffle_ps((v), (v), _SHUFFLE_PARAM(0, 0, 0, 0)))
#define _mm_replicate_y_ps(v) (_mm_shuffle_ps((v), (v), _SHUFFLE_PARAM(1, 1, 1, 1)))
#define _mm_replicate_z_ps(v) (_mm_shuffle_ps((v), (v), _SHUFFLE_PARAM(2, 2, 2, 2)))
#define _mm_replicate_w_ps(v) (_mm_shuffle_ps((v), (v), _SHUFFLE_PARAM(3, 3, 3, 3)))

void print__m128(__m128 a);
__m128 addWithAssembly(__m128 a, __m128 b);
__m128 addWithIntrinsics(__m128 a, __m128 b);


// 同步读取文件
bool syncReadFile(const char* filePath, void* buffer, size_t bufferSize, size_t& rBytesRead);
