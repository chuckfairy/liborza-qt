/**
 * Simple layout start
 */
#pragma once

#include <json/json.hpp>

#include <Audio/Server.h>
#include <Audio/Patchbay.h>
#include <Audio/PatchbayPresetLoader.h>

#include <Util/Dispatcher.h>

#include <Widget/Patchbay.h>

using nlohmann::json;

//using Orza::Widget::Patchbay;
using Audio::PatchbayPresetLoader;
//using Audio::Server;



namespace Orza { namespace Layouts {


class PresetLoader : public PatchbayPresetLoader {

	public:

		PresetLoader( ::Audio::Server * );


		/**
		 * Virtuals
		 */

		virtual void load( json settings );

		void setup();
		void takedown();


	protected:

		::Audio::Patchbay * _AudioPatchbay;

		Orza::Widget::Patchbay * _Patchbay;

};

}; };