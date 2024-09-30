#include <topics_rviz_plugin/display_topics.hpp>

namespace topics_rviz_plugin
{
DisplayTopics::DisplayTopics(QWidget* parent) :
        rviz::Panel(parent)
{
  qRegisterMetaType<QMessageBox::Icon>();
  setEnabled(false);
  setName("Topics RViz plugin");
  setObjectName(getName());

  connect(this, SIGNAL(displayMessageBox(const QString, const QString, const QString, const QMessageBox::Icon)), this,
          SLOT(displayMessageBoxHandler(const QString, const QString, const QString, const QMessageBox::Icon)));

  layout_ = new QVBoxLayout();
  QWidget *scroll_widget = new QWidget;
  scroll_widget->setLayout(layout_);
  QScrollArea *scroll_area = new QScrollArea;
  scroll_area->setWidget(scroll_widget);
  scroll_area->setWidgetResizable(true);
  scroll_area->setFrameShape(QFrame::NoFrame);
  QVBoxLayout* main_layout = new QVBoxLayout(this);
  main_layout->addWidget(scroll_area);

  QPushButton *configure = new QPushButton("Configure");
  configure->setIcon(QIcon::fromTheme("preferences-system"));
  connect(configure, SIGNAL(clicked()), this, SLOT(configure()));
  layout_->addWidget(configure);

  table_ = new QTableWidget;
  table_->insertColumn(0);
  table_->insertColumn(0);
  QStringList labels;
  labels.push_back("Topic");
  labels.push_back("Value");
  table_->setHorizontalHeaderLabels(labels);
  table_->setShowGrid(false);
  layout_->addWidget(table_);
  Q_EMIT setEnabled(true);

  connect(table_->horizontalHeader(), SIGNAL(sectionResized(int, int, int)), this, SIGNAL(configChanged()));
  connect(table_->verticalHeader(), SIGNAL(sectionResized(int, int, int)), this, SIGNAL(configChanged()));
}

DisplayTopics::~DisplayTopics()
{
  nh_.shutdown();
}

void DisplayTopics::load(const rviz::Config& config)
{
  rviz::Panel::load(config);

  unsigned i(0);
  while (1)
  {
    QString topic_name;
    QString topic_type;

    if (!config.mapGetString("topic_" + QString::number(i) + "_name", &topic_name))
      break;

    if (!config.mapGetString("topic_" + QString::number(i) + "_type", &topic_type))
      break;

    displayed_topics_.insert(std::pair<std::string, std::string>(topic_name.toStdString(), topic_type.toStdString()));
    ++i;
  }

  if (!displayed_topics_.empty())
    updateTopicsDisplayed();

  QString table_header_state_str;
  if (config.mapGetString("horizontal_table_header", &table_header_state_str))
  {
    table_->horizontalHeader()->restoreState(QByteArray::fromHex(qPrintable(table_header_state_str)));
  }

  if (config.mapGetString("vertical_table_header", &table_header_state_str))
  {
    table_->verticalHeader()->restoreState(QByteArray::fromHex(qPrintable(table_header_state_str)));
  }
}

void DisplayTopics::save(rviz::Config config) const
                         {
  rviz::Panel::save(config);
  unsigned i(0);
  for (auto topic : displayed_topics_)
  {
    config.mapSetValue("topic_" + QString::number(i) + "_name", QString::fromStdString(topic.first));
    config.mapSetValue("topic_" + QString::number(i) + "_type", QString::fromStdString(topic.second));
    ++i;
  }

  QByteArray table_header_state(table_->horizontalHeader()->saveState());
  // Must be saved as hex
  config.mapSetValue("horizontal_table_header", table_header_state.toHex());

  table_header_state = table_->verticalHeader()->saveState();
  // Must be saved as hex
  config.mapSetValue("vertical_table_header", table_header_state.toHex());
}

void DisplayTopics::configure()
{
  Q_EMIT setEnabled(false);

  ros::master::V_TopicInfo topics;
  if (!ros::master::getTopics(topics))
  {
    Q_EMIT displayMessageBox("Error getting topics", "Could not retrieve the topics names.", "",
                             QMessageBox::Icon::Critical);
    Q_EMIT setEnabled(true);
    return;
  }

  ros::master::V_TopicInfo supported_topics;
  for (auto topic : topics)
  {
    if (topic.datatype == "std_msgs/Bool" ||
        topic.datatype == "std_msgs/Int8" ||
        topic.datatype == "std_msgs/UInt8" ||
        topic.datatype == "std_msgs/Int16" ||
        topic.datatype == "std_msgs/UInt16" ||
        topic.datatype == "std_msgs/Int32" ||
        topic.datatype == "std_msgs/UInt32" ||
        topic.datatype == "std_msgs/Int64" ||
        topic.datatype == "std_msgs/UInt64" ||
        topic.datatype == "std_msgs/Float32" ||
        topic.datatype == "std_msgs/Float64" ||
        topic.datatype == "std_msgs/String" ||
        topic.datatype == "std_msgs/Time" ||
        topic.datatype == "std_msgs/Duration")
      supported_topics.push_back(topic);
  }

  if (supported_topics.empty())
  {
    Q_EMIT setEnabled(false);

    QDialog *no_topics_dialog = new QDialog(this);
    no_topics_dialog->setWindowTitle("No supported topic");
    QVBoxLayout *layout = new QVBoxLayout;
    no_topics_dialog->setLayout(layout);
    layout->addWidget(
        new QLabel("Error with topics, no supported topics found.\n"
                   "- Ok will clear the topics displayed\n- Cancel will not change the displayed topics"));

    QDialogButtonBox *button_box = new QDialogButtonBox(QDialogButtonBox::Ok
        | QDialogButtonBox::Cancel);
    no_topics_dialog->layout()->addWidget(button_box);

    connect(button_box, &QDialogButtonBox::accepted, no_topics_dialog, &QDialog::accept);
    connect(button_box, &QDialogButtonBox::rejected, no_topics_dialog, &QDialog::reject);

    if (!no_topics_dialog->exec())
    {
      Q_EMIT setEnabled(true);
      return;
    }

    displayed_topics_.clear();
    Q_EMIT configChanged();
    updateTopicsDisplayed();
    Q_EMIT setEnabled(true);
    return;
  }

  QDialog *pick_topics_dialog = new QDialog(this);
  pick_topics_dialog->setWindowTitle("Pick displayed topics");
  QVBoxLayout *layout = new QVBoxLayout;
  pick_topics_dialog->setLayout(layout);
  layout->addWidget(new QLabel("Only supported built-in types are displayed"));

  std::vector<QCheckBox *> topic_buttons;
  for (auto topic : supported_topics)
  {
    QCheckBox *radio_button = new QCheckBox;

    if (displayed_topics_.find(topic.name) != displayed_topics_.end())
      radio_button->setChecked(true);

    topic_buttons.push_back(radio_button);
    radio_button->setText(QString::fromStdString(topic.name));
    radio_button->setToolTip(QString::fromStdString(topic.datatype));
    pick_topics_dialog->layout()->addWidget(radio_button);
  }

  QDialogButtonBox *button_box = new QDialogButtonBox(QDialogButtonBox::Ok
      | QDialogButtonBox::Cancel);
  pick_topics_dialog->layout()->addWidget(button_box);

  connect(button_box, &QDialogButtonBox::accepted, pick_topics_dialog, &QDialog::accept);
  connect(button_box, &QDialogButtonBox::rejected, pick_topics_dialog, &QDialog::reject);

  if (!pick_topics_dialog->exec())
  {
    Q_EMIT setEnabled(true);
    return;
  }

  Q_EMIT configChanged();

  displayed_topics_.clear();
  for (auto button : topic_buttons)
  {
    if (!button->isChecked())
      continue;

    displayed_topics_.insert(std::pair<std::string, std::string>(button->text().toStdString(),
                                                                 button->toolTip().toStdString()));
  }

  updateTopicsDisplayed();
  Q_EMIT setEnabled(true);
}

void DisplayTopics::updateTopicsDisplayed()
{
  table_->setRowCount(0);
  table_->setRowCount(displayed_topics_.size());

  topic_infos_.clear();
  for (auto topic : displayed_topics_)
  {
    std::shared_ptr<TopicInfo> topic_info(new TopicInfo(topic.first, topic.second));
    topic_infos_.push_back(topic_info);
  }

  unsigned i(0);
  for (auto topic_info : topic_infos_)
  {
    table_->setCellWidget(i, 0, topic_info->label_.get());
    table_->setCellWidget(i, 1, topic_info->display_.get());
    ++i;
  }
}

void DisplayTopics::displayMessageBoxHandler(const QString title,
                                             const QString message,
                                             const QString info_msg,
                                             const QMessageBox::Icon icon)
{
  const bool old(isEnabled());
  Q_EMIT setEnabled(false);
  QMessageBox msg_box;
  msg_box.setWindowTitle(title);
  msg_box.setText(message);
  msg_box.setInformativeText(info_msg);
  msg_box.setIcon(icon);
  msg_box.setStandardButtons(QMessageBox::Ok);
  msg_box.exec();
  Q_EMIT setEnabled(old);
}

}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(topics_rviz_plugin::DisplayTopics, rviz::Panel)
