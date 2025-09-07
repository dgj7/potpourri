package com.dg.jmge.model.entity.text;

import com.dg.jmge.model.Color;
import com.dg.jmge.model.entity.AbstractEntity;

import java.awt.*;

public abstract class AbstractTextEntity extends AbstractEntity {
    public static final Color DEFAULT_COLOR = new Color(1.0f, 1.0f, 1.0f, 1.0f);
    public static final Font DEFAULT_FONT = new Font(Font.MONOSPACED, Font.PLAIN, 12);

    private String string = null;
    private Font font = null;

    protected AbstractTextEntity(String stringInput, Color colorInput, Font fontInput) {
        super(colorInput);
        string = stringInput;
        font = fontInput;
    }

    public String getString() {
        return string;
    }

    public void setString(String stringInput) {
        string = stringInput;
    }

    public Font getFont() {
        return font;
    }
}