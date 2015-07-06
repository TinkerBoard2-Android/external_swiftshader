//===- subzero/src/IceRegistersARM32.h - Register information ---*- C++ -*-===//
//
//                        The Subzero Code Generator
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file declares the registers and their encodings for ARM32.
///
//===----------------------------------------------------------------------===//

#ifndef SUBZERO_SRC_ICEREGISTERSARM32_H
#define SUBZERO_SRC_ICEREGISTERSARM32_H

#include "IceDefs.h"
#include "IceInstARM32.def"
#include "IceTypes.h"

namespace Ice {

namespace RegARM32 {

/// An enum of every register. The enum value may not match the encoding
/// used to binary encode register operands in instructions.
enum AllRegisters {
#define X(val, encode, name, scratch, preserved, stackptr, frameptr, isInt,    \
          isFP)                                                                \
  val,
  REGARM32_TABLE
#undef X
      Reg_NUM,
#define X(val, init) val init,
  REGARM32_TABLE_BOUNDS
#undef X
};

/// An enum of GPR Registers. The enum value does match the encoding used
/// to binary encode register operands in instructions.
enum GPRRegister {
#define X(val, encode, name, scratch, preserved, stackptr, frameptr, isInt,    \
          isFP)                                                                \
  Encoded_##val encode,
  REGARM32_GPR_TABLE
#undef X
      Encoded_Not_GPR = -1
};

// TODO(jvoung): Floating point and vector registers...
// Need to model overlap and difference in encoding too.

static inline GPRRegister getEncodedGPR(int32_t RegNum) {
  assert(Reg_GPR_First <= RegNum && RegNum <= Reg_GPR_Last);
  return GPRRegister(RegNum - Reg_GPR_First);
}

} // end of namespace RegARM32

} // end of namespace Ice

#endif // SUBZERO_SRC_ICEREGISTERSARM32_H
