#include "window.hpp"

#include <iostream>
#include <QVBoxLayout>

Tester::Tester(QWidget* parent)
:QMainWindow(parent), mButtonPressedAmt(0)
{
    //Since this is a QMainWindow we cannot set a layout,
    //we can only set a central widget.
    auto centralWidget = new QWidget(this);

    this->mpLabel = new QLabel(centralWidget);
    this->mpPushButton = new QPushButton("Press Me!", centralWidget);

    //Make sure our label has the correct text
    //starting out.
    this->updateLabelText();

    //Since setting a layout on QMainWindow is not allowed,
    //this layout is used in centralWidget instead.
    auto mainLayout = new QVBoxLayout();
    mainLayout->addWidget(this->mpLabel);
    mainLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Fixed));
    mainLayout->addWidget(this->mpPushButton);

    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

    //Syntax to connect a Qt signal with a lambda.
    QObject::connect(this->mpPushButton, &QPushButton::clicked, this, [this](){
        this->mButtonPressedAmt++;
        this->updateLabelText();
    });

    //Syntax to connect a custom class signal with a lambda.
    QObject::connect(this, &Tester::sigLabelTextUpdated, this, [](std::string_view val){
        std::cout << val << std::endl;
    });
}

void Tester::updateLabelText()
{
    this->mpLabel->setText("Button was clicked: " + QString::number(this->mButtonPressedAmt) + " times.");

    emit sigLabelTextUpdated(this->mpLabel->text().toStdString());
}
