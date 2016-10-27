#ifndef _EVENTS_H_
#define _EVENTS_H_

#include "types.h"

// FIXME:
// aleph has more event types for UI hardware.
// there is probably a cleaner way of doing this.
#ifdef MOD_ALEPH 
#include "aleph_event_types.h"
#else

// enumerate event types
typedef enum {
  kEventNone,
  kEventFront,
  kEventFrontShort,
  kEventFrontLong,
  kEventTimer,
  kEventPollADC,
  kEventKeyTimer,
  kEventSaveFlash,
  kEventClockNormal,
  kEventClockExt,
  /// connect/disconnect FTDI-based devices
  kEventFtdiConnect,
  kEventFtdiDisconnect,
  /// monome protocol
  kEventMonomeConnect,
  kEventMonomeDisconnect,
  kEventMonomePoll,	
  kEventMonomeRefresh, 	
  kEventMonomeGridKey, 
  kEventMonomeRingEnc,
  // HID
  kEventHidConnect,
  kEventHidDisconnect,
  kEventHidPacket,
  kEventHidTimer,

  kEventScreenRefresh,
  // Trigger EVENT (8 digital inputs)
  kEventTrigger,
  kEventII,
  kEventIItx,
  kEventIIrx,

  kEventMidiConnect,
  kEventMidiDisconnect,
  kEventMidiPacket,

  kEventTr,
  kEventTrNormal,
  kEventKey,


  /// dummy/count
  kNumEventTypes,
} etype;

#endif



typedef struct {
  etype type;
  s32 data;
} event_t;

// global array of pointers to handlers
extern void (*app_event_handlers[])(s32 data);

// init event queue
void init_events( void );

// check the queue for pending events
// return 1 if found
u8 event_next( event_t *e );

// add event to tail of queue
// return 1 if success
u8 event_post( event_t *e );

#endif // header guard
