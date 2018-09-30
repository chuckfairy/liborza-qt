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


using Jack::Server;
using nlohmann::json;


namespace Orza { namespace App { namespace Layouts {

class LayoutLoader : public Audio::PatchbayPresetLoader {

    public:

        LayoutLoader( Server * );
        ~LayoutLoader() {};


        /**
         * Virtuals
         */

        void load( json * );

        void loadLayout( const char * type );

        void loadLayout( Layout * );


        /**
         * Getters
         */

        Layout * getCurrent() {

            return _CurrentLayout;

        };


    private:

        Server * _Server;

        Layout * _CurrentLayout;

        LayoutRepository _Repo;

};

}; }; };
