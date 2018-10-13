/**
 * Instrument dropdown / combobox widget
 *
 */
#pragma once

#include <map>
#include <vector>
#include <iostream>

#include <QtCore>
#include <QtGui>
#include <QComboBox>
#include <QMessageBox>


using std::vector;


namespace Orza { namespace Widget {


class MidiNoteDropdown : public QComboBox {

    Q_OBJECT

    public:


        MidiNoteDropdown();
        ~MidiNoteDropdown() {};


        /**
         * Main shared setup
         */

        static void buildOn( QComboBox * );

        static void getValue( unsigned int );


    private:

        /**
         * Props
         */

        static vector<unsigned int> VALUES;

        static void buildData();

        static const char * buildDropdown( int );


};


} }
