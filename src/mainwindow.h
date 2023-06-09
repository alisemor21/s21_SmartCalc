#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "PN/graph.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

 private slots:
  void draw_Graph(double *mass, int flag_x);
  void on_Button1_clicked();
  void on_Button2_clicked();
  void on_Button3_clicked();
  void on_Button4_clicked();
  void on_Button5_clicked();
  void on_Button6_clicked();
  void on_Button7_clicked();
  void on_Button8_clicked();
  void on_Button9_clicked();
  void on_Button0_clicked();
  void on_Button_left_scob_clicked();
  void on_Button_right_scob_clicked();
  void on_Button_mult_clicked();
  void on_Button_div_clicked();
  void on_Button_sum_clicked();
  void on_Button_sub_clicked();
  void on_ButtonAC_clicked();
  int if_can_write_operator();
  int if_last_is_digit();
  void on_Button_dot_clicked();
  void on_Button_equal_clicked();
  void on_Button_sin_clicked();
  void on_Button_cos_clicked();
  void on_Button_tan_clicked();
  void on_Button_mod_clicked();
  void on_Button_sqrt_clicked();
  void on_Button_log_clicked();
  void on_Button_ln_clicked();
  void on_Button_acos_clicked();
  void on_Button_asin_clicked();
  void on_Button_atan_clicked();
  void on_Button_del_clicked();
  void on_Button_x_clicked();
  void on_Display_ymax_editingFinished();
  void on_Display_ymin_editingFinished();
  void on_Display_xmin_editingFinished();
  void on_Display_xmax_editingFinished();
  void on_Button_pow_clicked();
};

#endif  // MAINWINDOW_H
