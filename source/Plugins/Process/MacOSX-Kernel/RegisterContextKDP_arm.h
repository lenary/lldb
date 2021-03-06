//===-- RegisterContextKDP_arm.h --------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef liblldb_RegisterContextKDP_arm_h_
#define liblldb_RegisterContextKDP_arm_h_

// C Includes

// C++ Includes
// Other libraries and framework includes
// Project includes
#include "Plugins/Process/Utility/RegisterContextDarwin_arm.h"

class ThreadKDP;

class RegisterContextKDP_arm : public RegisterContextDarwin_arm {
public:
  RegisterContextKDP_arm(ThreadKDP &thread, uint32_t concrete_frame_idx);

  virtual ~RegisterContextKDP_arm();

protected:
  virtual int DoReadGPR(lldb::tid_t tid, int flavor, GPR &gpr);

  int DoReadFPU(lldb::tid_t tid, int flavor, FPU &fpu);

  int DoReadEXC(lldb::tid_t tid, int flavor, EXC &exc);

  int DoReadDBG(lldb::tid_t tid, int flavor, DBG &dbg);

  int DoWriteGPR(lldb::tid_t tid, int flavor, const GPR &gpr);

  int DoWriteFPU(lldb::tid_t tid, int flavor, const FPU &fpu);

  int DoWriteEXC(lldb::tid_t tid, int flavor, const EXC &exc);

  int DoWriteDBG(lldb::tid_t tid, int flavor, const DBG &dbg);

  ThreadKDP &m_kdp_thread;
};

#endif // liblldb_RegisterContextKDP_arm_h_
