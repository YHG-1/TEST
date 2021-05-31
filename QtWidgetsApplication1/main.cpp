#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <string>
#include <tchar.h>

int main( int argc, char* argv[] )
{
    //string->wstring
//     std::string sString = "4567456";
//     sWString.assign(sString.begin(), sString.end());

    //Qstring - >wchar_t
//     wchar_t sWchar[ 100 ];
//     QString sQstring = "595959";
//     sQstring.toWCharArray( sWchar );

    //Qstring - >wString
//     QString sQstring = "595959";
//     std::wstring sWString = sQstring.toStdWString();

    //wstring->string
//     std::wstring sWString = L"123123";
//     std::string sString;
//     sString.assign(sWString.begin(), sWString.end());

    //wstring->Qstring
//     QString sQString = QString::fromStdWString( sWString );
//     QString sQString = QString::fromWCharArray( sWString.c_str() );

    //wstring -> wchar_t
//     std::wstring sWString = L"0101010";
//     const wchar_t* cWchar = sWString.c_str();

    //wchar_t -> Qstring
//     wchar_t sWchar[ 100 ] = _T( "987987" );
//     wchar_t cWchar = L'0';
//     QString sQString = QString::fromWCharArray( sWchar, wcslen(sWchar) );
//     QString sQString = QString::fromStdWString( sWchar );
    
    //wchar_t -> wstring
//      wchar_t sWchar[ 100 ] = _T( "987987" );
//      std::wstring sWString;
//      sWString.assign(sWchar,100);
    
    //char* -> wstring
//     char* cArray = "000000";
//     std::wstring sWString( cArray, cArray + strlen( cArray ) );

    //char* -> QString
//     char* cha = "ABC";
//     QString sQString = QString( cha );
//     QString sQString2 = QString( " fileName=%1" ).arg( "qweqwe" );
//     QString sQString3 = QString::fromUtf8( cha );

    //QString -> char*
//     QString sQString = "02468";
//     auto sWString2 = sQString.toStdWString();
//     const char* cArray = (char *)sWString2.c_str();
/*   cArray = sQString.toUtf8().constData();*/
/*    strcpy(cArray, sQString.toStdString().c_str() );*/


    //wstring -> char*   
    std::wstring sWString = L"000000";

    QApplication a( argc, argv ); 
    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
}