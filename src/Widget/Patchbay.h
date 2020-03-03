/**
 * Test
 */
#pragma once

#include <vector>

#include <QtCore>
#include <QWidget>

#include <Jack/Server.h>

#include <ui_PatchBay.h>
#include <Audio/Plugin.h>

#include "EffectDropdown.h"


using std::vector;

using Jack::Server;
using Audio::Plugin;


namespace Orza { namespace Widget {

class PatchbayPlugin;


/**
 * Main class
 */

class Patchbay : public QWidget {

    Q_OBJECT;

    public:

        Patchbay( Server * );


        /**
         * Add action
         */

        void addPlugin();

        void movePlugin();

        void removePlugin( PatchbayPlugin * );

        void clearPlugins();

        void addPlugin( Plugin * );


        /**
         * Getters
         */

        QWidget * getWidgetContainer() {

            return _WidgetContent;

        };


    public slots:

        void handleAddClick();

        void handleRemoveClick( PatchbayPlugin * );

        void handleActivateClick( PatchbayPlugin * );


    private:

        Server * _Server;
		::Audio::Patchbay * _Patchbay;

        QWidget * _WidgetContent;

        EffectDropdown * _Dropdown;

        Ui_PatchBay _UI;

        QLayout * _Layout;

        QWidget * _LayoutWidget;

        vector<PatchbayPlugin*> _plugins;

        QSpacerItem * _Spacer = nullptr;

};

} }
