/**
 * ControlPort widget editor
 */
#include <QMessageBox>
#include <QListView>

#include <Audio/Port.h>

#include <Jack/Patchbay.h>

#include <Resource/Icons.h>

#include <Widget/Events/RemoveClickEvent.h>

#include "ControlPort.h"


using Orza::Resource::Icons;
using Orza::Widget::RemoveClickEvent;


namespace Orza { namespace MidiControl {


/**
 * Main class
 */

ControlPort::ControlPort( Server * app, Jack::MidiControlPort * p ) :
	_Server( app ),
	_ControlPort( p )
{

	_UI.setupUi( this );

	_UI.label->setText( _ControlPort->getName() );


	//Button setup

	setViewButton( _UI.view_btn, _UI.scrollArea );

	setDeleteButton( _UI.delete_btn );

	_UI.port_add_dropdown->setView(new QListView());


	//Events

	connect( _UI.port_add_btn, SIGNAL( clicked() ), this, SLOT( addControlPortValue() ) );


	updateDropdown();

};


/**
 * deletion
 */

ControlPort::~ControlPort() {

};


/**
 * Remove event char
 */

const char * ControlPort::REMOVE_EVENT = "REMOVE";


/**
 * Add port
 */

void ControlPort::addControlPortValue() {

	//No plugins loaded

	if( _UI.port_add_dropdown->currentIndex() == -1 ) {

		QMessageBox Msgbox;
		Msgbox.setText( "No plugins loaded" );
		Msgbox.exec();

		return;

	}


	//load new control value

	Audio::PluginPortContainer * port = _PortContainers[
		_UI.port_add_dropdown->currentIndex()
	];

	ControlPortValue * portValue = new ControlPortValue(
		_Server->getMidi(),
		_ControlPort,
		port
	);

	_UI.scroll_layout->addWidget( portValue );

	_UIPortValues.push_back( portValue );

	addNode( portValue );

};


/**
 * update midi port controls
 */

void ControlPort::updateDropdown() {

	_PortContainers = _Server->getPatchbay()
		->getPluginPortContainers();

	vector<Audio::PluginPortContainer*>::iterator it;

	for( it = _PortContainers.begin(); it != _PortContainers.end(); ++ it ) {

		Audio::PluginPortContainer * container = (*it);

		_UI.port_add_dropdown->addItem( container->getName() );

	}

};

} }
