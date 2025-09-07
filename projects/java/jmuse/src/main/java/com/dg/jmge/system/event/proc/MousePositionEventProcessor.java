package com.dg.jmge.system.event.proc;

//import org.apache.log4j.Logger;

import com.dg.jmge.model.event.AbstractEvent;
import com.dg.jmge.model.event.mouse.MousePositionChangeEvent;
import com.dg.jmge.system.SystemRegistry;
import com.dg.jmge.system.state.StateSystem;

public class MousePositionEventProcessor implements IEventProcessor {
    private StateSystem stateSystemReference = (StateSystem) SystemRegistry.getInstance().findSystem(StateSystem.class);
    //private static final Logger logger = Logger.getLogger(MousePositionEventProcessor.class);

    @Override
    public void process(AbstractEvent event) {
        MousePositionChangeEvent mpce = (MousePositionChangeEvent) event;
        stateSystemReference.updateMousePosition(mpce.getX(), mpce.getY());
        //logger.trace("(" + mpce.getX() + "," + mpce.getY() + ")");
    }
}