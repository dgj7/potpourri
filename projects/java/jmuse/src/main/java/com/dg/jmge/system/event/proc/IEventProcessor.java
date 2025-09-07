package com.dg.jmge.system.event.proc;

import com.dg.jmge.model.event.AbstractEvent;

public interface IEventProcessor {
    void process(AbstractEvent event);
}