/**
 * Instrument dropdown / combobox widget
 *
 */
#include <Midi/Note.h>

#include "MidiNoteDropdown.h"

using std::vector;

namespace Orza { namespace Widget {


vector<unsigned int> MidiNoteDropdown::VALUES = {};

MidiNoteDropdown::MidiNoteDropdown() {

    MidiNoteDropdown::buildOn( this );

};


/**
 * Main shared setup
 */

void MidiNoteDropdown::buildOn( QComboBox * combo ) {

    if( VALUES.empty() ) {

        MidiNoteDropdown::buildData();

    }

    for( int i = 0; i < VALUES.size(); ++ i ) {

        combo->addItem( buildDropdown( VALUES[ i ] ) );

    }

};


/**
 * Build midi num vectors
 */

void MidiNoteDropdown::buildData() {

    int i = Orza::Midi::NOTE_MIN;

    for( i; i < Orza::Midi::NOTE_MAX; ++ i ) {

        VALUES.push_back( i );

    }

};


/**
 * Build dropdown char
 */

const char * MidiNoteDropdown::buildDropdown( int id ) {

    const char * format = "%s (%i)";

    const char * name = Orza::Midi::NOTE_NAMES[ id - 21 ];

	char * data = (char*) malloc(
		( sizeof( format ) + sizeof( name ) + 10 )
		* sizeof( const char * )
	);

	sprintf( data, format, name, id );

    return (const char*) data;

};

} }
