/**
 * Layout writer qt ext
 */
#pragma once

#include <vector>

#include <json/json.hpp>

#include <Audio/PatchbayPresetWriter.h>
#include <Util/File.h>
#include <Jack/Patchbay.h>
#include <Jack/PatchbayEffects.h>
#include <Jack/PluginRepository.h>
#include <Jack/Plugin.h>


using std::string;
using std::vector;
using nlohmann::json;
using Audio::PatchbayPresetWriter;
using Audio::Plugin;


namespace Orza { namespace Layouts {

class LayoutWriter : public PatchbayPresetWriter {

    public:

         LayoutWriter() {};
         ~LayoutWriter() {};

         /**
          * @TODO
          */

        void writeLayoutToFile( string fileName, Jack::Patchbay * p ) {

            json output;

            output["layout"] = "simple";

            output["name"] = fileName;


            //Instruments json array

            output["instruments"] = getJSON( p->getActivePlugins() );


            //Effects list json array
            //@TODO better typing

            vector<::Jack::Plugin*> repo = p->getEffects()->getRepo()->getAll();

            vector<Plugin*> plugins( repo.begin(), repo.end() );

            output["effects"] = getJSON(
                plugins
            );


            //Save json

            saveToFile( fileName.c_str(), output );

        };

};

}; };
