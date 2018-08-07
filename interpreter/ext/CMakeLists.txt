#set(BUILD_SHARED_LIBS ON CACHE BOOL " " FORCE)
#
### GoogleTest
#set(GTEST_INCLUDE_DIR
#    ${CMAKE_CURRENT_SOURCE_DIR}/googletest)
#
#set(CompilerFlags
#    GTEST_INCLUDE_DIR)
#
#option(BUILD_GTEST ON)
#
#foreach(CompilerFlag ${CompilerFlags})
#    set(${CompilerFlag} "${${CompilerFlag}}" PARENT_SCOPE)
#endforeach()
