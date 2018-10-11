/**
 * Pi layout
 */
#pragma once

#include <QtCore>
#include <QWidget>

#include <Util/Dispatcher.h>

#include <Audio/Port.h>
#include <Audio/PluginPortContainer.h>

#include <Midi/Control.h>
#include <Jack/Midi.h>
#include <Jack/Server.h>

#include <Widget/TreeNode.h>

#include <ui_ControlPort.h>

#include "ControlPortValue.h"


using Jack::Server;


namespace Orza { namespace MidiControl {


/**
 * Main class
 */

class ControlPort : public Widget::TreeNode {

	Q_OBJECT;

	public:

		ControlPort( Server *, Jack::MidiControlPort * );
		~ControlPort();


		/**
		 * Event
		 */

		static const char * REMOVE_EVENT;


	public slots:

		void addControlPortValue();


	private:

		/**
		 * Internal
		 */

		Server * _Server;

		Ui_ControlPort _UI;

		QWidget * _WidgetContent;

		Jack::MidiControlPort * _ControlPort;

		/**
		 * Port value and dropdown
		 * @TODO remove double vector
		 */

		vector<Audio::PluginPortContainer*> _PortContainers;

		vector<ControlPortValue*> _UIPortValues;

		void updateDropdown();

};

} }
