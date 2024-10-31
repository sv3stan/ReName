//---------------------------------------------------------------------------
// ExifUtils.h
#ifndef ExifUtilsH
#define ExifUtilsH
#include <windows.h>
#include <iostream>
#include <string>
//---------------------------------------------------------------------------
#endif

#include <System.SysUtils.hpp>
#include <gdiplus.h>

struct ExifData {
    String date;
    UINT width;
    UINT height;
    String make;
    String model;
};


using namespace Gdiplus;


// получение атрибутов файла
std::string FormatFileAttributes(DWORD attributes);
// получение расширени€ файла
UnicodeString GetFileExtension(const UnicodeString &fileName);
// ќбъ€вл€ем функцию дл€ получени€ EXIF данных
// void GetExifData(const String &fileName);
void GetImageDimensions(const UnicodeString &fileNamee, UINT &width, UINT &height);
ExifData GetExifData(const String &fileName);
String GetExifDate(const String &fileName);
UINT GetImageWidth(const String &fileName);
UINT GetImageHeight(const String &fileName);
String GetCameraMake(const String &fileName);
String GetCameraModel(const String &fileName);
