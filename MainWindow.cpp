#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->radioButton->setObjectName("rb1");
    ui->radioButton_2->setObjectName("rb2");

    ui->comboBox->addItem("Item 1");
    ui->comboBox->addItem("Item 2");
    ui->comboBox->addItem("Item 3");
    ui->comboBox->addItem("Item 4");
    ui->comboBox->addItem("Item 5");

    ui->pushButton->setText("Do it");

    ui->pushButton->setCheckable(true);

    ui->progressBar->setRange(0, 10);
    ui->progressBar->setValue(0);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onPushButtonClicked() {
    int currentValue = ui->progressBar->value();
    int max = ui->progressBar->maximum();
    int step = max * 0.10;  // 10% от максимума
    int newValue = currentValue + step;

    if (newValue > max) {
        newValue = 0;
    }

    ui->progressBar->setValue(newValue);
}
