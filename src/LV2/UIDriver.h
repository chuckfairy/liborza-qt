/**
 * Plugin UI
 *
 */
#pragma once

#include <lilv/lilv.h>
#include <suil/suil.h>
#include <sratom/sratom.h>

#include <jack/jack.h>
#include <jack/ringbuffer.h>

#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QScrollArea>

#include <Audio/UIDriver.h>

#include <Jack/Server.h>

#include <LV2/UI.h>
#include <LV2/Plugin.h>
#include <LV2/include/types.h>
#include <LV2/Port.h>

#include <ui_PluginArea.h>

#include "PresetDropdown.h"



namespace Orza { namespace LV2UI {


/**
 * Forwarding
 */

class PortContainer;

class PresetDropdown;


/**
 * UI use lv2 driver
 *
 */

class UIDriver : public Audio::UIDriver {

    public:

        explicit UIDriver( Jack::Server *, LV2::UI * );


        /**
         * Virtual loading
         */

        void start();

        void stop();

        void update();

        void updatePort( Audio::Port * p );

        void updatePort( PortContainer );

        void resize();


        /**
         * Unique Lilv setups
         */

        void createUI();

        QWidget * createControlWidget();

        bool portGroupLessThan( const PortContainer &, const PortContainer & );

        QWidget* getControlWidget() {

            return _pluginAreaWidget;

        };


    protected:

        LV2::UI * _UI;


    private:

        /**
         * Main obj
         */

        Jack::Server * _Server;


        /**
         * Widget object
         */

        QMainWindow * win;

        QScrollArea * _MainWidget;

        QWidget* _controlWidget;

        PresetDropdown * _PresetDropdown;

        QWidget * _pluginAreaWidget;


        /**
         *  Lilv types
         */

        LilvUIs * _lilvUIS;

        const LilvUI * _lilvUI;

        const LilvNode * _uiType;


        /**
         * Port containers
         */

        vector<PortContainer> portContainer;


        /**
         * Ui
         */

        Ui_PluginArea _UIArea;


        /**
         * Port input creation methods
         */

        void setupInputPorts();

        void setupOutputPorts();

        void setupMidiPorts();

};

} }
