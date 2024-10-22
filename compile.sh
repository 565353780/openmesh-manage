#!/bin/bash

set -ex

TARGET_FOLDER=../packages/

rm -rf build

mkdir build
cd build
cmake ..
make -j
cd ..

mkdir -p $TARGET_FOLDER/lib/
cp -f build/libopenmesh_manage.so $TARGET_FOLDER/lib/
cp -f ./3rd/OpenMesh-11.0.0/build/Build/lib/libOpenMeshCore.so $TARGET_FOLDER/lib/
cp -f ./3rd/OpenMesh-11.0.0/build/Build/lib/libOpenMeshTools.so $TARGET_FOLDER/lib/

mkdir -p $TARGET_FOLDER/include/openmesh-manage/
cp -rf include/* $TARGET_FOLDER/include/openmesh-manage/