/*
 * File:   main.cpp
 * Author: javi
 *
 * Created on 13 de agosto de 2014, 13:37
 */

#include <QApplication>

#include "JVBotClient.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    ros::init(argc, argv, "JVBotClient");
    

    JVBotClient* pJVBotClient = new JVBotClient();
    pJVBotClient->start();
    
    // create and show your widgets here

    return app.exec();
}
