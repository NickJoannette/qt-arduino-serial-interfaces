#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QtCharts>
#include <QtCharts/QAbstractAxis>
#include "serialcommunicator.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    bool formed(std::string const & s)
   {
       QString k;

       if (s.find_first_of(".\r@a") != std::string::npos) return false;
       else return true;
   }

private slots:

    void OPEN_COM4_CLICKED();
    void CLOSE_COM4_CLICKED();
    void CLEAR_CHART_CLICKED();
    void RESET_DATA_CLICKED();
    void receive_chart_data(unsigned int, unsigned int);


private:

    QVBoxLayout * com_button_layout;
    QVBoxLayout * top_box_layout;
    QHBoxLayout* comms_panel_layout;

    QTextBrowser res;
    bool LED1_IS_ON = false;

    // MENU
    QMenu* file_menu;
    QMenu* port_menu;
    QAction *save_plot_action, *export_data_action;
    QAction *choose_port_action;
    QMenu* m_pSubMenu;

    // UI SECTION LABELS
    // coms
    QLabel com_control_section_label;

    // charts
    QLabel charts_control_section_label;



    // DATA CHARTING
    QChartView *chartView;
    QtCharts::QChart *chart;
    QtCharts::QSplineSeries* series;
    QtCharts::QAreaSeries* evaluation_points;

    // SERIAL INTERACTION

    // Layout Partition Labels

    QLabel transmission_label;
    QLabel reception_label;


    // Buttons and variables
    QPushButton OPEN_COM4;
    QPushButton FLICKER_LED;
    QPushButton READ_BUTTON;
    QPushButton RESET_DATA_BUTTON;
    unsigned int total_bytes_read = 0;

    // Serial communicator
    SerialCommunicator * s_com;

    // Serial comms log text view
    QLabel comms_log;

    // Serial Data Management
    unsigned int data_value_sum = 0;
    float average_data_value = 0;


};



#endif // MAINWINDOW_H
