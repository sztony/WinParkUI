#include "vzmainwindow.h"
#include "ui_vzmainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QDateTime>

VZMainWindow::VZMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VZMainWindow)
{
    ui->setupUi(this);
    pAnalogCamera = NULL;
    connect( QPlateThread::GetInstance( ), SIGNAL( PlateResult( QStringList, int, bool, bool ) ),
             this, SLOT( HandlePlateResult( QStringList, int, bool, bool ) ) );
    QCommon::GetPlatePicPath( strPlateDir );
    LoadLogoTitle( );

    aLables[ 0 ] = ui->lblVideo0;
    aLables[ 1 ] = ui->lblVideo1;
    aLables[ 2 ] = ui->lblVideo2;
    aLables[ 3 ] = ui->lblVideo3;
    //ImageFormatYUV420COMPASS : ImageFormatBGR
    QPlateThread::GetInstance( )->PostPlateInitEvent( ImageFormatBGR, 0 ); // HK
    //QPlateThread::GetInstance( )->PostPlateInitEvent( ImageFormatBGR, 1 );

    //QPlateThread::GetInstance( )->PostPlateInitEvent( ImageFormatRGB, 0 ); //TM
    //QPlateThread::GetInstance( )->PostPlateInitEvent( ImageFormatRGB, 1 );
    //QPlateThread::GetInstance( )->PostPlateInitEvent( ImageFormatRGB, 2 );
    //QPlateThread::GetInstance( )->PostPlateInitEvent( ImageFormatRGB, 3 );
}

VZMainWindow::~VZMainWindow()
{
    delete ui;
}

void VZMainWindow::LoadLogoTitle( )
{
    QString strPath;
    QString strNameFilter = "logo_*.*";
    QDir dir( strPath, strNameFilter, QDir::Unsorted, QDir::NoDotAndDotDot | QDir::Files );

    QFileInfoList lstFiles = dir.entryInfoList( );

    if ( 0 == lstFiles.count( ) ) {
        return;
    }

    const QFileInfo& fileInfo = lstFiles.at( 0 );
    QString strFile = fileInfo.absoluteFilePath( );

    QIcon winIcon( strFile );
    setWindowIcon( winIcon );

    QPixmap lblPic( strFile );
    ui->lblPicture->setPixmap( lblPic );

    QString strSuffix = "." + fileInfo.suffix( ).toLower( );
    strSuffix = fileInfo.baseName( ).toLower( ).remove( "logo_" ).remove( strSuffix );
    setWindowTitle( strSuffix );
}

void VZMainWindow::HandlePlateResult( QStringList lstResult, int nChannel, bool bSuccess, bool bVideo )
{
    ui->tabResult->insertRow( 0 );
    qint32 nCol = 0;
    QTableWidgetItem* pItem;
    lstResult << QString::number( nChannel ) << ( bVideo ? "是" : "否" );

    foreach ( const QString& str, lstResult ) {
        pItem = new QTableWidgetItem( str );
        pItem->setFlags( Qt::ItemIsEnabled | Qt::ItemIsSelectable );
        ui->tabResult->setItem( 0, nCol++, pItem );
    }

    if ( !bVideo ) {
        LoadImg( ui->lblVideo0, ui->lblPicture, ui->lblPlatePic, 0 );
    }
     //qDebug( ) << Q_FUNC_INFO << ":" << lstResult.join( "," ) << endl;
}

void VZMainWindow::HandleCaptureImage( QString strFile, int nChannel )
{

}

void VZMainWindow::HandleNotifyMessage( QString strMsg, bool bSuccess )
{

}

void VZMainWindow::HandleDetectInfo( int nChannel, bool bMotion )
{

}

void VZMainWindow::on_btnFile_clicked()
{
    QFileDialog dlg;
    QString strFile = dlg.getOpenFileName( );

    if ( strFile.isEmpty( ) ) {
        return;
    }

    QDir dir( strFile );
    dir.cdUp( );
    strFile = dir.path( );

    QDirectoryThread::GetInstance( )->PostDirectoryTraverse( strFile );
}

void VZMainWindow::on_tabResult_cellClicked(int row, int column)
{
    column = 0;
    if ( QString( "否" ) == ui->tabResult->item( row, ui->tabResult->columnCount( ) - 1 )->text() ) {
        LoadImg( ui->lblVideo0, ui->lblPicture, ui->lblPlatePic, row );
    }
}

void VZMainWindow::LoadImg( QLabel *lblCtrlLeft, QLabel *lblCtrlRight, QLabel* lblCtrlDown, int nRow )
{
    QTableWidget* tabWid = ui->tabResult;
    int nCol = tabWid->columnCount( ) - 1;
    QTableWidgetItem* pItem = tabWid->item( nRow, nCol - 2 );

    if ( NULL == pItem ) {
        return;
    }

    QString strFile = pItem->text( );

    if ( strFile.isEmpty( ) ) {
        return;
    }

    QPixmap picMap( strFile );
    lblCtrlLeft->setPixmap( picMap );
    lblCtrlRight->setPixmap( picMap );

    strFile = tabWid->item( nRow, nCol - 1 )->text( );
    QPixmap plateMap( strFile );
    lblCtrlDown->setPixmap( plateMap );
}

void VZMainWindow::on_btnClear_clicked()
{
    for ( int nIndex = ui->tabResult->rowCount( ) - 1 ; nIndex >= 0; nIndex-- ) {
        ui->tabResult->removeRow( nIndex );
    }

    ui->lblPicture->clear( );
    ui->lblPlatePic->clear( );
    ui->lblVideo0->clear( );
}

void VZMainWindow::on_btnAnalogCamera_clicked()
{
    if ( NULL != pAnalogCamera ) {
        return;
    }

    //pAnalogCamera = QTmCaptureCardThread::GetInstance( );
    pAnalogCamera = QHkCaptureCardThread::GetInstance( );

    connect( pAnalogCamera, SIGNAL( CaptureImage( QString, int ) ),
             this, SLOT( HandleCaptureImage( QString, int ) ) );
    connect( pAnalogCamera, SIGNAL( NotifyMessage( QString, bool ) ),
             this, SLOT( HandleNotifyMessage( QString, bool ) ) );
    connect( pAnalogCamera, SIGNAL( DetectInfo( int, bool ) ),
             this, SLOT( HandleDetectInfo( int, bool ) ) );

    pAnalogCamera->PostInitCaptureSDKEvent( winId( ) );

    for ( int nChannel = 0; nChannel < CHANNEL_WAY - 2; nChannel++ ) {
        pAnalogCamera->PostOpenChannelEvent( nChannel );
        pAnalogCamera->PostPlayVideoEvent( nChannel, aLables[ nChannel ]->winId( ) );
        pAnalogCamera->PostStartCaptureEvent( nChannel );
        pAnalogCamera->PostStartMotionDetectEvent( nChannel );
        pAnalogCamera->PostStartSourceStreamEvent( nChannel, 0 == nChannel );
    }
}

void VZMainWindow::on_btnDigitalCamera_clicked()
{

}

void VZMainWindow::on_btnVideoFile_clicked()
{

}

void VZMainWindow::on_btnAnalogCaptureFile_clicked()
{
    if ( NULL == pAnalogCamera ) {
        return;
    }

    int nChannel = 0;

    QString strFile = strPlateDir + QString::number( QDateTime::currentMSecsSinceEpoch( ) ) + ".JPG";
    pAnalogCamera->PostCaptrueImageEvent( nChannel, strFile, true );
}

void VZMainWindow::on_btnIPCCaptureFile_clicked()
{

}

void VZMainWindow::on_btnStopVideoRecognize_clicked()
{
    bool bFlag = QPlateThread::GetInstance( )->SetRecognizeFlag( );

    ui->btnStopVideoRecognize->setText( bFlag ? "启动视频识别" : "停止视频识别" );
}
