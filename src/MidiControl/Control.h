/**
 * Pi layout
 */
#pragma once

#include <vector>

#include <QtCore>
#include <QWidget>

#include <Util/Repository.h>

#include <Jack/Midi.h>
#include <Jack/Server.h>

#include <ui_Control.h>

#include <Widget/TreeNode.h>

#include "ControlPort.h"


using std::vector;

using Jack::Server;


namespace Orza { namespace MidiControl {


/**
 * Main class
 */

class Control : public Widget::TreeNode {

	Q_OBJECT;

	public:

		Control( Server * );

		/**
		 * Main getter
		 */

		QWidget * getWidget() {

			return _WidgetContent;

		};


	public slots:

		void addControlPort();


	private:

		/**
		 * Fullscreen flag
		 */

		Server * _Server;

		Ui_Control _UI;

		QWidget * _WidgetContent;


		/**
		 * Dropdown and midi control ports
		 */

		vector<Jack::MidiControlPort*> _Ports;

		void updateDropdown();

};

} }
