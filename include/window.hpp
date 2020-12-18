#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class Tester : public QMainWindow
{
    Q_OBJECT

    int32_t mButtonPressedAmt;

    QLabel* mpLabel;
    QPushButton* mpPushButton;

    void updateLabelText();

public:
    Tester(QWidget* parent = nullptr);
    ~Tester() = default;

signals:
    void sigLabelTextUpdated(std::string_view);
};