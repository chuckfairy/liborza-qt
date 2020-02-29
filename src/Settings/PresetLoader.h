/**
 * Simple layout start
 */
#pragma once

#include <Layouts/Layout.h>

#include <json/json.hpp>

#include <Audio/PatchbayPresetLoader.h>

#include <Util/Dispatcher.h>

#include <Widget/Patchbay.h>

using nlohmann::json;

using Jack::Server;

using Orza::Widget::Patchbay;



namespace Orza { namespace Server { namespace Layouts {


class PresetLoader : public Audio::PatchbayPresetLoader {

	public:

		PresetLoader( Jack::Server * );


		/**
		 * Virtuals
		 */

		void load( json settings );

		void setup();
		void takedown();


	protected:

		Jack::Server * _Server;

		Patchbay * _Patchbay;

};

}; }; };
