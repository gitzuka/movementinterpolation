/********************************************************************************
** Form generated from reading UI file 'movementinterpolation.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVEMENTINTERPOLATION_H
#define UI_MOVEMENTINTERPOLATION_H

#include <MyOpenGLWindow.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovementInterpolationClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    MyOpenGLWindow *openGLWidget_left;
    MyOpenGLWindow *openGLWidget_right;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_17;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_startPosX;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_startPosY;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_startPosZ;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_endPosX;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_endPosY;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_endPosZ;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_26;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_24;
    QDoubleSpinBox *doubleSpinBox_startEulerX;
    QLabel *label_23;
    QDoubleSpinBox *doubleSpinBox_startEulerY;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_startEulerZ;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_endEulerX;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_endEulerY;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_endEulerZ;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_18;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_startQuatX;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_startQuatY;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_startQuatZ;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_startQuatW;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_endQuatX;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_endQuatY;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBox_endQuatZ;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_endQuatW;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Reset;
    QComboBox *comboBox_s_lerp;
    QCheckBox *checkBox_steps;
    QLabel *label_27;
    QSpinBox *spinBox_frames;
    QLabel *label_28;
    QSpinBox *spinBox_time;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MovementInterpolationClass)
    {
        if (MovementInterpolationClass->objectName().isEmpty())
            MovementInterpolationClass->setObjectName(QStringLiteral("MovementInterpolationClass"));
        MovementInterpolationClass->resize(1078, 670);
        centralWidget = new QWidget(MovementInterpolationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        openGLWidget_left = new MyOpenGLWindow(centralWidget);
        openGLWidget_left->setObjectName(QStringLiteral("openGLWidget_left"));
        openGLWidget_left->setMouseTracking(true);
        openGLWidget_left->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(openGLWidget_left);

        openGLWidget_right = new MyOpenGLWindow(centralWidget);
        openGLWidget_right->setObjectName(QStringLiteral("openGLWidget_right"));
        openGLWidget_right->setMouseTracking(true);
        openGLWidget_right->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(openGLWidget_right);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_4->addWidget(label_17);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBox_startPosX = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startPosX->setObjectName(QStringLiteral("doubleSpinBox_startPosX"));
        doubleSpinBox_startPosX->setMinimum(-3);
        doubleSpinBox_startPosX->setMaximum(3);
        doubleSpinBox_startPosX->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_startPosX);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_4);

        doubleSpinBox_startPosY = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startPosY->setObjectName(QStringLiteral("doubleSpinBox_startPosY"));
        doubleSpinBox_startPosY->setMinimum(-3);
        doubleSpinBox_startPosY->setMaximum(3);
        doubleSpinBox_startPosY->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_startPosY);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_5);

        doubleSpinBox_startPosZ = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startPosZ->setObjectName(QStringLiteral("doubleSpinBox_startPosZ"));
        doubleSpinBox_startPosZ->setMinimum(-3);
        doubleSpinBox_startPosZ->setMaximum(3);
        doubleSpinBox_startPosZ->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_startPosZ);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_6);

        doubleSpinBox_endPosX = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endPosX->setObjectName(QStringLiteral("doubleSpinBox_endPosX"));
        doubleSpinBox_endPosX->setMinimum(-3);
        doubleSpinBox_endPosX->setMaximum(3);
        doubleSpinBox_endPosX->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_endPosX);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_15);

        doubleSpinBox_endPosY = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endPosY->setObjectName(QStringLiteral("doubleSpinBox_endPosY"));
        doubleSpinBox_endPosY->setMinimum(-3);
        doubleSpinBox_endPosY->setMaximum(3);
        doubleSpinBox_endPosY->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_endPosY);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_14);

        doubleSpinBox_endPosZ = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endPosZ->setObjectName(QStringLiteral("doubleSpinBox_endPosZ"));
        doubleSpinBox_endPosZ->setDecimals(2);
        doubleSpinBox_endPosZ->setMinimum(-3);
        doubleSpinBox_endPosZ->setMaximum(3);
        doubleSpinBox_endPosZ->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_endPosZ);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_7->addWidget(label_26);

        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_7->addWidget(label_25);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_24);

        doubleSpinBox_startEulerX = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startEulerX->setObjectName(QStringLiteral("doubleSpinBox_startEulerX"));
        doubleSpinBox_startEulerX->setDecimals(0);
        doubleSpinBox_startEulerX->setMaximum(359);

        horizontalLayout_6->addWidget(doubleSpinBox_startEulerX);

        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_23);

        doubleSpinBox_startEulerY = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startEulerY->setObjectName(QStringLiteral("doubleSpinBox_startEulerY"));
        doubleSpinBox_startEulerY->setDecimals(0);
        doubleSpinBox_startEulerY->setMaximum(359);

        horizontalLayout_6->addWidget(doubleSpinBox_startEulerY);

        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_22);

        doubleSpinBox_startEulerZ = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startEulerZ->setObjectName(QStringLiteral("doubleSpinBox_startEulerZ"));
        doubleSpinBox_startEulerZ->setDecimals(0);
        doubleSpinBox_startEulerZ->setMaximum(359);

        horizontalLayout_6->addWidget(doubleSpinBox_startEulerZ);

        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_21);

        doubleSpinBox_endEulerX = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endEulerX->setObjectName(QStringLiteral("doubleSpinBox_endEulerX"));
        doubleSpinBox_endEulerX->setDecimals(0);
        doubleSpinBox_endEulerX->setMaximum(359);

        horizontalLayout_6->addWidget(doubleSpinBox_endEulerX);

        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_20);

        doubleSpinBox_endEulerY = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endEulerY->setObjectName(QStringLiteral("doubleSpinBox_endEulerY"));
        doubleSpinBox_endEulerY->setDecimals(0);
        doubleSpinBox_endEulerY->setMaximum(359);

        horizontalLayout_6->addWidget(doubleSpinBox_endEulerY);

        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(label_19);

        doubleSpinBox_endEulerZ = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endEulerZ->setObjectName(QStringLiteral("doubleSpinBox_endEulerZ"));
        doubleSpinBox_endEulerZ->setDecimals(0);
        doubleSpinBox_endEulerZ->setMaximum(359);

        horizontalLayout_6->addWidget(doubleSpinBox_endEulerZ);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_5->addWidget(label_18);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_12);

        doubleSpinBox_startQuatX = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startQuatX->setObjectName(QStringLiteral("doubleSpinBox_startQuatX"));
        doubleSpinBox_startQuatX->setDecimals(3);
        doubleSpinBox_startQuatX->setMinimum(-1);
        doubleSpinBox_startQuatX->setMaximum(1);
        doubleSpinBox_startQuatX->setSingleStep(0.01);

        horizontalLayout_3->addWidget(doubleSpinBox_startQuatX);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_7);

        doubleSpinBox_startQuatY = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startQuatY->setObjectName(QStringLiteral("doubleSpinBox_startQuatY"));
        doubleSpinBox_startQuatY->setDecimals(3);
        doubleSpinBox_startQuatY->setMinimum(-1);
        doubleSpinBox_startQuatY->setMaximum(1);
        doubleSpinBox_startQuatY->setSingleStep(0.01);

        horizontalLayout_3->addWidget(doubleSpinBox_startQuatY);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_8);

        doubleSpinBox_startQuatZ = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startQuatZ->setObjectName(QStringLiteral("doubleSpinBox_startQuatZ"));
        doubleSpinBox_startQuatZ->setDecimals(3);
        doubleSpinBox_startQuatZ->setMinimum(-1);
        doubleSpinBox_startQuatZ->setMaximum(1);
        doubleSpinBox_startQuatZ->setSingleStep(0.01);

        horizontalLayout_3->addWidget(doubleSpinBox_startQuatZ);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_11);

        doubleSpinBox_startQuatW = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_startQuatW->setObjectName(QStringLiteral("doubleSpinBox_startQuatW"));
        doubleSpinBox_startQuatW->setDecimals(3);
        doubleSpinBox_startQuatW->setMinimum(-1);
        doubleSpinBox_startQuatW->setMaximum(1);
        doubleSpinBox_startQuatW->setSingleStep(0.01);
        doubleSpinBox_startQuatW->setValue(1);

        horizontalLayout_3->addWidget(doubleSpinBox_startQuatW);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setWordWrap(false);

        horizontalLayout_3->addWidget(label_10);

        doubleSpinBox_endQuatX = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endQuatX->setObjectName(QStringLiteral("doubleSpinBox_endQuatX"));
        doubleSpinBox_endQuatX->setDecimals(3);
        doubleSpinBox_endQuatX->setMinimum(-1);
        doubleSpinBox_endQuatX->setMaximum(1);
        doubleSpinBox_endQuatX->setSingleStep(0.01);

        horizontalLayout_3->addWidget(doubleSpinBox_endQuatX);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_9);

        doubleSpinBox_endQuatY = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endQuatY->setObjectName(QStringLiteral("doubleSpinBox_endQuatY"));
        doubleSpinBox_endQuatY->setDecimals(3);
        doubleSpinBox_endQuatY->setMinimum(-1);
        doubleSpinBox_endQuatY->setMaximum(1);
        doubleSpinBox_endQuatY->setSingleStep(0.01);

        horizontalLayout_3->addWidget(doubleSpinBox_endQuatY);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_16);

        doubleSpinBox_endQuatZ = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endQuatZ->setObjectName(QStringLiteral("doubleSpinBox_endQuatZ"));
        doubleSpinBox_endQuatZ->setDecimals(3);
        doubleSpinBox_endQuatZ->setMaximum(1);
        doubleSpinBox_endQuatZ->setSingleStep(0.01);

        horizontalLayout_3->addWidget(doubleSpinBox_endQuatZ);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_13);

        doubleSpinBox_endQuatW = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_endQuatW->setObjectName(QStringLiteral("doubleSpinBox_endQuatW"));
        doubleSpinBox_endQuatW->setDecimals(3);
        doubleSpinBox_endQuatW->setMinimum(-1);
        doubleSpinBox_endQuatW->setMaximum(1);
        doubleSpinBox_endQuatW->setSingleStep(0.01);
        doubleSpinBox_endQuatW->setValue(1);

        horizontalLayout_3->addWidget(doubleSpinBox_endQuatW);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_Start = new QPushButton(centralWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));

        horizontalLayout_8->addWidget(pushButton_Start);

        pushButton_Reset = new QPushButton(centralWidget);
        pushButton_Reset->setObjectName(QStringLiteral("pushButton_Reset"));

        horizontalLayout_8->addWidget(pushButton_Reset);

        comboBox_s_lerp = new QComboBox(centralWidget);
        comboBox_s_lerp->setObjectName(QStringLiteral("comboBox_s_lerp"));

        horizontalLayout_8->addWidget(comboBox_s_lerp);

        checkBox_steps = new QCheckBox(centralWidget);
        checkBox_steps->setObjectName(QStringLiteral("checkBox_steps"));

        horizontalLayout_8->addWidget(checkBox_steps);

        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QStringLiteral("label_27"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_27);

        spinBox_frames = new QSpinBox(centralWidget);
        spinBox_frames->setObjectName(QStringLiteral("spinBox_frames"));

        horizontalLayout_8->addWidget(spinBox_frames);

        label_28 = new QLabel(centralWidget);
        label_28->setObjectName(QStringLiteral("label_28"));
        sizePolicy1.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_28);

        spinBox_time = new QSpinBox(centralWidget);
        spinBox_time->setObjectName(QStringLiteral("spinBox_time"));
        spinBox_time->setMinimum(1);
        spinBox_time->setValue(1);

        horizontalLayout_8->addWidget(spinBox_time);


        gridLayout->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout->setStretch(0, 1);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        MovementInterpolationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MovementInterpolationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1078, 21));
        MovementInterpolationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MovementInterpolationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MovementInterpolationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MovementInterpolationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MovementInterpolationClass->setStatusBar(statusBar);

        retranslateUi(MovementInterpolationClass);

        QMetaObject::connectSlotsByName(MovementInterpolationClass);
    } // setupUi

    void retranslateUi(QMainWindow *MovementInterpolationClass)
    {
        MovementInterpolationClass->setWindowTitle(QApplication::translate("MovementInterpolationClass", "MovementInterpolation", Q_NULLPTR));
        label_17->setText(QApplication::translate("MovementInterpolationClass", "Strart position", Q_NULLPTR));
        label->setText(QApplication::translate("MovementInterpolationClass", "End position", Q_NULLPTR));
        label_3->setText(QApplication::translate("MovementInterpolationClass", "X:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MovementInterpolationClass", "Y:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MovementInterpolationClass", "Z:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MovementInterpolationClass", "X:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MovementInterpolationClass", "Y:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MovementInterpolationClass", "Z:", Q_NULLPTR));
        label_26->setText(QApplication::translate("MovementInterpolationClass", "Start euler rotation", Q_NULLPTR));
        label_25->setText(QApplication::translate("MovementInterpolationClass", "End euler rotation", Q_NULLPTR));
        label_24->setText(QApplication::translate("MovementInterpolationClass", "X:", Q_NULLPTR));
        label_23->setText(QApplication::translate("MovementInterpolationClass", "Y:", Q_NULLPTR));
        label_22->setText(QApplication::translate("MovementInterpolationClass", "Z:", Q_NULLPTR));
        label_21->setText(QApplication::translate("MovementInterpolationClass", "X:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MovementInterpolationClass", "Y:", Q_NULLPTR));
        label_19->setText(QApplication::translate("MovementInterpolationClass", "Z:", Q_NULLPTR));
        label_18->setText(QApplication::translate("MovementInterpolationClass", "Start quaternion rotation", Q_NULLPTR));
        label_2->setText(QApplication::translate("MovementInterpolationClass", "End quaternion rotation", Q_NULLPTR));
        label_12->setText(QApplication::translate("MovementInterpolationClass", "X:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MovementInterpolationClass", "Y:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MovementInterpolationClass", "Z:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MovementInterpolationClass", "W:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MovementInterpolationClass", "X:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MovementInterpolationClass", "Y:", Q_NULLPTR));
        label_16->setText(QApplication::translate("MovementInterpolationClass", "Z:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MovementInterpolationClass", "W:", Q_NULLPTR));
        pushButton_Start->setText(QApplication::translate("MovementInterpolationClass", "Start", Q_NULLPTR));
        pushButton_Reset->setText(QApplication::translate("MovementInterpolationClass", "Reset", Q_NULLPTR));
        comboBox_s_lerp->clear();
        comboBox_s_lerp->insertItems(0, QStringList()
         << QApplication::translate("MovementInterpolationClass", "slerp", Q_NULLPTR)
         << QApplication::translate("MovementInterpolationClass", "lerp", Q_NULLPTR)
        );
        checkBox_steps->setText(QApplication::translate("MovementInterpolationClass", "Show steps", Q_NULLPTR));
        label_27->setText(QApplication::translate("MovementInterpolationClass", "Steps:", Q_NULLPTR));
        label_28->setText(QApplication::translate("MovementInterpolationClass", "Animation time", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MovementInterpolationClass: public Ui_MovementInterpolationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVEMENTINTERPOLATION_H
