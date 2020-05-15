/**
 * Simple layout start
 */
#include <string.h>

#include <json/json.hpp>
#include <PluginSearch/LoadedPlugins.h>

#include "PresetLoader.h"
#include <Jack/Server.h>

#include <Audio/UI.h>


using nlohmann::json;
//using Audio::Server;

//using Orza::Widget::Patchbay;

using Orza::PluginSearch::LoadedPlugins;


namespace Orza { namespace Layouts {

/**
 * Construct
 */

PresetLoader::PresetLoader( ::Audio::Server * app ) :
	_AudioPatchbay( app->getPatchbay() ),
	_Patchbay( new Orza::Widget::Patchbay( (::Jack::Server*) app ) ),
	_SingleInstrument( new Orza::Widget::SingleInstrument( app ) )
{
};

PresetLoader::PresetLoader( ::Audio::Server * app, Orza::Widget::Patchbay * patchbay ) :
	_AudioPatchbay( app->getPatchbay() ),
	_Patchbay( patchbay )
{
};


/**
 * Main virtuals
 */

void PresetLoader::setup() {

};


void PresetLoader::takedown() {

};

void PresetLoader::setPatchbay(Orza::Widget::Patchbay * patch) {

	_Patchbay = patch;

};

void PresetLoader::setSingleInstrument(Orza::Widget::SingleInstrument * inst) {

	_SingleInstrument = inst;

};


/**
 * Main layout load
 */

void PresetLoader::load( json j ) {

	Audio::Patchbay * host = _AudioPatchbay;

	host->setActive( false );

	LoadedPlugins * search = LoadedPlugins::getInstance();


	if( ! j["instruments"].empty() ) {

		json instrument = j["instruments" ][ 0 ];

		std::string id = instrument["id"];

		Audio::Plugin * p = search->getById( id.c_str() );
		Audio::Plugin * clone = (Audio::Plugin*) p->clone();

		_SingleInstrument->setPlugin( clone );

		setPortsFromJSON( clone, instrument );

		clone->getUI()->updateDrivers();

	}



	// Plugin effects

	_Patchbay->clearPlugins();

	if( ! j["effects"].empty() ) {

		for( json::iterator it = j["effects"].begin(); it != j["effects"].end(); ++it ) {

			json effect = *it;

			std::string id = effect["id"];

			Audio::Plugin * plug = search->getById( id.c_str() );

			Audio::Plugin * p = plug->clone();

			_Patchbay->addPlugin( p );

			setPortsFromJSON( p, effect );

			p->getUI()->updateDrivers();

		}

	}

	host->setActive( true );

};

}; };
