/*
 * File:   main.cpp
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 11:32
 */

#include <QApplication>
#include <QDebug>
#include "JVBotServerUI.h"

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "JVBotServer.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    
    ros::init(argc, argv, "JVBotServer");
        
    JVBotServerUI botServerUI;
    botServerUI.show();

    JVBotServer::getInstance()->start();
    // create and show your widgets here

    
    
    return app.exec();
}
