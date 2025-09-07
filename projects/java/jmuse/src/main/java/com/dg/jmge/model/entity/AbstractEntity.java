package com.dg.jmge.model.entity;

import com.dg.jmge.model.Color;

public abstract class AbstractEntity {
    protected Color color = null;
    protected boolean visible = true;

    protected AbstractEntity(Color colorInput) {
        color = colorInput;
    }

    protected AbstractEntity(Color colorInput, boolean visibilityInput) {
        color = colorInput;
        visible = visibilityInput;
    }

    public Color getColor() {
        return color;
    }

    public boolean isVisible() {
        return visible;
    }

    public void setVisible(boolean visibilityInput) {
        visible = visibilityInput;
    }
}