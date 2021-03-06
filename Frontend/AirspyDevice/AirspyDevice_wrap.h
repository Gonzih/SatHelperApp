/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

// source: Frontend/AirspyDevice/AirspyDevice.i

#ifndef SWIG_AirspyDevice_WRAP_H_
#define SWIG_AirspyDevice_WRAP_H_

class Swig_memory;

class SwigDirector_AirspyDeviceCallback : public GoDeviceCallback
{
 public:
  SwigDirector_AirspyDeviceCallback(int swig_p);
  void _swig_upcall_cbFloatIQ(void *data, int length) {
    GoDeviceCallback::cbFloatIQ(data,length);
  }
  virtual void cbFloatIQ(void *data, int length);
  void _swig_upcall_cbS16IQ(void *data, int length) {
    GoDeviceCallback::cbS16IQ(data,length);
  }
  virtual void cbS16IQ(void *data, int length);
  void _swig_upcall_cbS8IQ(void *data, int length) {
    GoDeviceCallback::cbS8IQ(data,length);
  }
  virtual void cbS8IQ(void *data, int length);
  void _swig_upcall_Info(std::string arg0) {
    GoDeviceCallback::Info(arg0);
  }
  virtual void Info(std::string arg0);
  void _swig_upcall_Error(std::string arg0) {
    GoDeviceCallback::Error(arg0);
  }
  virtual void Error(std::string arg0);
  void _swig_upcall_Warn(std::string arg0) {
    GoDeviceCallback::Warn(arg0);
  }
  virtual void Warn(std::string arg0);
  void _swig_upcall_Debug(std::string arg0) {
    GoDeviceCallback::Debug(arg0);
  }
  virtual void Debug(std::string arg0);
  virtual ~SwigDirector_AirspyDeviceCallback();
 private:
  intgo go_val;
  Swig_memory *swig_mem;
};

#endif
