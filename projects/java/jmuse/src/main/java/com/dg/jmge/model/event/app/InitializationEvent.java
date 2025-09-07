package com.dg.jmge.model.event.app;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.model.event.EventSource;

public class InitializationEvent extends AbstractEvent {
    public InitializationEvent() {
        super(EventSource.Initialization);
    }
}