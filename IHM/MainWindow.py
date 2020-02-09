#!/usr/bin/python3
# -*- coding: utf-8 -*-

import PyQt5
from PyQt5 import QtWidgets
import gui  # import du fichier gui.py généré par pyuic5
import subprocess
from subprocess import call
from subprocess import Popen

class MyWindow(QtWidgets.QMainWindow):


    def __init__(self, parent=None):
        self.lastvalue = 0
        self.lastvalue2 = 0
        self.lastvalue3 = 0
        self.lastvalue4 = 0
        self.lastvalue5 = 0
        self.lastvalue6 = 0
        QtWidgets.QMainWindow.__init__(self, parent)
        self.ui = gui.Ui_DaVinciBot()
        self.ui.setupUi(self)
        self.ui.send_droit.clicked.connect(self.action_bouton2)
        self.ui.CreateMasterButton.clicked.connect(self.action_masterButton)
        self.ui.send_droit_2.clicked.connect(self.action_leftWheel)
        self.ui.send_droit_3.clicked.connect(self.action_rightWheelEncoder)
        self.ui.send_droit_4.clicked.connect(self.action_leftWheelEncoder)
        self.ui.send_droit_5.clicked.connect(self.forward)
        self.ui.send_droit_6.clicked.connect(self.action_bras)
        self.ui.rese_encoder_right.clicked.connect(self.action_reset_encoder_right)
        self.ui.reset_encoder_left.clicked.connect(self.action_reset_encoder_left)
        self.ui.state_encoder_left.clicked.connect(self.action_show_state_left)
        self.ui.state_encoder_right.clicked.connect(self.action_show_state_right)
        self.ui.state_encoder.clicked.connect(self.action_show_state_right)
        self.ui.state_encoder.clicked.connect(self.action_show_state_left)
        self.ui.reset_encoder.clicked.connect(self.action_reset_encoder_left)
        self.ui.reset_encoder.clicked.connect(self.action_reset_encoder_right)
        self.ui.show_topic.clicked.connect(self.showTopic)
        self.ui.go_goldenium.clicked.connect(self.go_goldenium)
        self.ui.kill_master.clicked.connect(self.kill_master)

        ##self.ui.lineEdit.textChanged(self.valuechange)
        self.ui.spinBox.valueChanged['QString'].connect(self.valuechange)
        self.ui.spinBox_2.valueChanged['QString'].connect(self.valuechange2)
        self.ui.spinBox_3.valueChanged['QString'].connect(self.valuechange3)
        self.ui.spinBox_4.valueChanged['QString'].connect(self.valuechange4)
        self.ui.spinBox_5.valueChanged['QString'].connect(self.valuechange5)
        self.ui.spinBox_6.valueChanged['QString'].connect(self.valuechange6)
        
    def valuechange(self):
        self.lastvalue = self.ui.lineEdit.text()

    def valuechange2(self):
        self.lastvalue2 = self.ui.lineEdit_2.text()

    def valuechange3(self):
        self.lastvalue3 = self.ui.lineEdit_3.text()

    def valuechange4(self):
        self.lastvalue4 = self.ui.lineEdit_4.text()

    def valuechange5(self):
        self.lastvalue5 = self.ui.lineEdit_5.text()
    
    def valuechange6(self):
        self.lastvalue6 = self.ui.lineEdit_6.text()
    

    def action_bouton2(self):
        cmd = "xterm -e bash_file/stopRight.sh "+ self.lastvalue
        print (cmd) 
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        out = p.communicate()[0]
        print(out)

    def action_leftWheel(self):
        cmd = "xterm -e bash_file/stopLeft.sh "+ self.lastvalue2
        print (cmd) 
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        out = p.communicate()[0]
        print(out)
    
    def action_rightWheelEncoder(self):
        cmd = "xterm -e bash_file/action_wheel_encoder_right.sh "+ self.lastvalue3
        print (cmd) 
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
     
    def forward(self):
        cmd = "xterm -e bash_file/forward.sh "+ self.lastvalue5
        print (cmd) 
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)


    def action_leftWheelEncoder(self):
        cmd2 = "xterm -e bash_file/action_wheel_encoder_left.sh " + self.lastvalue4
        e = subprocess.Popen(cmd2, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    

    def action_masterButton(self):
        d = subprocess.Popen("xterm -e bash_file/create_master.sh", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
       
    def action_reset_encoder_right(self):
         subprocess.Popen("xterm -e bash_file/reset_wheel_encoder_right.sh", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

    def action_reset_encoder_left(self):
        f = subprocess.Popen("xterm -e bash_file/reset_wheel_encoder_left.sh", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

    def action_show_state_left(self) : 
        h = subprocess.Popen("xterm -e bash_file/action_show_state_left.sh", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

    def action_show_state_right(self) : 
         subprocess.Popen("xterm -e bash_file/action_show_state_right.sh", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
   
    def go_goldenium(self) : 
         subprocess.Popen("xterm -e bash_file/action_go_goldenium.sh", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
   
    def kill_master(self) : 
         subprocess.Popen("xterm -e bash_file/action_kill_master.sh", shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    
    def action_bras(self):
        cmd = "xterm -e bash_file/action_bras.sh "+ self.lastvalue6
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)

    def showTopic(self):
        cmd = "xterm -e bash_file/action_show_topic.sh "
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
       
if __name__ == '__main__':
    import sys
    app = QtWidgets.QApplication(sys.argv)
    window = MyWindow()
    window.show()
    sys.exit(app.exec_())