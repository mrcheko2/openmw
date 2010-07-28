
#include "statsextensions.hpp"

#include <components/compiler/extensions.hpp>

#include <components/interpreter/interpreter.hpp>
#include <components/interpreter/runtime.hpp>
#include <components/interpreter/opcodes.hpp>

#include "interpretercontext.hpp"

namespace MWScript
{
    namespace Stats
    {
        class OpGetAttribute : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpGetAttribute (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    Interpreter::Type_Integer value =
                        context.getReference().getCreatureStats().mAttributes[mIndex].
                        getModified();

                    runtime.push (value);
                }
        };

        class OpGetAttributeExplicit : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpGetAttributeExplicit (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    std::string id = runtime.getStringLiteral (runtime[0].mInteger);
                    runtime.pop();

                    Interpreter::Type_Integer value =
                        context.getWorld().getPtr (id, false).getCreatureStats().mAttributes[mIndex].
                        getModified();

                    runtime.push (value);
                }
        };

        class OpSetAttribute : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpSetAttribute (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    Interpreter::Type_Integer value = runtime[0].mInteger;
                    runtime.pop();

                    context.getReference().getCreatureStats().mAttributes[mIndex].
                        setModified (value, 0);
                }
        };

        class OpSetAttributeExplicit : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpSetAttributeExplicit (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    std::string id = runtime.getStringLiteral (runtime[0].mInteger);
                    runtime.pop();

                    Interpreter::Type_Integer value = runtime[0].mInteger;
                    runtime.pop();

                    context.getWorld().getPtr (id, false).getCreatureStats().mAttributes[mIndex].
                        setModified (value, 0);
                }
        };

        class OpModAttribute : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpModAttribute (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    Interpreter::Type_Integer value = runtime[0].mInteger;
                    runtime.pop();

                    value += context.getReference().getCreatureStats().mAttributes[mIndex].
                        getModified();

                    context.getReference().getCreatureStats().mAttributes[mIndex].
                        setModified (value, 0, 100);
                }
        };

        class OpModAttributeExplicit : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpModAttributeExplicit (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    std::string id = runtime.getStringLiteral (runtime[0].mInteger);
                    runtime.pop();

                    Interpreter::Type_Integer value = runtime[0].mInteger;
                    runtime.pop();

                    value +=
                        context.getWorld().getPtr (id, false).getCreatureStats().mAttributes[mIndex].
                        getModified();

                    context.getWorld().getPtr (id, false).getCreatureStats().mAttributes[mIndex].
                        setModified (value, 0, 100);
                }
        };

        class OpGetDynamic : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpGetDynamic (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    if (mIndex==0)
                    {
                        // TODO health is a special case


                    }

                    Interpreter::Type_Integer value =
                        context.getReference().getCreatureStats().mDynamic[mIndex].
                        getCurrent();

                    runtime.push (value);
                }
        };

        class OpGetDynamicExplicit : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpGetDynamicExplicit (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    std::string id = runtime.getStringLiteral (runtime[0].mInteger);
                    runtime.pop();

                    Interpreter::Type_Integer value =
                        context.getWorld().getPtr (id, false).getCreatureStats().mDynamic[mIndex].
                        getCurrent();

                    runtime.push (value);
                }
        };

        class OpSetDynamic : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpSetDynamic (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    Interpreter::Type_Integer value = runtime[0].mInteger;
                    runtime.pop();

                    context.getReference().getCreatureStats().mDynamic[mIndex].
                        setModified (value, 0);
                }
        };

        class OpSetDynamicExplicit : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpSetDynamicExplicit (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    std::string id = runtime.getStringLiteral (runtime[0].mInteger);
                    runtime.pop();

                    Interpreter::Type_Integer value = runtime[0].mInteger;
                    runtime.pop();

                    context.getWorld().getPtr (id, false).getCreatureStats().mDynamic[mIndex].
                        setModified (value, 0);
                }
        };

        class OpModDynamic : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpModDynamic (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    Interpreter::Type_Integer diff = runtime[0].mInteger;
                    runtime.pop();

                    MWMechanics::CreatureStats& stats = context.getReference().getCreatureStats();

                    Interpreter::Type_Integer current = stats.mDynamic[mIndex].getCurrent();

                    stats.mDynamic[mIndex].setModified (
                        diff + stats.mDynamic[mIndex].getModified(), 0);

                    stats.mDynamic[mIndex].setCurrent (diff + current);
                }
        };

        class OpModDynamicExplicit : public Interpreter::Opcode0
        {
                int mIndex;

            public:

                OpModDynamicExplicit (int index) : mIndex (index) {}

                virtual void execute (Interpreter::Runtime& runtime)
                {
                    MWScript::InterpreterContext& context
                        = static_cast<MWScript::InterpreterContext&> (runtime.getContext());

                    std::string id = runtime.getStringLiteral (runtime[0].mInteger);
                    runtime.pop();

                    Interpreter::Type_Integer diff = runtime[0].mInteger;
                    runtime.pop();

                    MWMechanics::CreatureStats& stats =
                        context.getWorld().getPtr (id, false).getCreatureStats();

                    Interpreter::Type_Integer current = stats.mDynamic[mIndex].getCurrent();

                    stats.mDynamic[mIndex].setModified (
                        diff + stats.mDynamic[mIndex].getModified(), 0);

                    stats.mDynamic[mIndex].setCurrent (diff + current);
                }
        };

        const int numberOfAttributes = 8;

        const int opcodeGetAttribute = 0x2000027;
        const int opcodeGetAttributeExplicit = 0x200002f;
        const int opcodeSetAttribute = 0x2000037;
        const int opcodeSetAttributeExplicit = 0x200003f;
        const int opcodeModAttribute = 0x2000047;
        const int opcodeModAttributeExplicit = 0x200004f;

        const int numberOfDynamics = 3;

        const int opcodeGetDynamic = 0x2000057;
        const int opcodeGetDynamicExplicit = 0x200005a;
        const int opcodeSetDynamic = 0x200005d;
        const int opcodeSetDynamicExplicit = 0x2000060;
        const int opcodeModDynamic = 0x2000063;
        const int opcodeModDynamicExplicit = 0x2000066;

        void registerExtensions (Compiler::Extensions& extensions)
        {
            static const char *attributes[numberOfAttributes] =
            {
                "strength", "intelligence", "willpower", "agility", "speed", "endurance",
                "personality", "luck"
            };

            static const char *dynamics[numberOfDynamics] =
            {
                "health", "magicka", "fatigue"
            };

            std::string get ("get");
            std::string set ("set");
            std::string mod ("mod");

            for (int i=0; i<numberOfAttributes; ++i)
            {
                extensions.registerFunction (get + attributes[i], 'l', "",
                    opcodeGetAttribute+i, opcodeGetAttributeExplicit+i);

                extensions.registerInstruction (set + attributes[i], "l",
                    opcodeSetAttribute+i, opcodeSetAttributeExplicit+i);

                extensions.registerInstruction (mod + attributes[i], "l",
                    opcodeModAttribute+i, opcodeModAttributeExplicit+i);
            }

            for (int i=0; i<numberOfDynamics; ++i)
            {
                extensions.registerFunction (get + dynamics[i], 'l', "",
                    opcodeGetDynamic+i, opcodeGetDynamicExplicit+i);

                extensions.registerInstruction (set + dynamics[i], "l",
                    opcodeSetDynamic+i, opcodeSetDynamicExplicit+i);

                extensions.registerInstruction (mod + dynamics[i], "l",
                    opcodeModDynamic+i, opcodeModDynamicExplicit+i);
            }
        }

        void installOpcodes (Interpreter::Interpreter& interpreter)
        {
            for (int i=0; i<numberOfAttributes; ++i)
            {
                interpreter.installSegment5 (opcodeGetAttribute+i, new OpGetAttribute (i));
                interpreter.installSegment5 (opcodeGetAttributeExplicit+i,
                    new OpGetAttributeExplicit (i));

                interpreter.installSegment5 (opcodeSetAttribute+i, new OpSetAttribute (i));
                interpreter.installSegment5 (opcodeSetAttributeExplicit+i,
                    new OpSetAttributeExplicit (i));

                interpreter.installSegment5 (opcodeModAttribute+i, new OpModAttribute (i));
                interpreter.installSegment5 (opcodeModAttributeExplicit+i,
                    new OpModAttributeExplicit (i));
            }

            for (int i=0; i<numberOfDynamics; ++i)
            {
                interpreter.installSegment5 (opcodeGetDynamic+i, new OpGetDynamic (i));
                interpreter.installSegment5 (opcodeGetDynamicExplicit+i,
                    new OpGetDynamicExplicit (i));

                interpreter.installSegment5 (opcodeSetDynamic+i, new OpSetDynamic (i));
                interpreter.installSegment5 (opcodeSetDynamicExplicit+i,
                    new OpSetDynamicExplicit (i));

                interpreter.installSegment5 (opcodeModDynamic+i, new OpModDynamic (i));
                interpreter.installSegment5 (opcodeModDynamicExplicit+i,
                    new OpModDynamicExplicit (i));
            }
        }
    }
}
