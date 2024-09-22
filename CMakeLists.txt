
cmake_minimum_required (VERSION 2.6)



project(interpretter-programmer)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

find_package(PkgConfig REQUIRED)
#find_package(MySQL REQUIRED)
#find_library(TRT_LIB trtinfer)
#find_library(ENDO_API endoapi)
#find_library(LIBI2C i2ctools)


#opencv
# pkg_check_modules(OpenCV REQUIRED opencv)
#gtkmm
pkg_check_modules(gtkmm REQUIRED gtkmm-3.0)

file(GLOB SOURCES
        "${CMAKE_SOURCE_DIR}/*.cpp"
        "${CMAKE_SOURCE_DIR}/cpp/settings/*.cpp"
        
        )

include_directories(
    # ${CMAKE_SOURCE_DIR}/utils
    # ${CMAKE_SOURCE_DIR}/ENDO_API
    # "/usr/local/cuda-10.2/targets/aarch64-linux/include"
    # ${OpenCV_INCLUDE_DIRS}
    ${gtkmm_INCLUDE_DIRS}
    # ${CMAKE_SOURCE_DIR}/hpp
    #"usr/include/mysql"
    #"/usr/src/tensorrt/samples/common/"
    
    )

link_directories(
        # /usr/local/cuda-10.2/targets/aarch64-linux/lib
		# /usr/lib/aarch64-linux-gnu/tegra	
		# /usr/local/cuda/lib64
		/usr/local/lib/	
        # ${CMAKE_SOURCE_DIR}/build/ENDO_API/
		)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    # ${OpenCV_LIBRARIES}
    ${gtkmm_LIBRARIES}
    #lsoci_core
    #-lsoci_mysql
    
    )

# target_compile_options(${PROJECT_NAME} PUBLIC ${OpenCV_CFLAGS_OTHER} ${gtkmm_CFLAGS_OTHER})
target_compile_options(${PROJECT_NAME} PUBLIC  ${gtkmm_CFLAGS_OTHER})


# add_subdirectory(utils)
# add_subdirectory(ENDO_API)
#add_subdirectory(I2C_LIB)



# FILE(COPY res DESTINATION "${CMAKE_BINARY_DIR}")

include(CPack)
