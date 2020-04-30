/**
 * Single instrument widget
 */
#pragma once

#include <vector>

#include <QtCore>
#include <QWidget>

#include <ui_SingleInstrument.h>

#include <Audio/Server.h>

#include "InstrumentDropdown.h"


using std::vector;


namespace Orza { namespace Widget {

using Audio::Server;

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

        bool HAS_PLUGIN;


        /**
         * Private methods
         */

        void setEvents();

};

}; };
