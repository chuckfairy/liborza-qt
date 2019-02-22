QT += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = liborza
TEMPLATE = app

FORMS    += src/MidiControl/ControlPortValue.ui\
	src/MidiControl/ControlPort.ui\
	src/MidiControl/Control.ui\
	src/Widget/SingleInstrument.ui\
        src/Widget/PatchBay.ui\
        src/Widget/PatchBayItem.ui\
	src/LV2/PluginArea.ui\
        src/Settings/SettingsLayout.ui\
