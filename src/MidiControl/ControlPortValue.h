/**
 * Pi layout
 */
#pragma once

#include <QtCore>
#include <QWidget>

#include <Audio/Port.h>
#include <Audio/PluginPortContainer.h>
#include <Audio/MidiControlRange.h>

#include <Midi/Control.h>
#include <Jack/Midi.h>

#include <Midi/Events.h>
#include <Midi/Events/EventMessage.h>

#include <Widget/TreeNode.h>

#include <ui_ControlPortValue.h>

#include <Jack/Midi.h>


using Audio::MidiControlRange;
using Audio::PluginPortContainer;


namespace Orza { namespace MidiControl {


/**
 * Main class
 */

class ControlPortValue : public Widget::TreeNode {

	Q_OBJECT;

	public:

		explicit ControlPortValue( Jack::Midi *, Jack::MidiControlPort *, PluginPortContainer * );

		void setRange( float start, float end );

		static unsigned int PERCISION;

		void onMidiMessage( Orza::Midi::Event * );


	public slots:

		void handleUpdateRange();


	private:

		/**
		 * UI
		 */

		Ui_ControlPortValue _UI;


		/**
		 * Event
		 */

		Midi::EventMessage<ControlPortValue> * _Event;


		/**
		 * Server ports
		 */

		Jack::Midi * _Midi;

		Jack::MidiControlPort * _ControlPort;

		PluginPortContainer * _PortContainer;

		MidiControlRange<Jack::MidiControlPort> * _ControlRange;

		void updateRange();

		void setValue();

		void setEvents();

};

} }
