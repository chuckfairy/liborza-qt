/**
 * Single instrument widget
 */
#include <QListView>

#include <LV2/UIDriver.h>

#include <Jack/Server.h>

#include <PluginSearch/LoadedPlugins.h>

#include "SingleInstrument.h"

#include "SimpleChangeEvent.h"


using std::vector;

using Orza::PluginSearch::LoadedPlugins;
using Orza::LV2UI::UIDriver;
using Audio::Server;


namespace Orza { namespace Widget {


/**
 * Main class
 */

SingleInstrument::SingleInstrument( Server * app ) :
	_Server( app ),
	_Dropdown( new InstrumentDropdown( LoadedPlugins::getInstance() ) ),
	_WidgetContent( new QWidget() )
{

	_UI.setupUi( _WidgetContent );

	_Dropdown->setView(new QListView());

	_UI.item_area->addWidget( _Dropdown );

	setEvents();

};


/**
 * Event setter internal
 */

void SingleInstrument::setEvents() {

	Util::Event * e = new SimpleChangeEvent<SingleInstrument>( this );

	_Dropdown->on(
		InstrumentDropdown::CHANGE_EVENT,
		e
	);

};


/**
 * Clear plugin
 */

void SingleInstrument::clearPlugin() {

};


/**
 * Set plugin and driver
 */

void SingleInstrument::setPlugin( Audio::Plugin * p ) {

	//@TODO jack removal
	UIDriver * driver = new UIDriver( (Jack::Server*) _Server, (LV2::UI*) p->getUI() );

	p->getUI()->addDriver( driver );

	_Server->getPatchbay()->clearPlugins();

	_Server->getPatchbay()->addPlugin( p );

	HAS_PLUGIN = true;

	_UI.singleinstrument_scroll_area
		->setWidget(
			driver->getControlWidget()
		);

};


/**
 * Main dropdown change event
 */

void SingleInstrument::handleChange( void * data ) {

	setPlugin( ( (Audio::Plugin*) data )->clone());

};

} }
