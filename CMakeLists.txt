cmake_minimum_required(VERSION 3.8)
project(demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

set (SRC 
     src/main.cpp 
    )  

# build executable 
add_executable(demo ${SRC}) 

# include directories 
include_directories(${PROJECT_SOURCE_DIR}/include)

# ament_target_dependencies() dep pkgs 

# target_include_directories() include headers 
target_include_directories(demo 
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
) 


install (TARGETS demo 
        DESTINATION bin)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # dependency: gtest
  find_package(ament_cmake_gtest REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)

  set (TEST 
       src/demo.cpp  
       unitest/ut.cpp  
  )

  ament_add_gtest(${PROJECT_NAME}_test ${TEST})

  # ament_target_dependencies(${PROJECT_NAME}_test <deps>)

  # install 
  install(TARGETS ${PROJECT_NAME}_test
          DESTINATION unitest)

  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
