# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
set(AUTOGEN_TARGET_DEPENDS ON)

# find the location of Qt header files and libraries
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)


file(GLOB liborza-qt_UIS
	Widget/*.ui
	LV2/PluginArea.ui
	MidiControl/Control.ui
	MidiControl/ControlPort.ui
	MidiControl/ControlPortValue.ui
	Settings/SettingsLayout.ui
)

#file(GLOB common-ladspa ../common/LADSPA/*.cpp)

qt5_wrap_ui(liborza-qt_UIS ${liborza-qt_UIS} )

qt5_add_resources(RESOURCES ./Resources.qrc)


#links

#FIND_PACKAGE(Boost)
find_package( Boost 1.45.0 COMPONENTS filesystem regex )

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	../common /usr/local/lib

	"${LIBORZAQT_ROOT_PATH}/../liborza/lib-src"
	"${LIBORZA_ROOT_PATH}/lib-src"
	"${LIBORZA_ROOT_PATH}/src/common/Audio"
	"${LIBORZA_ROOT_PATH}/src/"
	"${LIBORZAQT_ROOT_PATH}/../liborza/lib-src/json"

	${LIBORZA_LIB_PATH}

	"../lib-src"
	"../../liborza/lib-src"
	"../../liborza/src"
	"${CMAKE_CURRENT_BINARY_DIR}/../../liborza/lib-src"
	"${CMAKE_CURRENT_BINARY_DIR}/../../liborza/lib-src/json"
	"${CMAKE_CURRENT_BINARY_DIR}/../../liborza/src"

	${Boost_INCLUDE_DIR}
)


# tell CMake to compile every .cpp file in this directory and add it to an executable named `liborza.qt`
file(
	GLOB
	liborza-qt_SRC
	"../lib-src/QtAwesome/*.cpp"
	Resource/*.cpp
	MidiControl/*.cpp
	main.cpp
	#**/moc_*.cpp
	#*.moc
	Widget/*.cpp
	#Layouts/*.cpp
	LV2/*.cpp
	Settings/*.cpp
	Settings/Events/*.cpp
)


# Qt Objects / mocs

FILE( GLOB moc_files
	Pi/Layout.h
	"../lib-src/QtAwesome/*.h"
	Widget/AbstractDropdown.h
	Widget/AbstractIODropdown.h
	Widget/InstrumentDropdown.h
	Widget/Patchbay.h
	Widget/MidiNoteDropdown.h
	Widget/PatchbayPlugin.h
	Widget/SimpleLayout.h
	Widget/SingleInstrument.h
	Widget/InputDropdown.h
	Widget/OutputDropdown.h
	Widget/TreeNode.h
	Widget/Popup.h
	Settings/MidiDeviceDropdown.h
	LV2/IOPortChanger.h
	LV2/PresetDropdown.h
	LV2/WindowLayout.h
	Settings/Layout.h
	MidiControl/*.h
)

QT5_WRAP_CPP( MY_MOCED_FILES ${moc_files} )


# Main executable

add_library(liborza-qt STATIC ${liborza-qt_SRC} ${RESOURCES} ${MY_MOCED_FILES} ${liborza-qt_UIS})

target_link_libraries( liborza-qt
	PUBLIC
	dl
	liborza-common-jack
	liborza-common-plugin
	liborza-common-lv2
	Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	Qt5::Qml
	${Boost_LIBRARIES}
)

install( TARGETS
   liborza-qt

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
