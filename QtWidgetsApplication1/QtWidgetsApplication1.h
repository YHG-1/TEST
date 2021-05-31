#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"

const QString BUTTON_CSS = "QPushButton:!hover { background-color : rgb( 36, 134, 0 ); color: rgb( 255, 255, 255 ); }";
const QString BUTTON_SSC = "QPushButton:!hover { background-color :rgb(150, 167, 120);  color : rgb(255, 255, 255); } QPushButton:hover{ background-color : rgb( 134, 181, 117 );  color: rgb( 0, 0, 0 ); } QPushButton:pressed{ background-color : rgb( 36, 134, 0 ); color: rgb( 255, 255, 255 ); }";
class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT
public:
    QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);

public slots:
    //숫자 부분
    void on_btnNum1_clicked();
    void on_btnNum2_clicked();
    void on_btnNum3_clicked();
    void on_btnNum4_clicked(); 
    void on_btnNum5_clicked();
    void on_btnNum6_clicked();
    void on_btnNum7_clicked();
    void on_btnNum8_clicked();
    void on_btnNum9_clicked();
    void on_btnNum0_clicked();
    //연산자 부분
    void on_btnAdd_clicked();
    void on_btnMul_clicked();
    void on_btnSub_clicked();
    void on_btnDivison_clicked();
    //equal연산 부분
    void on_btnEnter_clicked();
    //CE 입력값만 초기화
    void on_btnCe_clicked();
    //C 완전 초기화
    void on_btnC_clicked();
    //소수점 부분
    void on_btnPoint_clicked();
    //부호 변환
    void on_btnSign_clicked();
    //숫자 부분 함수
    void btnNumFunction( char c );
    //연산자 부분 함수
    void operFunction( QString operString );

    void on_btnErase_clicked();
protected:
    //keypad 눌렀을때
    void keyPressEvent( QKeyEvent* pe );
    //keypad 누르지 않았을 때
    void keyReleaseEvent( QKeyEvent* pe );

private:
    //연산 부분 함수
    void calc();
    Ui::QtWidgetsApplication1Class ui;
    QString mathString;
    QString operString;
    QString matText;
    QString calText;
    double _dResult;
    double _dNum;
    char c;

    // 연산자 저장 변수
    char oper = '^';
    bool bEquel = false;
    bool bNUmber = false;
};
