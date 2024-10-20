# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(launch_project_s_CONFIG_INCLUDED)
  return()
endif()
set(launch_project_s_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("FALSE" STREQUAL "TRUE")
  set(launch_project_s_SOURCE_PREFIX /home/segula/Desktop/ava/achitecture_ws/src/launch_project_s)
  set(launch_project_s_DEVEL_PREFIX /home/segula/Desktop/ava/achitecture_ws/devel)
  set(launch_project_s_INSTALL_PREFIX "")
  set(launch_project_s_PREFIX ${launch_project_s_DEVEL_PREFIX})
else()
  set(launch_project_s_SOURCE_PREFIX "")
  set(launch_project_s_DEVEL_PREFIX "")
  set(launch_project_s_INSTALL_PREFIX /home/segula/Desktop/ava/achitecture_ws/install)
  set(launch_project_s_PREFIX ${launch_project_s_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'launch_project_s' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(launch_project_s_FOUND_CATKIN_PROJECT TRUE)

if(NOT " " STREQUAL " ")
  set(launch_project_s_INCLUDE_DIRS "")
  set(_include_dirs "")
  if(NOT " " STREQUAL " ")
    set(_report "Check the issue tracker '' and consider creating a ticket if the problem has not been reported yet.")
  elseif(NOT " " STREQUAL " ")
    set(_report "Check the website '' for information and consider reporting the problem.")
  else()
    set(_report "Report the problem to the maintainer 'sorin <sorin@todo.todo>' and request to fix the problem.")
  endif()
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${launch_project_s_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'launch_project_s' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  ${_report}")
      endif()
    else()
      message(FATAL_ERROR "Project 'launch_project_s' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/segula/Desktop/ava/achitecture_ws/install/${idir}'.  ${_report}")
    endif()
    _list_append_unique(launch_project_s_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND launch_project_s_LIBRARIES ${library})
  elseif(TARGET ${library})
    list(APPEND launch_project_s_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND launch_project_s_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /home/segula/Desktop/ava/achitecture_ws/install/lib;/home/dev/as_drivers_customer/install/lib;/home/dev/dbw_ws/devel/lib;/home/segula/Desktop/ava/achitecture_ws/devel/lib;/home/dev/ros_workspace/dev_ws/devel/lib;/home/dev/ros_workspace/as_vehicle/install/lib;/home/dev/ros_workspace/third_party_drivers/devel/lib;/opt/ros/kinetic/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(launch_project_s_LIBRARY_DIRS ${lib_path})
      list(APPEND launch_project_s_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'launch_project_s'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND launch_project_s_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(launch_project_s_EXPORTED_TARGETS "")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${launch_project_s_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 launch_project_s_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${launch_project_s_dep}_FOUND)
      find_package(${launch_project_s_dep} REQUIRED NO_MODULE)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${launch_project_s_dep} REQUIRED NO_MODULE ${depend_list})
  endif()
  _list_append_unique(launch_project_s_INCLUDE_DIRS ${${launch_project_s_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(launch_project_s_LIBRARIES ${launch_project_s_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${launch_project_s_dep}_LIBRARIES})
  _list_append_deduplicate(launch_project_s_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(launch_project_s_LIBRARIES ${launch_project_s_LIBRARIES})

  _list_append_unique(launch_project_s_LIBRARY_DIRS ${${launch_project_s_dep}_LIBRARY_DIRS})
  list(APPEND launch_project_s_EXPORTED_TARGETS ${${launch_project_s_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${launch_project_s_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
