//---------------------------------------------------------------------------
// ExifUtils.h
#ifndef ExifUtilsH
#define ExifUtilsH
#include <windows.h>
#include <iostream>
#include <string>
#include <Utils.h>
#include <sysutils.hpp>

//---------------------------------------------------------------------------
#endif

#include <System.SysUtils.hpp>
#include <gdiplus.h>
//
//struct ExifData {
//    String date;
//    UINT width;
//    UINT height;
//    String make;
//    String model;
//};


using namespace Gdiplus;


// ��������� ��������� �����
std::string FormatFileAttributes(DWORD attributes);
// ��������� ���������� �����
UnicodeString GetFileExtension(const UnicodeString &fileName);
// ��������� ������� ��� ��������� EXIF ������
// void GetExifData(const String &fileName);
void GetImageDimensions(const UnicodeString &fileNamee, UINT &width, UINT &height);
ExifData GetExifData(const UnicodeString &fileName);
System::TDateTime GetExifDate(const String &fileName);
UINT GetImageWidth(const String &fileName);
UINT GetImageHeight(const String &fileName);
System::UnicodeString GetCameraMake(const String &fileName);
String GetCameraModel(const String &fileName);
void GetImageSize(const UnicodeString &fileName, UINT &width, UINT &height);
