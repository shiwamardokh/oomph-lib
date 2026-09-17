# ------------------------------------------------------------------------------
list(APPEND CMAKE_MESSAGE_INDENT " ")
message(VERBOSE "Entered plasticity subdirectory")

# Define the headers
set(HEADERS plasticity_elements.h)

# Define the sources
set(SOURCES plasticity_elements.cc)

# Set the name of the library
set(LIBNAME plasticity)

# We depend on the generic library
set(LINKLIBS generic)

# Import the OomphLibraryConfig module to handle the library creation
include(OomphLibraryConfig)
oomph_library_config(
  LIBNAME ${LIBNAME}
  HEADERS ${HEADERS}
  SOURCES ${SOURCES}
  LINKLIBS ${LINKLIBS})

# Silence the annoying (typeid) warning produced by this library
include(OomphTargetSilenceWarnings)
oomph_target_silence_warnings(
  TARGET ${LIBNAME} CXX_COMPILE_FLAGS -Wno-potentially-evaluated-expression)

message(VERBOSE "Leaving plasticity subdirectory")
# ------------------------------------------------------------------------------
