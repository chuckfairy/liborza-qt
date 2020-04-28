/**
 * Popup widget
 */
#pragma once

#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QVBoxLayout>


namespace Orza { namespace Widget {

class Popup : public QWidget {

	Q_OBJECT

	public:

		explicit Popup(QWidget * parent) :
		QWidget(parent),
		widgetParent(parent)
		{
			setupLayout();
			resize();
		};

		void resize() {
			setGeometry( 0, 0, widgetParent->width(), widgetParent->height() );
		}

		void addLayoutWidget(QWidget * widget) {
			_layout->addWidget(widget);
		}

	protected:
		void resizeEvent(QResizeEvent * event) {
			resize();
		};

	private:
		QWidget * widgetParent;

		QVBoxLayout * _layout;

		void setupLayout() {

			_layout = new QVBoxLayout();
			_layout->setSpacing( 0 );
			_layout->setContentsMargins(0, 0, 0, 0);

			setLayout( _layout );

		};

};

}; };
