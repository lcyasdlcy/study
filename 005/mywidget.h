#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QSystemTrayIcon>
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event);
signals:

public slots:
    void onTrayAction(QSystemTrayIcon::ActivationReason reason);

private:
    QSystemTrayIcon *tray;
    QMenu *menu;
    QAction *restore;
    QAction *quit;
};

#endif // MYWIDGET_H
