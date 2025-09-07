package com.dg.jmge.system.event.proc;

import com.dg.jmge.model.event.AbstractEvent;
import org.apache.log4j.Logger;

public class UndefinedEventProcessor implements IEventProcessor {
    private static final Logger logger = Logger.getLogger(UndefinedEventProcessor.class);

    public void process(AbstractEvent event) {
        logger.trace("ignoring undefined event type [" + event.getClass().getSimpleName() + "] with id [" + event.getEventId() + "].");
    }
}