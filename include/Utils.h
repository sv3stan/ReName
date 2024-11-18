//---------------------------------------------------------------------------

#ifndef UtilsH
#define UtilsH
//---------------------------------------------------------------------------

#include <System.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.StdCtrls.hpp>

#include <System.SysUtils.hpp>
#include "Main.h"
#include <optional>
#include <chrono>
//

class TForm1; // Forward declaration

TFormatSettings GlobalFormatSettings;

void InitGlobalFormatSettings()
{
    GlobalFormatSettings = TFormatSettings::Create();
    GlobalFormatSettings.ShortDateFormat = "yyyy:mm:dd";
    GlobalFormatSettings.LongTimeFormat = "hh:nn:ss";
    GlobalFormatSettings.DateSeparator = ':';
    GlobalFormatSettings.TimeSeparator = ':';
}
//

struct ExifData
{
    System::TDateTime date;
    unsigned int width; // ������ �����������
    unsigned int height; // ������ �����������
    System::UnicodeString make; // �������������
    System::UnicodeString model; // ������
};

struct NewData
{
    System::TDateTime newDateCreated; // ����� ���� ��������
    System::TDateTime newDateModified; // ����� ���� �����������
    System::TDateTime newDateOpened; // ����� ���� ��������
    System::TDateTime newDateOriginal; // ����� ���� ����
    System::UnicodeString newAttribute; // ����� �������
    System::UnicodeString newName; // ����� ���
};

struct FileData
{
    System::UnicodeString path; // ����
    System::UnicodeString name; // ���
    long size; // ������
    System::TDateTime dateCreated; // ���� ��������
    System::TDateTime dateModified; // ���� �����������
    System::TDateTime dateOpened; // ���� ��������
    System::UnicodeString attribute = L"----"; // �������
    ExifData exifData; // Exif-������
    NewData newData; // ����� ���������� � �����
};

struct FullItemData
{
    FileData fileData;
    NewData newData;
    ExifData exifData;
};

extern void InitGlobalFormatSettings();
extern std::unordered_map<System::UnicodeString, FullItemData> itemMap;

// ������� ��� ��������� ���������� � ��������� �����
void ProcessSelectedFile(
    TListItem* selectedItem, TForm1* form, TJvImage* image);
void storeDraggedFilesToMap(TStrings* Value);
void fromMapToStoreListView(TJvListView* jvListView);
void ProcessFolder(const UnicodeString &folderPath, TListItems* items);

TDateTime parseDateFromFileName(const System::UnicodeString &fileName);
bool setChangedFileDateTime(const UnicodeString &filePath,
    const UnicodeString &fileName);
bool StringToSystemTime(const String &dateTimeStr, SYSTEMTIME &systemTime);
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);
AnsiString DateTimeToExifFormat(const TDateTime &dateTime);
bool SetExifDateTimeOriginal(const UnicodeString &filePath,
    const UnicodeString &fileName, const TDateTime &newDate);
bool TDateTimeToFileTime(const TDateTime &dateTime, FILETIME &fileTime);
void ApplyFilenameToDate(TListView* listView);
void GetFileCreationDateTime(TListView* listView);
void parseNewNameFromFileDateTime(
        System::TDateTime dateTime,
    UnicodeString &formattedDate,
    UnicodeString &formattedTime);

#endif // UTILS_H

