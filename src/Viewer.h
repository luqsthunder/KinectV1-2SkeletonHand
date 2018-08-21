/*******************************************************************************
*                                                                              *
*   PrimeSense NiTE 2.0 - User Viewer Sample                                   *
*   Copyright (C) 2012 PrimeSense Ltd.                                         *
*                                                                              *
*******************************************************************************/

#ifndef _NITE_USER_VIEWER_H_
#define _NITE_USER_VIEWER_H_

#include "NiTE.h"
#include <opencv2/core.hpp>

#define MAX_DEPTH 10000

class SampleViewer {
public:
  explicit SampleViewer(const char *strSampleName);

  virtual ~SampleViewer();

  virtual openni::Status Init(int argc, char **argv);

  virtual openni::Status Run();  //Does not return

  SampleViewer(const SampleViewer &) = delete;

  SampleViewer &operator=(SampleViewer &) = delete;

protected:
  virtual void Display();

  virtual void DisplayPostDraw() {};  // Overload to draw over the screen image

  virtual void OnKey(unsigned char key, int x, int y);

  virtual openni::Status InitOpenGL(int argc, char **argv);

  void InitOpenGLHooks();

  void Finalize();

private:

  static SampleViewer *ms_self;

  static void glutIdle();

  static void glutDisplay();

  static void glutKeyboard(unsigned char key, int x, int y);

  float m_pDepthHist[MAX_DEPTH];
  char m_strSampleName[ONI_MAX_STR];
  openni::RGB888Pixel *m_pTexMap;
  unsigned int m_nTexMapX;
  unsigned int m_nTexMapY;

  openni::Device m_device;
  nite::UserTracker *m_pUserTracker;

  nite::UserId m_poseUser;
  uint64_t m_poseTime;
  cv::Mat _imCut, _im50x50;
};


#endif // _NITE_USER_VIEWER_H_
