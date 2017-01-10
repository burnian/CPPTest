#include "utils.h"


__m128 addWithAssembly(__m128 a, __m128 b)
{
	__m128 r;
	__asm
	{
		movaps xmm0, xmmword ptr[a]
		movaps xmm1, xmmword ptr[b]
		addps xmm0, xmm1
		movaps xmmword ptr[r], xmm0
	}
	return r;
}

__m128 addWithIntrinsics(__m128 a, __m128 b)
{
	__m128 r = _mm_add_ps(a, b);
	return r;
}


//__m128 mulVectorMatrix(__m128 v, __m128 Mrow1, __m128 Mrow2, __m128 Mrow3, __m128 Mrow4)
//{
//	__m128 xMrow1 = _mm_mul_ps(_mm_replicate_x_ps(v), Mrow1);
//	__m128 yMrow2 = _mm_mul_ps(_mm_replicate_y_ps(v), Mrow2);
//	__m128 zMrow3 = _mm_mul_ps(_mm_replicate_z_ps(v), Mrow3);
//	__m128 wMrow4 = _mm_mul_ps(_mm_replicate_w_ps(v), Mrow4);
//
//	__m128 result = _mm_add_ps(xMrow1, yMrow2);
//	result = _mm_add_ps(result, zMrow3);
//	result = _mm_add_ps(result, wMrow4);
//
//	return result;
//}

void print__m128(__m128 a)
{
	__declspec(align(16)) float r[4];
	_mm_store_ps(r, a);
	printf("%g %g %g %g\n", r[0], r[1], r[2], r[3]);
}


// 同步读取文件
bool syncReadFile(const char* filePath, void* buffer, size_t bufferSize, size_t& rBytesRead)
{
	FILE* handle = nullptr;
	errno_t err = fopen_s(&handle, filePath, "rb");
	if (err == 0)
	{
		// 在这里阻塞，直至所有数据都读取完毕
		size_t bytesRead = fread(buffer, 1, bufferSize, handle);
		// 若过程出错，取得错误码
		int err = ferror(handle);
		fclose(handle);
		if (0 == err)
		{
			rBytesRead = bytesRead;
			return true;
		}
	}
	return false;
}

// 在vs调试控制台打印日志
int IDebugPrintf(const char* format, ...)
{
	va_list argList;
	va_start(argList, format);
	const size_t MAX_CHARS = 1023;
	static char s_buffer[MAX_CHARS + 1];
	int charsWritten = vsnprintf(s_buffer, MAX_CHARS, format, argList);
	s_buffer[MAX_CHARS] = '\0';
	va_end(argList);

	OutputDebugString(s_buffer);

	return charsWritten;
}

// 当前代码所在文件，所在行
//cout << __FILE__ << "  " << __LINE__ << endl;

//SIMD 操作
//__declspec(align(16)) float f1[4] = { 1.0f, 2.0f, 3.0f, 4.0f };
//__declspec(align(16)) float f2[4] = { 5.0f, 6.0f, 7.0f, 8.0f };
//__declspec(align(16)) float r[4];
//
//__m128 a = _mm_load_ps(f1);
//__m128 b = _mm_load_ps(f2);
//
//
//__m128 m1 = { 1.0f, 2.0f, 3.0f, 4.0f };
//__m128 m2 = { 5.0f, 6.0f, 7.0f, 8.0f };
//
//__m128 temp = _mm_shuffle_ps(m1, m1, _SHUFFLE_PARAM(0, 1, 3, 0));
//print__m128(temp);
//temp = _mm_shuffle_ps(m1, m1, _SHUFFLE_PARAM(0, 0, 0, 0));
//print__m128(temp);
//temp = _mm_shuffle_ps(m1, m1, _SHUFFLE_PARAM(1, 1, 1, 0));
//print__m128(temp);
//temp = _mm_shuffle_ps(m1, m1, _SHUFFLE_PARAM(2, 2, 2, 2));
//print__m128(temp);
//
//temp = _mm_shuffle_ps(m1, m2, _SHUFFLE_PARAM(0, 1, 3, 0));
//print__m128(temp);
//temp = _mm_shuffle_ps(m1, m2, _SHUFFLE_PARAM(0, 0, 0, 0));
//print__m128(temp);
//temp = _mm_shuffle_ps(m1, m2, _SHUFFLE_PARAM(1, 1, 1, 0));
//print__m128(temp);
//temp = _mm_shuffle_ps(m1, m2, _SHUFFLE_PARAM(2, 2, 2, 2));
//print__m128(temp);
