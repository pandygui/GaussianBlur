#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gaussianblur.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->valueSlider->setRange(1, 100);

    connect(ui->openButton, SIGNAL(clicked(bool)), SLOT(openImage()));
    connect(ui->valueSlider, SIGNAL(valueChanged(int)), SLOT(radiusChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage()
{
    m_path = QFileDialog::getOpenFileName(this, "Please Image", "", "Images (*.png *.bmp *.jpg)");
    if(m_path.isEmpty())
    {
        return;
    }

    ui->valueSlider->setValue(1);
    ui->originPixLabel->setPixmap(QPixmap(m_path));
    ui->resultPixLabel->setPixmap(QPixmap(m_path));
}

void MainWindow::radiusChanged(int value)
{
    if(m_path.isEmpty())
    {
        return;
    }

    QImage image(m_path);
    GaussianBlur().gaussBlur(image, value);
    ui->resultPixLabel->setPixmap(QPixmap::fromImage(image));
}
