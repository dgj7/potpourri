package com.dg.jmge.model.entity.text;

import com.dg.jmge.model.Color;

import java.awt.*;

public class Text2D extends AbstractTextEntity {
    protected int x = 0;
    protected int y = 0;

    public Text2D(String stringInput, Color colorInput, Font fontInput, int xInput, int yInput) {
        super(stringInput, colorInput, fontInput);
    }

    public Text2D(String stringInput, int xInput, int yInput) {
        super(stringInput, AbstractTextEntity.DEFAULT_COLOR, AbstractTextEntity.DEFAULT_FONT);
        x = xInput;
        y = yInput;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}