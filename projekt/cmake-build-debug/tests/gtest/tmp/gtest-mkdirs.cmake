# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest/src/gtest"
  "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest/src/gtest-build"
  "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest"
  "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest/tmp"
  "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest/src/gtest-stamp"
  "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest/src"
  "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest/src/gtest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest/src/gtest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/ja/Desktop/studia/sdizo/pwr_projekt_sdizo/projekt/cmake-build-debug/tests/gtest/src/gtest-stamp${cfgdir}") # cfgdir has leading slash
endif()
