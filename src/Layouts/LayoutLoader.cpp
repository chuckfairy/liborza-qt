/**
 * Qt layout loader impl
 */
#include <Config/Defaults.h>

//#include <Effect/EffectLayout.h>

//#include <InstrumentEffect/InstrumentEffect.h>


#include "LayoutLoader.h"


namespace Orza { namespace Layouts {


/**
 * Construct
 */

LayoutLoader::LayoutLoader( Server * app ) :
    _Server( app )
{

    //@TODO better

    Layout * defaultLayout;

    loadLayout( defaultLayout );

};


void LayoutLoader::loadLayout( Layout * l ) {

    l->setup();

    _CurrentLayout = l;

};


/**
 * Main layout load
 */

void LayoutLoader::load( json * setting ) {

    //if( setting["type"] ) {

        //throw std::runtime_error(
            //"no type in JSON"
        //);

    //}

};

}; };
