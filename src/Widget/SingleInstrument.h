/**
 * Single instrument widget
 */
#pragma once

#include <vector>

#include <QtCore>
#include <QWidget>

#include <Jack/Server.h>

#include <ui_SingleInstrument.h>

#include "InstrumentDropdown.h"


using std::vector;

using Jack::Server;


namespace Orza { namespace Widget {


/**
 * Main class
 */

class SingleInstrument : public QWidget {

    Q_OBJECT;

    public:

        SingleInstrument( Server * );


        /**
         * Add action
         */

        void clearPlugin();

        void setPlugin( Audio::Plugin * );

        void handleChange( void * );


        /**
         * Getters
         */

        QWidget * getWidgetContainer() {

            return _WidgetContent;

        };


    private:

        Server * _Server;

        QWidget * _WidgetContent;

        InstrumentDropdown * _Dropdown;

        Ui_SingleInstrument _UI;

        QWidget * _LayoutWidget;

        bool HAS_PLUGIN;


        /**
         * Private methods
         */

        void setEvents();

};

} }
