#include "HwndKey.hpp"

HwndKey createHwndKey(HWND hwnd)
{
	HwndKey key = (HwndKey)hwnd;
	return key;
}
