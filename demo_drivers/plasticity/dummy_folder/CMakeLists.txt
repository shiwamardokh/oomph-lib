# ------------------------------------------------------------------------------
# OOMPH auto-inserted: warn once if user configures inside an existing build.
if(EXISTS "${CMAKE_CURRENT_BINARY_DIR}/CMakeCache.txt"
   AND CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  message(
    WARNING
      "You're re-configuring an existing build tree. For a clean configuration, "
      "delete the whole build folder and start with a fresh directory.")
endif()
# ------------------------------------------------------------------------------
list(APPEND CMAKE_MESSAGE_INDENT " ")
message(VERBOSE "Entered dummy_folder subdirectory")

cmake_minimum_required(VERSION 3.24 FATAL_ERROR)
project(dummy_folder C CXX Fortran)

if(NOT oomphlib_FOUND)
  find_package(oomphlib CONFIG REQUIRED PATHS "../../../install")
endif()

include(CTest)

oomph_add_executable(
  NAME dummy_test
  SOURCES dummy_test.cc
  LIBRARIES oomph::plasticity oomph::plasticity_constitutive oomph::meshes oomph::generic)

# ---------------------------------- TESTING ----------------------------------

oomph_add_test(
  TEST_NAME plasticity.dummy_test
  DEPENDS_ON dummy_test
  COMMAND ./validate.sh ${OOMPH_ROOT_DIR}
  TEST_FILES validate.sh validata)

message(VERBOSE "Leaving dummy_folder subdirectory")
# ------------------------------------------------------------------------------
