# ------------------------------------------------------------------------------
list(APPEND CMAKE_MESSAGE_INDENT " ")
message(VERBOSE "Entered plasticity_constitutive subdirectory")

# Define the headers
set(HEADERS plasticity_constitutive_laws.h)

# Define the sources
set(SOURCES plasticity_constitutive_laws.cc)

# Set the name of the library
set(LIBNAME plasticity_constitutive)

# We depend on the generic library
set(LINKLIBS generic)

# Import the OomphLibraryConfig module to handle the library creation
include(OomphLibraryConfig)
oomph_library_config(
  LIBNAME ${LIBNAME}
  HEADERS ${HEADERS}
  SOURCES ${SOURCES}
  LINKLIBS ${LINKLIBS})

message(VERBOSE "Leaving plasticity_constitutive subdirectory")
# ------------------------------------------------------------------------------
