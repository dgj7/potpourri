package com.dg.jmge.system.state;

import com.dg.jmge.model.state.ApplicationState;
import com.dg.jmge.model.state.ButtonState;
import com.dg.jmge.model.state.MousePresenceState;
import com.dg.jmge.system.AbstractSystem;
import org.apache.log4j.Logger;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class StateSystem extends AbstractSystem {
    private static final Logger logger = Logger.getLogger(StateSystem.class);
    private volatile ConcurrentMap<Integer, ButtonState> keyboardMap = new ConcurrentHashMap<Integer, ButtonState>();
    private volatile ConcurrentMap<Integer, ButtonState> mouseMap = new ConcurrentHashMap<Integer, ButtonState>();
    private volatile ApplicationState applicationState = ApplicationState.Off;
    private volatile MousePresenceState mousePresenceState = MousePresenceState.Undefined;
    private volatile int mouseXPosition = 0;
    private volatile int mouseYPosition = 0;

    @Override
    public void start() {
        logger.debug("StateSystem started successfully.");
    }

    @Override
    public void shutdown() {
        logger.debug("StateSystem shut down successfully.");
    }

    public synchronized ButtonState getKeyboardButtonState(Integer key) {
        ButtonState state = keyboardMap.get(key);
        if (state == null)
            state = ButtonState.Released;
        keyboardMap.put(key, state);
        return state;
    }

    public synchronized ButtonState getMouseButtonState(Integer key) {
        ButtonState state = mouseMap.get(key);
        if (state == null)
            state = ButtonState.Released;
        mouseMap.put(key, state);
        return state;
    }

    public synchronized ApplicationState getApplicationState() {
        return applicationState;
    }

    public synchronized void setApplicationState(ApplicationState applicationStateInput) {
        applicationState = applicationStateInput;
    }

    public synchronized MousePresenceState getMousePresenceState() {
        return mousePresenceState;
    }

    public synchronized void setMousePresenceState(MousePresenceState mousePresenceStateInput) {
        mousePresenceState = mousePresenceStateInput;
    }

    public int getMouseXPosition() {
        return mouseXPosition;
    }

    public int getMouseYPosition() {
        return mouseYPosition;
    }

    public void updateMousePosition(int xInput, int yInput) {
        mouseXPosition = xInput;
        mouseYPosition = yInput;
    }
}