/**
 * Control widget editor
 */
#include <Jack/Midi.h>

#include "ControlPort.h"

#include "Control.h"


using Jack::MidiControlPort;
using Jack::Server;


namespace Orza { namespace MidiControl {


/**
 * Main class
 */

Control::Control( Server * app ) :
	_Server( app ),
	_WidgetContent( new QWidget() )
{

	_UI.setupUi( _WidgetContent );


	//Events

	connect( _UI.add_btn, SIGNAL( clicked() ), this, SLOT( addControlPort() ) );

	updateDropdown();

};


/**
 * Add port
 */

void Control::addControlPort() {

	Jack::MidiControlPort * port = _Ports[ _UI.control_dropdown->currentIndex() ];

	ControlPort * uiPort = new ControlPort( _Server, port );

	_UI.scroll_layout->addWidget( uiPort );


	//set events

	addNode( uiPort );

};


/**
 * update midi port controls
 */

void Control::updateDropdown() {

	_Ports = _Server->getMidi()
		->getMidiControlPorts();

	vector<MidiControlPort*>::iterator it;

	for( it = _Ports.begin(); it != _Ports.end(); ++ it ) {

		_UI.control_dropdown->addItem( (*it)->getName() );

	}

};

} }
