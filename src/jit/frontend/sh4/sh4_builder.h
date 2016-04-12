#ifndef SH4_BUILDER_H
#define SH4_BUILDER_H

#include "jit/frontend/sh4/sh4_context.h"
#include "jit/frontend/sh4/sh4_disassembler.h"
#include "jit/ir/ir_builder.h"

namespace re {

namespace hw {
class Memory;
}

namespace jit {
namespace frontend {
namespace sh4 {

class SH4Builder : public ir::IRBuilder {
 public:
  SH4Builder(Arena &arena);

  void Emit(uint32_t guest_addr, uint8_t *host_addr, int flags);

  ir::Instr *LoadGuest(ir::Value *addr, ir::ValueType type);
  void StoreGuest(ir::Value *addr, ir::Value *v);
  ir::Value *LoadGPR(int n, ir::ValueType type);
  void StoreGPR(int n, ir::Value *v);
  ir::Value *LoadFPR(int n, ir::ValueType type);
  void StoreFPR(int n, ir::Value *v);
  ir::Value *LoadXFR(int n, ir::ValueType type);
  void StoreXFR(int n, ir::Value *v);
  ir::Value *LoadSR();
  void StoreSR(ir::Value *v);
  ir::Value *LoadT();
  void StoreT(ir::Value *v);
  ir::Value *LoadGBR();
  void StoreGBR(ir::Value *v);
  ir::Value *LoadFPSCR();
  void StoreFPSCR(ir::Value *v);
  ir::Value *LoadPR();
  void StorePR(ir::Value *v);

  void InvalidInstruction(uint32_t guest_addr);

  bool EmitDelayInstr(const Instr &prev, int flags);

 private:
  uint32_t pc_;
  uint8_t *host_addr_;
  int flags_;
  int guest_cycles_;
};
}
}
}
}

#endif
