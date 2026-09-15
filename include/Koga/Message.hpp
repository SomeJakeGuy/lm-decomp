#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "Koga/Array.hpp"
#include "dolphin/types.h"
#include <types.h>

class ToolDataRef;

class MessageReceiver;
typedef bool (MessageReceiver::*MessageCallback1)(int arg0);
typedef bool (MessageReceiver::*MessageCallback2)(int arg0, int arg1);

class MessageRecieverArray : public Koga::Array<MessageReceiver*, 12> {
public:
    MessageRecieverArray() { }
    ~MessageRecieverArray() { }
    void add(MessageReceiver** member) { addMember(member); }
};

class MessageSender {
public:
    MessageSender();

    /* 0x04 */ virtual ~MessageSender();
    /* 0x08 */ virtual void vt_08() = 0;
    /* 0x0C */ virtual void vt_0C() = 0;
    /* 0x10 */ virtual s32 vt_10(MessageCallback1 fn, int arg0);
    /* 0x14 */ virtual s32 vt_14(MessageCallback2 fn, int arg0, int arg1);

    bool addReceiver(MessageReceiver*);

public:
    /* 0x4 */ MessageRecieverArray _4;
};

class IMessageReceiver {
public:
    //Seems to be inlined where its used and doesn't show up in the final binary
    /* 0x04 */ inline virtual ~IMessageReceiver() { }
    /* 0x08 */ virtual BOOL vt_08(ToolDataRef*) = 0;
    /* 0x0C */ virtual BOOL vt_0C(ToolDataRef*) = 0;
    /* 0x10 */ virtual BOOL vt_10(ToolDataRef*, char*) = 0;
};

class MessageReceiver : public IMessageReceiver {
public:
    MessageReceiver();

    /* 0x04 */ virtual ~MessageReceiver();
    /* 0x08 */ virtual BOOL vt_08(ToolDataRef*);
    /* 0x0C */ virtual BOOL vt_0C(ToolDataRef*);
    /* 0x10 */ virtual BOOL vt_10(ToolDataRef*, char*);
};

#endif
