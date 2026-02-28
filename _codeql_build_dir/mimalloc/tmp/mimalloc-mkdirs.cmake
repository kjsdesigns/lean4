# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/src/mimalloc")
  file(MAKE_DIRECTORY "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/src/mimalloc")
endif()
file(MAKE_DIRECTORY
  "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/src/mimalloc-build"
  "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc"
  "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/tmp"
  "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/src/mimalloc-stamp"
  "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/src"
  "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/src/mimalloc-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/src/mimalloc-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/runner/work/lean4/lean4/_codeql_build_dir/mimalloc/src/mimalloc-stamp${cfgdir}") # cfgdir has leading slash
endif()
