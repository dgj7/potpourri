package com.dg.jmge.model.entity.text;

import com.dg.jmge.model.Color;
import com.dg.jmge.model.entity.AbstractEntity;

import java.util.Calendar;

public class FPSText extends AbstractEntity {
    private Text2D text = null;

    private int currentSecond = 0;
    private int previousSecondFps = 0;
    private int fpsAccumulator = 0;

    protected FPSText(Color colorInput) {
        super(colorInput);
        text = new Text2D("", 0, 590);
        currentSecond = Calendar.getInstance().get(Calendar.SECOND);
    }

    public Text2D getText() {
        int calculatedCurrentSecond = Calendar.getInstance().get(Calendar.SECOND);
        if (calculatedCurrentSecond == currentSecond) {
            fpsAccumulator++;
        } else {
            previousSecondFps = fpsAccumulator;
            fpsAccumulator = 0;
            currentSecond = calculatedCurrentSecond;
        }
        text.setString("FPS: " + previousSecondFps);
        return text;
    }
}