package com.dg.jmge.system.event.journal;

//import org.apache.log4j.Logger;

import com.dg.jmge.model.event.AbstractEvent;

/**
 * in the future this will log events differently than normal log files.
 * the value with this is to recreate/debug issues based on the events in
 * the journal when the error occurred.
 *
 * @version 0.1
 * @since 6/21/2017
 */
public class EventJournal {
    //private static Logger logger = Logger.getLogger(EventJournal.class);

    public void log(AbstractEvent event) {
        //if(event != null)
        //	logger.trace("journal: " + event.getClass().getSimpleName() + " with id [" + event.getEventId() + "].");
        //else
        //	logger.trace("journal: null event.");
    }
}