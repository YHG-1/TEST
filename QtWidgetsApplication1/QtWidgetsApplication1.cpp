 #include "QtWidgetsApplication1.h"
 #include "qevent.h"
 QtWidgetsApplication1::QtWidgetsApplication1( QWidget* parent )
     : QMainWindow( parent )
 {
     ui.setupUi( this ); 
     on_btnC_clicked();
 }
 void QtWidgetsApplication1::calc()
 {
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     QLabel* pCal = this->findChild <QLabel*>( "txtCal" );
     sMatText = pMath->text();
     _dNum = sMatText.toDouble();
     if( _cOper == '^' )
     {
         _dResult = _dNum;
         calText = sMatText;
     }
     else if( _cOper == '+' )
     {
         _dResult += _dNum;
         calText = QString::number( _dResult );
     }
     else if( _cOper == '-' )
     {
         _dResult -= _dNum;
         calText = QString::number( _dResult );
     }
     else if( _cOper == '*' )
     {
         _dResult *= _dNum;
         calText = QString::number( _dResult );
     }
     else if( _cOper == '/' )
     {
         _dResult /= _dNum;
     }
     calText = QString::number( _dResult );
 }
 void QtWidgetsApplication1::btnNumFunction( char c )
 {
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     QLabel* pCal = this->findChild <QLabel*>( "txtCal" );
     //결과값 출력 이후, txtMatg, result, txtCal 모두 초기화
     if( bEquel == true )
     {
         pMath->setText( sMatText );
         _dResult = 0;
         _cOper = '^';
         calText.clear();
         pCal->setText( calText );
         bEquel = false;
     }
     sMatText = pMath->text();
     sMatText = sMatText + c;
     pMath->setText( sMatText );
 }
 void QtWidgetsApplication1::operFunction( QString operString )
 {
     if( bEquel == true )
     {
         _cOper = '^';
         bEquel = false;
     }
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     QLabel* pCal = this->findChild <QLabel*>( "txtCal" );
     sMatText = pMath->text();
     _dNum = sMatText.toDouble();
     //입력한 연산자 변경할때
     if( sMatText.isEmpty() == true )
     {
         calText = QString::number( _dResult );
         calText.append( operString );
         pCal->setText( calText );
         return;
     }
     calc();
     calText.append( operString );
     pCal->setText( calText );
     sMatText.clear();
     pMath->setText( sMatText );
 }
 void QtWidgetsApplication1::on_btnNum1_clicked()
 {
     c = '1';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum2_clicked()
 {
     c = '2';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum3_clicked()
 {
     c = '3';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum4_clicked()
 {
     c = '4';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum5_clicked()
 {
     c = '5';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum6_clicked()
 {
     c = '6';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum7_clicked()
 {
     c = '7';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum8_clicked()
 {
     c = '8';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum9_clicked()
 {
     c = '9';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnNum0_clicked()
 {
     c = '0';
     btnNumFunction( c );
 }
 void QtWidgetsApplication1::on_btnPoint_clicked()
 {
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     sMatText = pMath->text();
     bool bDot = sMatText.contains( ".", Qt::CaseInsensitive );
     if( sMatText.isEmpty() == false )
     {
         //matText내 .가 없는지 확인
         if( bDot == false )
             sMatText.append( '.' );
     }
     else
     {
         sMatText.append( '0' );
         sMatText.append( '.' );
     }
     pMath->setText( sMatText );
 }
 void QtWidgetsApplication1::on_btnCe_clicked()
 {
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     sMatText = pMath->text();
     sMatText.clear();
     pMath->setText( sMatText );
 }
 void QtWidgetsApplication1::on_btnC_clicked()
 {
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     QLabel* pCal = this->findChild <QLabel*>( "txtCal" );
     sMatText = pMath->text();
     calText = pMath->text();
     sMathString.clear();
     sMatText.clear();
     calText.clear();
     pMath->setText( sMatText );
     pCal->setText( calText );
     _dResult = 0;
     _dNum = 0;
     _cOper = '^';
     if( bEquel == true )
     {
         _cOper = '^';
         bEquel = false;
     }
 }
 void QtWidgetsApplication1::on_btnErase_clicked()
 {
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     sMatText = pMath->text();
     sMatText.chop( 1 );
     pMath->setText( sMatText );
 }
 void QtWidgetsApplication1::on_btnAdd_clicked()
 {
     sOperString = " + ";
     operFunction( sOperString );
     _cOper = '+';
 }
 void QtWidgetsApplication1::on_btnSub_clicked()
 {
     sOperString = " - ";
     operFunction( sOperString );
     _cOper = '-';
 }
 void QtWidgetsApplication1::on_btnMul_clicked()
 {
     sOperString = " * ";
     operFunction( sOperString );
     _cOper = '*';
 }
 void QtWidgetsApplication1::on_btnDivison_clicked()
 {
     sOperString = " / ";
     operFunction( sOperString );
     _cOper = '/';
 }
 void QtWidgetsApplication1::on_btnEnter_clicked()
 {
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     QLabel* pCal = this->findChild <QLabel*>( "txtCal" );
     sMatText = pMath->text();
     if( bEquel == false )
     {
         sMathString.clear();
         sMathString.append( sMatText );
         bEquel = true;
     }
     else
     {
         if( _cOper != '^' )
         {
             calText.append( QString::number( _dResult ) );
             calText.append( " " );
             calText.append( _cOper );
             calText.append( " " );
         }
     }
     if( sMatText.isEmpty() == true )
         sMathString = QString::number( _dResult );
     _dNum = sMathString.toDouble();
     if( _cOper == '^' )
         _dResult = sMatText.toDouble();
     else
     {
         if( _cOper == '-' )
             _dResult -= _dNum;
         else if( _cOper == '+' )
             _dResult += _dNum;
         else if( _cOper == '*' )
             _dResult *= _dNum;
         else if( _cOper == '/' )
             _dResult /= _dNum;
     }
     calText.append( sMathString );
     calText.append( " = " );
     pCal->setText( calText );
     pMath->setText( QString::number( _dResult ) );
     calText.clear();
     sMatText.clear();
 }
 void QtWidgetsApplication1::on_btnSign_clicked()
 {
     QLabel* pMath = this->findChild<QLabel*>( "txtMath" );
     QLabel* pCal = this->findChild <QLabel*>( "txtCal" );
     if( bEquel == true )
     {
         sMatText = pMath->text();
         _cOper = '^';
         calText.clear();
         calText.append( calText );
         bEquel = false;
     }
     if( sMatText.isEmpty() == true )
     {
         sMatText = QString::number( _dResult );
         if( sMatText[ 0 ] != '-' )
             sMatText = "-" + sMatText;
         else
             sMatText.remove( 0, 1 );
     }
     else
     {
         if( sMatText[ 0 ] != '-' )
             sMatText = "-" + sMatText;
         else
             sMatText.remove( 0, 1 );
     }
     pMath->setText( sMatText );
     _dNum = sMatText.toDouble();
 }
 void QtWidgetsApplication1::keyPressEvent( QKeyEvent* pe )
 {
     switch( pe->key() )
     {
         case Qt::Key_0:
         {
             ui.btnNum0->setStyleSheet( BUTTON_CSS );
             on_btnNum0_clicked();
         }break;
         case Qt::Key_1:
         {
             ui.btnNum1->setStyleSheet( BUTTON_CSS );
             on_btnNum1_clicked();
         }break;
         case Qt::Key_2:
         {
             ui.btnNum2->setStyleSheet( BUTTON_CSS );
             on_btnNum2_clicked();
         }break;
         case Qt::Key_3:
         {
             ui.btnNum3->setStyleSheet( BUTTON_CSS );
             on_btnNum3_clicked();
         }break;
         case Qt::Key_4:
         {
             ui.btnNum4->setStyleSheet( BUTTON_CSS );
             on_btnNum4_clicked();
         }break;
         case Qt::Key_5:
         {
             ui.btnNum5->setStyleSheet( BUTTON_CSS );
             on_btnNum5_clicked();
         }break;
         case Qt::Key_6:
         {
             ui.btnNum6->setStyleSheet( BUTTON_CSS );
             on_btnNum6_clicked();
         }break;
         case Qt::Key_7:
         {
             ui.btnNum7->setStyleSheet( BUTTON_CSS );
             on_btnNum7_clicked();
         }break;
         case Qt::Key_8:
         {
             ui.btnNum8->setStyleSheet( BUTTON_CSS );
             on_btnNum8_clicked();
         }break;
         case Qt::Key_9:
         {
             ui.btnNum9->setStyleSheet( BUTTON_CSS );
             on_btnNum9_clicked();
         } break;
         case Qt::Key_Plus:
         {
             ui.btnAdd->setStyleSheet( BUTTON_CSS );
             on_btnAdd_clicked();
         }break;
         case Qt::Key_Minus:
         {
             ui.btnSub->setStyleSheet( BUTTON_CSS );
             on_btnSub_clicked();
         }break;
         case Qt::Key_Slash:
         {
             ui.btnDivison->setStyleSheet( BUTTON_CSS );
             on_btnDivison_clicked();
         } break;
         case Qt::Key_Asterisk:
         {
             ui.btnMul->setStyleSheet( BUTTON_CSS );
             on_btnMul_clicked();
         }break;
         case Qt::Key_Backspace:
         {
             ui.btnErase->setStyleSheet( BUTTON_CSS );
             on_btnErase_clicked();
         } break;
         case Qt::Key_Delete:
         {
             ui.btnCe->setStyleSheet( BUTTON_CSS );
             on_btnCe_clicked();
         } break;
         case Qt::Key_Escape:
         {
             ui.btnC->setStyleSheet( BUTTON_CSS );
             on_btnC_clicked();
         }break;
         case Qt::Key_Period:
         {
             ui.btnPoint->setStyleSheet( BUTTON_CSS );
             on_btnPoint_clicked();
         } break;
         case Qt::Key_Enter:
         {
             QString sStyle = "QPushButton:!hover { background-color : rgb( 70,70,70 ); color: rgb( 255, 255, 255 ); } QPushButton:hover{ background-color : rgb( 197,197,197 );  color: rgb( 0, 0, 0 ); } QPushButton:pressed{ background-color : rgb( 107,107,107 ); color: rgb( 255, 255, 255 ); }";
             ui.btnEnter->setStyleSheet( sStyle );
             on_btnEnter_clicked();
         }break;
     }
 }
 void QtWidgetsApplication1::keyReleaseEvent( QKeyEvent* pe )
 {
     switch( pe->key() )
     {
         case Qt::Key_0:
         {
             ui.btnNum0->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_1:
         {
             ui.btnNum1->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_2:
         {
             ui.btnNum2->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_3:
         {
             ui.btnNum3->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_4:
         {
             ui.btnNum4->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_5:
         {
             ui.btnNum5->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_6:
         {
             ui.btnNum6->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_7:
         {
             ui.btnNum7->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_8:
         {
             ui.btnNum8->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_9:
         {
             ui.btnNum9->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Plus:
         {
             ui.btnAdd->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Minus:
         {
             ui.btnSub->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Slash:
         {
             ui.btnDivison->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Asterisk:
         {
             ui.btnMul->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Backspace:
         {
             ui.btnErase->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Delete:
         {
             ui.btnCe->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Escape:
         {
             ui.btnC->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Period:
         {
             ui.btnPoint->setStyleSheet( BUTTON_SSC );
         }break;
         case Qt::Key_Enter:
         {
             QString sStyle = "QPushButton:!hover { background-color : rgb( 107,107,107 ); color: rgb(255, 255, 255); } QPushButton:hover{ background-color : rgb(197,197,197);  color: rgb( 0, 0, 0 ); } QPushButton:pressed{ background-color : rgb( 70,70,70 ); color: rgb( 255, 255, 255 ); }";
             ui.btnEnter->setStyleSheet( sStyle );
         }break;
     }
 }