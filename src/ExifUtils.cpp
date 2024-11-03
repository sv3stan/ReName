//---------------------------------------------------------------------------

#pragma hdrstop
// Объявляем функцию для получения EXIF данных
#include "../include/ExifUtils.h"
#include <System.DateUtils.hpp>
#include <iostream>
#include <System.SysUtils.hpp>
#include <Vcl.Dialogs.hpp>
#include <vcl.Graphics.hpp>
#include <vcl.Controls.hpp>
#include <vcl.Forms.hpp>
#include <vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//

std::string FormatFileAttributes(DWORD attributes)
{
    std::string formatted = "----"; // Инициализация строки для пяти атрибутов

    // Установка символов в строке в зависимости от наличия атрибутов
    if (attributes & FILE_ATTRIBUTE_ARCHIVE) {
        formatted[0] = 'a'; // Первый символ 'A' для архива
    }

    if (attributes & FILE_ATTRIBUTE_READONLY) {
        formatted[1] = 'r'; // Второй символ 'R' для только для чтения
    }

    if (attributes & FILE_ATTRIBUTE_HIDDEN) {
        formatted[2] = 'h'; // Третий символ 'H' для скрытого файла
    }

    if (attributes & FILE_ATTRIBUTE_SYSTEM) {
        formatted[3] = 's'; // Четвертый символ 'S' для системного файла
    }

    return formatted;
}

UnicodeString GetFileExtension(const UnicodeString &fileName)

{
    int dotIndex = fileName.LastDelimiter(L'.'); // Находим последний символ '.'

    if (dotIndex != -1 && dotIndex < fileName.Length() - 1) {
        return fileName.SubString(dotIndex + 1, fileName.Length() - dotIndex);
    }

    return UnicodeString(); // Возвращаем пустую строку, если расширение не найдено
}

System::TDateTime GetExifDate(const UnicodeString &fileName)
{
    Image image(fileName.c_str());
    if (image.GetLastStatus() != Ok) {
        return TDateTime(0); // Возвращаем 0 в случае ошибки
    }

    //UINT tagList[] = { 0x9003, 0x0132, 0x9004 }; // Проверяем несколько тегов
    //for (UINT tag : tagList) {
//    ShowMessage("&&&&&&");
        UINT size = image.GetPropertyItemSize(0x9003);
        //     UINT size = image.GetPropertyItemSize(0x0132); // EXIF DateTimeOriginal
        if (size > 0) {
            PropertyItem* pItem = (PropertyItem*)malloc(size);
            if (pItem == nullptr) {
                return TDateTime(
                    0); // Возвращаем 0, если не удалось выделить память
            }
            if (image.GetPropertyItem(0x9003, size, pItem) == Ok &&
                pItem->type == PropertyTagTypeASCII)
            {
                String exifValue = String((char*)pItem->value);
                free(pItem);
                try {
//                                    ShowMessage(exifValue);
                    TDateTime result =
                        StrToDateTime(exifValue, GlobalFormatSettings);
                    return result; // Возвращаем результат
                } catch (...) {
                    return TDateTime(0); // Возвращаем 0, если ошибка в формате
                }
            }
            free(pItem);
        }
   // }
    return TDateTime(0); // Возвращаем 0, если данных нет или они неверны
}

UINT GetImageWidth(const String &fileName)
{
    Image image(fileName.c_str());
    if (image.GetLastStatus() != Ok) {
        return 0; // Или другое значение по умолчанию
    }

    UINT size = image.GetPropertyItemSize(PropertyTagExifPixXDim);
    const UINT PropertyTagImageLength = 0x0101;
    if (size > 0) {
//        ShowMessage("1111111111");
        PropertyItem* pItem = (PropertyItem*)malloc(size);
        if (image.GetPropertyItem(PropertyTagExifPixXDim, size, pItem) == Ok) {
            UINT imageWidth = *(UINT*)pItem->value;
            free(pItem);
//            ShowMessage(UnicodeString(imageWidth));
            return imageWidth;
        }
        free(pItem);
    }
    return 0; // Или другое значение по умолчанию
}

UINT GetImageHeight(const String &fileName)
{
    Image image(fileName.c_str());
    if (image.GetLastStatus() != Ok) {
        return 0; // Или другое значение по умолчанию
    }

    UINT size = image.GetPropertyItemSize(PropertyTagImageHeight);
    UINT PropertyTagImageLength = 0x0101;
    if (size > 0) {
        PropertyItem* pItem = (PropertyItem*)malloc(size);
        if (image.GetPropertyItem(PropertyTagImageLength, size, pItem) == Ok) {
            UINT imageHeight = *(UINT*)pItem->value;
            free(pItem);
            return imageHeight;
        }
        free(pItem);
    }
    return 0;
}

System::UnicodeString GetCameraMake(const String &fileName)
{
    Image image(fileName.c_str());
    if (image.GetLastStatus() != Ok) {
        return "Не удалось загрузить изображение.";
    }
    const UINT PropertyTagMake = 0x010F;
    UINT size = image.GetPropertyItemSize(PropertyTagMake);

    if (size > 0) {
        PropertyItem* pItem = (PropertyItem*)malloc(size);
        if (image.GetPropertyItem(PropertyTagMake, size, pItem) == Ok) {
            System::UnicodeString makeValue = String((char*)pItem->value);
            free(pItem);
            // ShowMessage(makeValue);
            return makeValue;
        }
        free(pItem);
    }
    return "Нет данных";
}




//System::UnicodeString GetCameraMake(const String &fileName)
//{
//    Image image(fileName.c_str());
//    if (image.GetLastStatus() != Ok) {
//        return "Не удалось загрузить изображение.";
//    }
//
//    const UINT PropertyTagMake = 0x010F;
//    UINT size = image.GetPropertyItemSize(PropertyTagMake);
//
//    if (size > 0) {
//        PropertyItem* pItem = (PropertyItem*)malloc(size);
//        if (pItem && image.GetPropertyItem(PropertyTagMake, size, pItem) == Ok) {
//            // Попробуем сконвертировать данные с учётом возможной кодировки
//            System::UnicodeString makeValue = String((wchar_t*)pItem->value);
//            free(pItem);
//            return makeValue;
//        }
//        free(pItem);
//    }
//    return "Нет данных";
//}



















String GetCameraModel(const String &fileName)
{
    Image image(fileName.c_str());
    if (image.GetLastStatus() != Ok) {
        return "Не удалось загрузить изображение.";
    }
    const UINT PropertyTagModel = 0x0110;
    UINT size = image.GetPropertyItemSize(PropertyTagModel);
    if (size > 0) {
        PropertyItem* pItem = (PropertyItem*)malloc(size);
        if (image.GetPropertyItem(PropertyTagModel, size, pItem) == Ok) {
            String modelValue = String((char*)pItem->value);
            free(pItem);
            return modelValue;
        }
        free(pItem);
    }
    return "Нет данных";
}

void GetImageDimensions(const String &fileName, UINT &width, UINT &height)
{
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    Image image(fileName.c_str());
    if (image.GetLastStatus() == Ok) {
        width = image.GetWidth();
        height = image.GetHeight();
    } else {
        ShowMessage("Failed to load image " + fileName);
    }
    GdiplusShutdown(gdiplusToken);
}

ExifData GetExifData(const UnicodeString &fileName)
{
    ExifData exifData;
    exifData.date = GetExifDate(fileName);
    //itemMap.exifDate.date = GetExifDate(fileName);

    if (exifData.date == TDateTime(0)) {
        ShowMessage("++++++");
        GetImageDimensions(fileName, exifData.width, exifData.height);
    } else {
        ShowMessage("------");
        exifData.width = GetImageWidth(fileName);
        exifData.height = GetImageHeight(fileName);
        exifData.make = GetCameraMake(fileName);
        exifData.model = GetCameraModel(fileName);
    }

    ShowMessage(exifData.date);
    return exifData;
}


void GetImageSize(const UnicodeString &fileName, UINT &width, UINT &height) {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    Image image(fileName.c_str());
    if (image.GetLastStatus() == Ok) {
        width = image.GetWidth();
        height = image.GetHeight();
    } else {
        width = 0;
        height = 0;
    }

    GdiplusShutdown(gdiplusToken);
}
