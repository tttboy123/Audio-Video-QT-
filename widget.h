#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QListWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QPushButton>
#include "golbal.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void setget_alltime(qint64 playtime);//获取视频时长设置标签
    void setget_currenttime(qint64 playtime);//获取当前视频时长并设置
    void settimeslider(qint64 playtime);//设置进度条
    ~Widget();

private slots:
    void on_btn_open_clicked();//打开音视频
    void on_btn_start_clicked();//播放
    void on_btn_stop_clicked();//暂停
    void on_voice_control_valueChanged(int value);//控制音量
    void on_btn_fullshow_clicked();//全屏显示
    void getduration(qint64 playtime);//获取时间改变信号
    void getposition(qint64 playtime);//获取当前播放位置
    void on_btn_last_clicked();//获取上一个视频
    void on_btn_next_clicked();//获取下一个视频
    void on_listWidget_doubleClicked(const QModelIndex &index);
protected:
    void resizeEvent(QResizeEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    Ui::Widget *ui;
    QStringList m_strlst;//文件列表
    QMediaPlayer* m_pMediaPlayer;//播放器
    QVideoWidget* m_pVideoWidget;//播放窗口
    QMediaPlaylist* m_MediaPlaylist;//播放列表
    QMediaPlayer::State m_state; //视频状态
    int m_hour;//总时长
    int m_minute;//分钟
    int m_second;//秒
    bool m_sliderstate; //滑块是否被选中
    int m_slider_crtval;//当前滑块值
    QPushButton* open_dir;
    QLabel* label = new QLabel;
};
#endif // WIDGET_H
