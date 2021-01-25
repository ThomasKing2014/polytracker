#ifndef POLYTRACKER_INCLUDE_POLYTRACKER_PASS_H_
#define POLYTRACKER_INCLUDE_POLYTRACKER_PASS_H_

#include <vector>
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/IR/InstVisitor.h"
#include "llvm/IR/DerivedTypes.h"

namespace polytracker {

typedef uint32_t func_index_t;
typedef uint32_t bb_index_t;

struct PolytrackerPass : public llvm::ModulePass {
  static char ID;
  PolytrackerPass() : ModulePass(ID) {}
  bool runOnModule(llvm::Module &function) override;
  bool analyzeFunction(llvm::Function *f, const func_index_t& index);
bool analyzeBlock(llvm::Function *func,
                                    llvm::Value* func_index,
                                   llvm::BasicBlock* curr_bb,
                                   const bb_index_t &bb_index,
                                   std::vector<llvm::BasicBlock *> &split_bbs,
                                   llvm::DominatorTree &DT);
  void initializeTypes(llvm::Module &mod);
  llvm::Module* mod;
  llvm::FunctionCallee func_entry_log;
  llvm::FunctionType* func_entry_type;
  llvm::FunctionCallee func_exit_log;
  llvm::FunctionCallee bb_entry_log;
  llvm::FunctionCallee taint_op_log;
  llvm::FunctionCallee taint_cmp_log;
  llvm::FunctionCallee dfsan_get_label;

  const int shadow_width = 32;
  llvm::IntegerType *shadow_type;
};

struct PolyInstVisitor : public llvm::InstVisitor<PolyInstVisitor> {
  void logBinaryInst(llvm::Instruction* inst);

  //Binary Instructions
  void visitCmpInst(llvm::CmpInst& CI);
  
  llvm::Module* mod;
  llvm::FunctionCallee dfsan_get_label;
  llvm::FunctionCallee taint_op_log;
  llvm::FunctionCallee taint_cmp_log;
};

}; // namespace polytracker

#endif /* POLYTRACKER_INCLUDE_POLYTRACKER_PASS_H_ */
