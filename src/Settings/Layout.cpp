/**
 * Settings layout tab
 */
#include <string>
#include <vector>
#include <iostream>

#include <QtCore>

//#include <Layouts/LayoutLoader.h>

#include "Events/OutputChangeEvent.h"
#include "Events/InputChangeEvent.h"
#include "Layout.h"

#include <Jack/Patchbay.h>
#include <Jack/PatchbayEffects.h>


using Orza::Widget::InputDropdown;
using Orza::Widget::OutputDropdown;
using Jack::Server;
using Orza::Layouts::PresetLoader;
using Orza::Layouts::LayoutWriter;

using std::string;
using std::vector;


namespace Orza { namespace Settings {


/**
 * Construct
 */

Layout::Layout( Server * win ) :
	Layout::Layout( win, new LayoutWriter, new PresetLoader( win ) )
{
}

Layout::Layout( Server * win,  LayoutWriter * writer, PresetLoader * loader ) :
	_Server( win ),
	_LayoutWriter( writer ),
	_PresetLoader( loader ),
	_PresetName( new Widget::BaseLineEdit ),
	_midiDevices( new MidiDeviceDropdown( win ) )
{

	_UI.setupUi(this);

	_UI.preset_save_layout->insertWidget( 0, _PresetName );

	setDropdowns();
	setEvents();
	setAppUI();

};


/**
 * Set dropdown widgets and events
 */

void Layout::setDropdowns() {

	_LeftOutput = new OutputDropdown( _Server );
	_RightOutput = new OutputDropdown( _Server );

	_LeftOutput->setCurrentIndex( 1 );
	_RightOutput->setCurrentIndex( 2 );

	_InputDropdown = new InputDropdown( _Server );



	//Settings

	QComboBox * dropdown = _UI.load_layout_dropdown;

	vector<string> fileNames = _PresetLoader->getFileNames();

	vector<string>::const_iterator it;

	for( it = fileNames.begin(); it < fileNames.end(); ++ it ) {

		dropdown->addItem( it->c_str() );

	}

};


void Layout::setEvents() {

	//Output changing

	_Event = (Util::Event*) new OutputChangeEvent( this );

	_LeftOutput->on( OutputDropdown::CHANGE_EVENT, _Event );
	_RightOutput->on( OutputDropdown::CHANGE_EVENT, _Event );

	Util::Event * inputEvent = new InputChangeEvent<Layout>( this );

	_InputDropdown->on( InputDropdown::CHANGE_EVENT, inputEvent );


	//Save click

	connect(
		_UI.save_layout_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( handleSaveClick() )
	);

	connect(
		_UI.load_layout_btn,
		SIGNAL( clicked() ),
		this,
		SLOT( handlePresetLoadClick() )
	);

};


/**
 * App UI setting
 */

void Layout::setAppUI() {

	_UI.horizontalLayout_5->addWidget( _LeftOutput );
	_UI.horizontalLayout_5->addWidget( _RightOutput );
	_UI.input_layout->addWidget( _InputDropdown );

	_UI.midi_layout->addWidget( _midiDevices );


	//Add layout options
	//@TODO

	//_App->getUI()->load_

};


/**
 * Save layout
 */

void Layout::saveLayout() {

	std::string layoutName = _PresetName->text().toStdString();

	_LayoutWriter->writeLayoutToFile(
		layoutName,
		_Server->getPatchbay()
	);

	_UI.load_layout_dropdown->addItem( layoutName.c_str() );

};


/**
 * load preset from dropdown
 */

void Layout::loadPreset() {

	std::string layoutName = _UI.load_layout_dropdown
		->currentText()
		.toStdString();

	_PresetLoader->loadFromName( layoutName.c_str() );

};


/**
 * Qt handler for save click
 */

void Layout::handleSaveClick() {

	saveLayout();

};

void Layout::handlePresetLoadClick() {

	loadPreset();

};


/**
 * Input change
 */

void Layout::handleInputChange( void * data ) {

	const int index = _InputDropdown->currentIndex();

	_Server->getPatchbay()
		->getEffects()->clearInputs();


	//Clear all if 0 or none

	if( index == 0 ) {

		return;

	}


	//Change input
	//@TODO
	Jack::PatchbayEffects * effects = (Jack::PatchbayEffects*) _Server->getPatchbay()->getEffects();

	effects->connectInputTo(
		_InputDropdown->getCurrentJackPort()
	);

	std::cout << "Connected to "
		<<_InputDropdown->getCurrentJackPort() << "\n";

};


/**
 * Update output ports to selected inputs
 */

void Layout::updateOutputPorts() {

	const int left = _LeftOutput->currentIndex() - 1;
	const int right = _RightOutput->currentIndex() - 1;

	vector<Jack::Port> ports = _Server->getAudio()
		->getInputPorts();

	_Server->getAudio()
		->disconnectOutputs();

	_Server->getAudio()
		->connectOutputTo(
			ports[ left ].name,
			ports[ right ].name
		);

};

} }
