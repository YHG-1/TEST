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
    //���� �κ�
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
    //������ �κ�
    void on_btnAdd_clicked();
    void on_btnMul_clicked();
    void on_btnSub_clicked();
    void on_btnDivison_clicked();
    //equal���� �κ�
    void on_btnEnter_clicked();
    //CE �Է°��� �ʱ�ȭ
    void on_btnCe_clicked();
    //C ���� �ʱ�ȭ
    void on_btnC_clicked();
    //�Ҽ��� �κ�
    void on_btnPoint_clicked();
    //��ȣ ��ȯ
    void on_btnSign_clicked();
    //���� �κ� �Լ�
    void btnNumFunction( char c );
    //������ �κ� �Լ�
    void operFunction( QString operString );

    void on_btnErase_clicked();
protected:
    //keypad ��������
    void keyPressEvent( QKeyEvent* pe );
    //keypad ������ �ʾ��� ��
    void keyReleaseEvent( QKeyEvent* pe );

private:
    //���� �κ� �Լ�
    void calc();
    Ui::QtWidgetsApplication1Class ui;
    QString mathString;
    QString operString;
    QString matText;
    QString calText;
    double _dResult;
    double _dNum;
    char c;

    // ������ ���� ����
    char oper = '^';
    bool bEquel = false;
    bool bNUmber = false;
};
