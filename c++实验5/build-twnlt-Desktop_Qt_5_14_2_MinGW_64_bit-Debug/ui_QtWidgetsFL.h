/********************************************************************************
** Form generated from reading UI file 'QtWidgetsFL.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSFL_H
#define UI_QTWIDGETSFL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsFL
{
public:
    QLabel *labelWind;
    QTextEdit *textEditStop;
    QTextEdit *textEditLine;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonLine;
    QLabel *labelStop;
    QLabel *labelStop_2;
    QLabel *labelHits;
    QPushButton *pushButtonDone;
    QPushButton *pushButtonQuit;

    void setupUi(QWidget *QtWidgetsFL)
    {
        if (QtWidgetsFL->objectName().isEmpty())
            QtWidgetsFL->setObjectName(QString::fromUtf8("QtWidgetsFL"));
        QtWidgetsFL->resize(635, 300);
        QtWidgetsFL->setMinimumSize(QSize(635, 300));
        QtWidgetsFL->setMaximumSize(QSize(635, 300));
        labelWind = new QLabel(QtWidgetsFL);
        labelWind->setObjectName(QString::fromUtf8("labelWind"));
        labelWind->setGeometry(QRect(200, 30, 231, 20));
        textEditStop = new QTextEdit(QtWidgetsFL);
        textEditStop->setObjectName(QString::fromUtf8("textEditStop"));
        textEditStop->setGeometry(QRect(120, 110, 341, 31));
        textEditLine = new QTextEdit(QtWidgetsFL);
        textEditLine->setObjectName(QString::fromUtf8("textEditLine"));
        textEditLine->setGeometry(QRect(120, 180, 351, 31));
        pushButtonStop = new QPushButton(QtWidgetsFL);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(542, 110, 71, 28));
        pushButtonLine = new QPushButton(QtWidgetsFL);
        pushButtonLine->setObjectName(QString::fromUtf8("pushButtonLine"));
        pushButtonLine->setGeometry(QRect(540, 180, 71, 28));
        labelStop = new QLabel(QtWidgetsFL);
        labelStop->setObjectName(QString::fromUtf8("labelStop"));
        labelStop->setGeometry(QRect(50, 120, 72, 15));
        labelStop_2 = new QLabel(QtWidgetsFL);
        labelStop_2->setObjectName(QString::fromUtf8("labelStop_2"));
        labelStop_2->setGeometry(QRect(40, 190, 72, 15));
        labelHits = new QLabel(QtWidgetsFL);
        labelHits->setObjectName(QString::fromUtf8("labelHits"));
        labelHits->setGeometry(QRect(20, 260, 561, 31));
        pushButtonDone = new QPushButton(QtWidgetsFL);
        pushButtonDone->setObjectName(QString::fromUtf8("pushButtonDone"));
        pushButtonDone->setGeometry(QRect(120, 230, 93, 28));
        pushButtonQuit = new QPushButton(QtWidgetsFL);
        pushButtonQuit->setObjectName(QString::fromUtf8("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(390, 230, 93, 28));

        retranslateUi(QtWidgetsFL);

        QMetaObject::connectSlotsByName(QtWidgetsFL);
    } // setupUi

    void retranslateUi(QWidget *QtWidgetsFL)
    {
        QtWidgetsFL->setWindowTitle(QCoreApplication::translate("QtWidgetsFL", "\346\226\207\344\273\266\345\212\240\350\275\275", nullptr));
        labelWind->setText(QCoreApplication::translate("QtWidgetsFL", "\347\253\231\347\202\271\345\217\212\350\267\257\347\272\277\351\200\211\346\213\251", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("QtWidgetsFL", "\346\265\217\350\247\210...", nullptr));
        pushButtonLine->setText(QCoreApplication::translate("QtWidgetsFL", "\346\265\217\350\247\210...", nullptr));
        labelStop->setText(QCoreApplication::translate("QtWidgetsFL", "\347\253\231\347\202\271\351\200\211\346\213\251", nullptr));
        labelStop_2->setText(QCoreApplication::translate("QtWidgetsFL", "\347\272\277\350\267\257\351\200\211\346\213\251", nullptr));
        labelHits->setText(QString());
        pushButtonDone->setText(QCoreApplication::translate("QtWidgetsFL", "\347\241\256\350\256\244", nullptr));
        pushButtonQuit->setText(QCoreApplication::translate("QtWidgetsFL", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsFL: public Ui_QtWidgetsFL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSFL_H
