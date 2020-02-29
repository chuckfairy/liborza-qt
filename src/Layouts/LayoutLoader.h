/**
 * Qt layout loader
 */
#pragma once

#include <Util/Repository.h>

#include <stdexcept>

#include <json/json.hpp>

#include "LayoutRepository.h"

#include "Layout.h"

#include <Audio/PatchbayPresetLoader.h>

#include <Jack/Server.h>

using nlohmann::json;

using Jack::Server;

using Audio::PatchbayPresetLoader;

namespace Orza { namespace Layouts {

class LayoutLoader : public Audio::PatchbayPresetLoader {

    public:

        LayoutLoader( Server * );
        ~LayoutLoader() {};


        /**
         * Virtuals
         */

        void load( json * );


    private:

        Server * _Server;

};

}; };
