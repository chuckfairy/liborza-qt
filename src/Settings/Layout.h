/**
 * Settings layout tab
 */
#pragma once

#include <QtCore>
#include <QWidget>

#include <Layouts/LayoutWriter.h>
#include <Jack/Server.h>

#include <Widget/OutputDropdown.h>
#include <Widget/InputDropdown.h>
#include <Widget/BaseLineEdit.h>

#include <ui_SettingsLayout.h>


using Orza::Widget::InputDropdown;
using Orza::Widget::OutputDropdown;
using Jack::Server;


/**
 * Forwading
 */

namespace Orza { namespace Settings {

/**
 * class
 */

class Layout : public QWidget {

    Q_OBJECT;


	public:

		Layout( Server * );

		void updateOutputPorts();

		/**
		 * Save preset layout
		 */

		void saveLayout();

		void loadPreset();

		InputDropdown * getInputDropdown() {

			return _InputDropdown;

		};


		/**
		 * Input change handle
		 */

		void handleInputChange( void * data );


	public slots:

		void handleSaveClick();

		void handlePresetLoadClick();


	private:

		Server * _Server;

		/**
		 * UI
		 */

		Ui_SettingsLayout _UI;

        Orza::App::Layouts::LayoutWriter * _LayoutWriter;

		/**
		 * Widget dropdowns
		 */

		OutputDropdown * _LeftOutput;
		OutputDropdown * _RightOutput;

		InputDropdown * _InputDropdown;

		Widget::BaseLineEdit * _PresetName;


		/**
		 * Main event
		 */

		Util::Event * _Event;


		/**
		 * Private setters for cleaniness
		 */

		void setDropdowns();

		void setEvents();

		void setAppUI();

};

} }
