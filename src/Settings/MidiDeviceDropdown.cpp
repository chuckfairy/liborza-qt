/**
 * Midi device drop down impl
 *
 */
#include <vector>

#include <Jack/Port.h>
#include <Jack/Server.h>
#include <Jack/Midi.h>

#include "MidiDeviceDropdown.h"

using std::vector;

using Jack::Server;


/**
 * Constructor test
 *
 */

MidiDeviceDropdown::MidiDeviceDropdown( Server * win ) :
    QComboBox(),
    _Server( win )
{

    vector<Jack::Port> ports = _Server->getMidi()
        ->getMidiPorts();

    vector<Jack::Port>::iterator itVec;

    for( itVec = ports.begin(); itVec != ports.end(); ++itVec ) {

        addMidiDevice( &(*itVec) );

    }

};


/**
 * Add instrument implmentation
 * Will use list iterator
 *
 */
void MidiDeviceDropdown::addMidiDevice( Jack::Port * port , const int order ) {

    addItem( port->name );

    //MidiDevices.push_back( device );

};
