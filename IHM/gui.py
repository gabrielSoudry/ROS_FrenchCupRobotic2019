# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ProjetInter.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_DaVinciBot(object):
    def setupUi(self, DaVinciBot):
        DaVinciBot.setObjectName("DaVinciBot")
        DaVinciBot.resize(774, 677)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/images/images/DaVinciBot_Square.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        DaVinciBot.setWindowIcon(icon)
        self.centralwidget = QtWidgets.QWidget(DaVinciBot)
        self.centralwidget.setObjectName("centralwidget")
        self.send_droit = QtWidgets.QPushButton(self.centralwidget)
        self.send_droit.setGeometry(QtCore.QRect(20, 150, 201, 51))
        self.send_droit.setObjectName("send_droit")
        self.spinBox = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox.setGeometry(QtCore.QRect(30, 60, 171, 81))
        self.spinBox.setMinimum(-200)
        self.spinBox.setMaximum(200)
        self.spinBox.setSingleStep(30)
        self.spinBox.setObjectName("spinBox")
        self.lineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit.setEnabled(True)
        self.lineEdit.setGeometry(QtCore.QRect(610, 680, 113, 27))
        self.lineEdit.setObjectName("lineEdit")
        self.textEdit = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit.setGeometry(QtCore.QRect(20, 20, 201, 31))
        self.textEdit.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.textEdit.setFrameShadow(QtWidgets.QFrame.Raised)
        self.textEdit.setObjectName("textEdit")
        self.send_droit_2 = QtWidgets.QPushButton(self.centralwidget)
        self.send_droit_2.setGeometry(QtCore.QRect(280, 150, 201, 51))
        self.send_droit_2.setObjectName("send_droit_2")
        self.textEdit_2 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_2.setGeometry(QtCore.QRect(280, 20, 201, 31))
        self.textEdit_2.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.textEdit_2.setFrameShadow(QtWidgets.QFrame.Raised)
        self.textEdit_2.setObjectName("textEdit_2")
        self.spinBox_2 = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox_2.setGeometry(QtCore.QRect(290, 60, 171, 81))
        self.spinBox_2.setMinimum(-200)
        self.spinBox_2.setMaximum(200)
        self.spinBox_2.setSingleStep(30)
        self.spinBox_2.setObjectName("spinBox_2")
        self.CreateMasterButton = QtWidgets.QPushButton(self.centralwidget)
        self.CreateMasterButton.setGeometry(QtCore.QRect(580, 20, 161, 27))
        self.CreateMasterButton.setObjectName("CreateMasterButton")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_2.setGeometry(QtCore.QRect(610, 710, 113, 25))
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.rese_encoder_right = QtWidgets.QPushButton(self.centralwidget)
        self.rese_encoder_right.setGeometry(QtCore.QRect(580, 100, 161, 27))
        self.rese_encoder_right.setObjectName("rese_encoder_right")
        self.reset_encoder_left = QtWidgets.QPushButton(self.centralwidget)
        self.reset_encoder_left.setGeometry(QtCore.QRect(580, 130, 161, 27))
        self.reset_encoder_left.setObjectName("reset_encoder_left")
        self.state_encoder_left = QtWidgets.QPushButton(self.centralwidget)
        self.state_encoder_left.setGeometry(QtCore.QRect(580, 220, 161, 27))
        self.state_encoder_left.setObjectName("state_encoder_left")
        self.state_encoder_right = QtWidgets.QPushButton(self.centralwidget)
        self.state_encoder_right.setGeometry(QtCore.QRect(580, 250, 161, 27))
        self.state_encoder_right.setObjectName("state_encoder_right")
        self.spinBox_3 = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox_3.setGeometry(QtCore.QRect(30, 260, 171, 81))
        self.spinBox_3.setMinimum(-13000)
        self.spinBox_3.setMaximum(13000)
        self.spinBox_3.setSingleStep(100)
        self.spinBox_3.setObjectName("spinBox_3")
        self.textEdit_3 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_3.setGeometry(QtCore.QRect(20, 220, 211, 31))
        self.textEdit_3.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.textEdit_3.setFrameShadow(QtWidgets.QFrame.Raised)
        self.textEdit_3.setObjectName("textEdit_3")
        self.send_droit_3 = QtWidgets.QPushButton(self.centralwidget)
        self.send_droit_3.setGeometry(QtCore.QRect(20, 350, 201, 51))
        self.send_droit_3.setObjectName("send_droit_3")
        self.send_droit_4 = QtWidgets.QPushButton(self.centralwidget)
        self.send_droit_4.setGeometry(QtCore.QRect(280, 350, 201, 51))
        self.send_droit_4.setObjectName("send_droit_4")
        self.spinBox_4 = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox_4.setGeometry(QtCore.QRect(290, 260, 171, 81))
        self.spinBox_4.setMinimum(-13000)
        self.spinBox_4.setMaximum(13000)
        self.spinBox_4.setSingleStep(100)
        self.spinBox_4.setObjectName("spinBox_4")
        self.textEdit_4 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_4.setGeometry(QtCore.QRect(270, 220, 211, 31))
        self.textEdit_4.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.textEdit_4.setFrameShadow(QtWidgets.QFrame.Raised)
        self.textEdit_4.setObjectName("textEdit_4")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_3.setGeometry(QtCore.QRect(610, 740, 113, 25))
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.lineEdit_4 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_4.setGeometry(QtCore.QRect(610, 780, 113, 25))
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.kill_master = QtWidgets.QPushButton(self.centralwidget)
        self.kill_master.setGeometry(QtCore.QRect(580, 50, 161, 27))
        self.kill_master.setObjectName("kill_master")
        self.reset_encoder = QtWidgets.QPushButton(self.centralwidget)
        self.reset_encoder.setGeometry(QtCore.QRect(580, 160, 161, 27))
        self.reset_encoder.setObjectName("reset_encoder")
        self.state_encoder = QtWidgets.QPushButton(self.centralwidget)
        self.state_encoder.setGeometry(QtCore.QRect(580, 280, 161, 27))
        self.state_encoder.setObjectName("state_encoder")
        self.go_goldenium = QtWidgets.QPushButton(self.centralwidget)
        self.go_goldenium.setGeometry(QtCore.QRect(580, 330, 161, 27))
        self.go_goldenium.setObjectName("go_goldenium")
        self.spinBox_5 = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox_5.setGeometry(QtCore.QRect(30, 460, 171, 81))
        self.spinBox_5.setMinimum(-13000)
        self.spinBox_5.setMaximum(13000)
        self.spinBox_5.setSingleStep(100)
        self.spinBox_5.setObjectName("spinBox_5")
        self.send_droit_5 = QtWidgets.QPushButton(self.centralwidget)
        self.send_droit_5.setGeometry(QtCore.QRect(20, 550, 201, 51))
        self.send_droit_5.setObjectName("send_droit_5")
        self.textEdit_5 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_5.setGeometry(QtCore.QRect(20, 420, 211, 31))
        self.textEdit_5.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.textEdit_5.setFrameShadow(QtWidgets.QFrame.Raised)
        self.textEdit_5.setObjectName("textEdit_5")
        self.send_droit_6 = QtWidgets.QPushButton(self.centralwidget)
        self.send_droit_6.setGeometry(QtCore.QRect(280, 550, 201, 51))
        self.send_droit_6.setObjectName("send_droit_6")
        self.textEdit_6 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_6.setGeometry(QtCore.QRect(280, 420, 211, 31))
        self.textEdit_6.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.textEdit_6.setFrameShadow(QtWidgets.QFrame.Raised)
        self.textEdit_6.setObjectName("textEdit_6")
        self.spinBox_6 = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox_6.setGeometry(QtCore.QRect(290, 460, 171, 81))
        self.spinBox_6.setMinimum(-13000)
        self.spinBox_6.setMaximum(13000)
        self.spinBox_6.setSingleStep(100)
        self.spinBox_6.setObjectName("spinBox_6")
        self.lineEdit_5 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_5.setGeometry(QtCore.QRect(610, 810, 113, 25))
        self.lineEdit_5.setObjectName("lineEdit_5")
        self.lineEdit_6 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_6.setGeometry(QtCore.QRect(610, 840, 113, 25))
        self.lineEdit_6.setObjectName("lineEdit_6")
        self.show_topic = QtWidgets.QPushButton(self.centralwidget)
        self.show_topic.setGeometry(QtCore.QRect(580, 360, 161, 27))
        self.show_topic.setObjectName("show_topic")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(580, 420, 321, 171))
        self.label.setObjectName("label")
        DaVinciBot.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(DaVinciBot)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 774, 22))
        self.menubar.setObjectName("menubar")
        DaVinciBot.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(DaVinciBot)
        self.statusbar.setObjectName("statusbar")
        DaVinciBot.setStatusBar(self.statusbar)

        self.retranslateUi(DaVinciBot)
        self.spinBox.valueChanged['QString'].connect(self.lineEdit.setText)
        self.spinBox_2.valueChanged['QString'].connect(self.lineEdit_2.setText)
        self.spinBox_3.valueChanged['QString'].connect(self.lineEdit_3.setText)
        self.spinBox_4.valueChanged['QString'].connect(self.lineEdit_4.setText)
        self.spinBox_5.valueChanged['QString'].connect(self.lineEdit_5.setText)
        self.spinBox_6.valueChanged['QString'].connect(self.lineEdit_6.setText)
        QtCore.QMetaObject.connectSlotsByName(DaVinciBot)
        
    def retranslateUi(self, DaVinciBot):
        _translate = QtCore.QCoreApplication.translate
        DaVinciBot.setWindowTitle(_translate("DaVinciBot", "DaVincBot "))
        self.send_droit.setText(_translate("DaVinciBot", "Send"))
        self.textEdit.setHtml(_translate("DaVinciBot", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ff0000;\">Speed wheel right </span></p></body></html>"))
        self.send_droit_2.setText(_translate("DaVinciBot", "Send"))
        self.textEdit_2.setHtml(_translate("DaVinciBot", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#ff0000;\">Speed wheel left</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600; color:#ff0000;\"><br /></p></body></html>"))
        self.CreateMasterButton.setText(_translate("DaVinciBot", "Create Master"))
        self.rese_encoder_right.setText(_translate("DaVinciBot", "Reset Encoder Right"))
        self.reset_encoder_left.setText(_translate("DaVinciBot", "Reset Encoder Left"))
        self.state_encoder_left.setText(_translate("DaVinciBot", "State Encoder Left"))
        self.state_encoder_right.setText(_translate("DaVinciBot", "State Encoder Right"))
        self.textEdit_3.setHtml(_translate("DaVinciBot", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#ff0000;\"> Setpoint position right</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#ff0000;\"> </span></p></body></html>"))
        self.send_droit_3.setText(_translate("DaVinciBot", "Send"))
        self.send_droit_4.setText(_translate("DaVinciBot", "Send"))
        self.textEdit_4.setHtml(_translate("DaVinciBot", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#ff0000;\">Setpoint position left</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600; color:#ff0000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#ff0000;\"> </span></p></body></html>"))
        self.kill_master.setText(_translate("DaVinciBot", "Kill Master"))
        self.reset_encoder.setText(_translate("DaVinciBot", "Reset ALL Encoder"))
        self.state_encoder.setText(_translate("DaVinciBot", "State ALL Encoder"))
        self.go_goldenium.setText(_translate("DaVinciBot", "Go To Goldenium "))
        self.send_droit_5.setText(_translate("DaVinciBot", "Send"))
        self.textEdit_5.setHtml(_translate("DaVinciBot", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#ff0000;\">Setpoint position both wheel</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600; color:#ff0000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#ff0000;\"> </span></p></body></html>"))
        self.send_droit_6.setText(_translate("DaVinciBot", "Send"))
        self.textEdit_6.setHtml(_translate("DaVinciBot", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Ubuntu\'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#ff0000;\">Angular position servo motor</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600; color:#ff0000;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600; color:#ff0000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600; color:#ff0000;\"> </span></p></body></html>"))
        self.show_topic.setText(_translate("DaVinciBot", "Show topic active"))
        self.label.setText(_translate("DaVinciBot", "<html><head/><body><p><img src=\":/images/images/Webp.net-resizeimage.png\"/></p></body></html>"))

import resources_rc
