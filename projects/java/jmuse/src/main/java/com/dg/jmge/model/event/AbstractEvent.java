package com.dg.jmge.model.event;

import java.util.Date;
import java.util.concurrent.atomic.AtomicLong;

public abstract class AbstractEvent {
    private static AtomicLong eventIdBase = new AtomicLong((new Date()).getTime());

    protected long eventId = 0;
    private EventSource eventSource = EventSource.Undefined;

    protected AbstractEvent(EventSource eventSourceInput) {
        eventId = eventIdBase.getAndIncrement();
        eventSource = eventSourceInput;
    }

    public long getEventId() {
        return eventId;
    }

    public EventSource getEventSource() {
        return eventSource;
    }
}