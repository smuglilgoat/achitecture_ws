 [![Institut Maupertuis logo](http://www.institutmaupertuis.fr/media/gabarit/logo.png)](http://www.institutmaupertuis.fr) Topics RViz plugin
===

[![build status](https://gitlab.com/InstitutMaupertuis/topics_rviz_plugin/badges/kinetic/build.svg)](https://gitlab.com/InstitutMaupertuis/topics_rviz_plugin/commits/kinetic)

This package contains a Qt RViz panel that allows users to display topics values dynamically.

Supported [built-in types](http://wiki.ros.org/msg#Fields) are:
- `bool`
- `duration`
- `float32`
- `float64`
- `int8`
- `int16`
- `int32`
- `int64`
- `string`
- `time`
- `uint8`
- `uint16`
- `uint32`
- `uint64`

:warning: Qt does not support displaying some types, these are casted:
- `int64` is casted to a `int32_t`
- `uint32` is casted to a `uint16_t`
- `uint64` is casted to a `uint16_t`

# Screenshots
![Pick topics](./documentation/pick_topics.png)

![Graphical user interface](./documentation/gui.png)

# Project logo

![Topics RViz plugin logo](./documentation/icon_blue.png)
