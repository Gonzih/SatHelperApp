[![Snap Status](https://build.snapcraft.io/badge/opensatelliteproject/SatHelperApp.svg)](https://build.snapcraft.io/user/opensatelliteproject/SatHelperApp) [![Build Status](https://api.travis-ci.org/opensatelliteproject/libsathelper.svg?branch=master)](https://travis-ci.org/opensatelliteproject/libsathelper) [![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](https://tldrlegal.com/license/mit-license)


SatHelperApp
============

The OpenSatelliteProject Satellite Helper Application! This is currently a LRIT/HRIT Demodulator / Decoder program based on [libSatHelper](https://github.com/opensatelliteproject/libsathelper/) and [xritdemod](https://github.com/opensatelliteproject/xritdemod).

It is currently WIP and in Alpha State. Use with care.


Building
========

That's a standard go project. Make sure you have `libSatHelper` and `libairspy` installed and run:

```bash
go get github.com/OpenSatelliteProject/SatHelperApp
```

It will be installed into your `${GOPATH}/bin`. If you have it it on your path, just run `SatHelperApp` 

Have fun!


Ubuntu Instructions to get it running
=====================================

Base tools:
```bash
sudo apt install build-essential cmake swig
```

Quick Instructions to get GO 1.10 running:

```bash
sudo add-apt-repository ppa:gophers/archive
sudo apt-get update
sudo apt-get install golang-1.10-go
mkdir ~/go
export GOPATH=~/go
export GOROOT=/usr/lib/go-1.10
export PATH=$PATH:$GOPATH/bin:$GOROOT/bin
```

Install LibSatHelper:
```bash
git clone https://github.com/opensatelliteproject/libsathelper/
cd libsathelper
make libcorrect
sudo make libcorrect-install
make
sudo make install
```

Install libAirspy:
```bash
git clone https://github.com/airspy/airspyone_host/
cd airspyone_host
mkdir build
cd build
cmake .. -DINSTALL_UDEV_RULES=ON
make -j4
sudo make install
sudo ldconfig
```

Quick Instructions to get SatHelperApp running assuming you have Go 1.10, libSatHelper and libAirspy installed.
```bash
go get github.com/OpenSatelliteProject/SatHelperApp
SatHelperApp
```

This should create a `SatHelperApp.cfg` file in the same folder you ran `SatHelperApp`. You can edit it and tune for your needs.

Have fun!


## Static libLimeSuite

LimeSuite by default only compiles dynamic libraries (see https://github.com/myriadrf/LimeSuite/issues/241), so the default behaviour of SatHelperApp wrapper is to dynamic link. However is possible to statically link the libLimeSuite so no external .so / .dll is needed.

To do that, build the `libLimeSuite` with `-DBUILD_SHARED_LIBS=OFF` to generate `libLimeSuite.a` file.

```bash
# Compile Static
cmake .. -DBUILD_SHARED_LIBS=OFF
make -j8
sudo make install
```

Then change [LimeDevice.go](Frontend/LimeDevice/LimeDevice.go) ldflags line from:

```
#cgo LDFLAGS: -lLimeSuite
```

to

```
#cgo LDFLAGS: -l:libLimeSuite.a -l:libstdc++.a -lm -lusb-1.0
```

And then compile SatHelperApp as normal.