// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vswitch.h"
#include "Vswitch__Syms.h"

//============================================================
// Constructors

Vswitch::Vswitch(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vswitch__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vswitch::Vswitch(const char* _vcname__)
    : Vswitch(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vswitch::~Vswitch() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vswitch___024root___eval_debug_assertions(Vswitch___024root* vlSelf);
#endif  // VL_DEBUG
void Vswitch___024root___eval_static(Vswitch___024root* vlSelf);
void Vswitch___024root___eval_initial(Vswitch___024root* vlSelf);
void Vswitch___024root___eval_settle(Vswitch___024root* vlSelf);
void Vswitch___024root___eval(Vswitch___024root* vlSelf);

void Vswitch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vswitch::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vswitch___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vswitch___024root___eval_static(&(vlSymsp->TOP));
        Vswitch___024root___eval_initial(&(vlSymsp->TOP));
        Vswitch___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vswitch___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vswitch::eventsPending() { return false; }

uint64_t Vswitch::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vswitch::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vswitch___024root___eval_final(Vswitch___024root* vlSelf);

VL_ATTR_COLD void Vswitch::final() {
    Vswitch___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vswitch::hierName() const { return vlSymsp->name(); }
const char* Vswitch::modelName() const { return "Vswitch"; }
unsigned Vswitch::threads() const { return 1; }
