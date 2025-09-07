package com.dg.jmge.system.event.proc;

//import org.apache.log4j.Logger;

import com.dg.jmge.model.event.AbstractEvent;

public class NullEventProcessor implements IEventProcessor {
    //private static Logger logger = Logger.getLogger(NullEventProcessor.class);

    public void process(AbstractEvent event) {
        //logger.trace("handling null event!");
    }
}