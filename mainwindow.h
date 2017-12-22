#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* =================================================
 * This file is part of the Gaussian Blur project
 * Copyright (C) 2016 - 2017 Greedysky Studio
   ================================================= */

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected Q_SLOTS:
    void openImage();
    void radiusChanged(int value);

private:
    Ui::MainWindow *ui;
    QString m_path;

};

#endif // MAINWINDOW_H
