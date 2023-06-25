


cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(QtWidgetDemo)


# find Qt5 and required components
find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)



set(project_ui mainwindow.ui)
set(project_headers mainwindow.h)
set(project_sources mainwindow.cpp main.cpp)


qt5_wrap_ui(ui_wrap ${PROJECT_UI})
qt5_wrap_cpp(moc_sources ${PROJECT_HEADERS})


add_executable(
	${PROJECT_NAME} 
	${PROJECT_HEADERS}
	${PROJECT_SOURCES}
	${UI_WRAP}
	${MOC_SOURCES}
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC
	Qt5::Core
	Qt5::Gui 
	Qt5::Widgets
)
