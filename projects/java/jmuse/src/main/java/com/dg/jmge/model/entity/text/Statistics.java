package com.dg.jmge.model.entity.text;

import com.dg.jmge.model.Color;
import com.dg.jmge.model.entity.AbstractEntity;

public class Statistics extends AbstractEntity {
    private FPSText fps = null;

    public Statistics() {
        super(new Color(1.0f, 1.0f, 1.0f, 1.0f));
        fps = new FPSText(color);
    }

    public Text2D getFpsText() {
        return fps.getText();
    }
}