#ifndef TOPICS_RVIZ_PLUGIN_DISPLAY_TOPICS_HPP
#define TOPICS_RVIZ_PLUGIN_DISPLAY_TOPICS_HPP

#ifndef Q_MOC_RUN
#include <memory>
#include <ros/package.h>
#include <ros/ros.h>
#include <rviz/panel.h>
#include <topics_rviz_plugin/topic_info.hpp>
#endif

#include <QApplication>
#include <QCheckBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QLCDNumber>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QtGlobal>

namespace topics_rviz_plugin
{

class DisplayTopics : public rviz::Panel
{
Q_OBJECT

public:
  DisplayTopics(QWidget* parent = NULL);
  virtual ~DisplayTopics();

Q_SIGNALS:
  void displayMessageBox(const QString,
                         const QString,
                         const QString,
                         const QMessageBox::Icon);

protected Q_SLOTS:
  virtual void load(const rviz::Config& config);
  virtual void save(rviz::Config config) const;

  void configure();
  void updateTopicsDisplayed();

  void displayMessageBoxHandler(const QString title,
                                const QString message,
                                const QString info_msg = "",
                                const QMessageBox::Icon icon = QMessageBox::Icon::Information);

protected:
  ros::NodeHandle nh_;

  QVBoxLayout *layout_;
  QTableWidget *table_;
  std::map<std::string, std::string> displayed_topics_;
  std::vector<std::shared_ptr<TopicInfo>> topic_infos_;
};

}

#endif
