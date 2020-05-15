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
#include <Widget/SingleInstrument.h>

using nlohmann::json;

//using Orza::Widget::Patchbay;
using Audio::PatchbayPresetLoader;
//using Audio::Server;



namespace Orza { namespace Layouts {


class PresetLoader : public PatchbayPresetLoader {

	public:

		PresetLoader( ::Audio::Server * );
		PresetLoader( ::Audio::Server *, Orza::Widget::Patchbay * );


		/**
		 * Virtuals
		 */

		virtual void load( json settings );

		void setup();
		void takedown();


		/**
		 * Setters
		 * @TODO maybe remove
		 */
		void setPatchbay(Orza::Widget::Patchbay *);
		void setSingleInstrument(Orza::Widget::SingleInstrument *);


	protected:

		::Audio::Patchbay * _AudioPatchbay;

		Orza::Widget::Patchbay * _Patchbay;
		Orza::Widget::SingleInstrument * _SingleInstrument;

};

}; };
