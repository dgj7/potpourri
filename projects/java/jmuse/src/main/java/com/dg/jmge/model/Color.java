package com.dg.jmge.model;

public class Color {
    private float red;
    private float green;
    private float blue;
    private float alpha;

    public Color(float redInput, float greenInput, float blueInput, float alphaInput) {
        red = redInput;
        green = greenInput;
        blue = blueInput;
        alpha = alphaInput;
    }

    public Color(float redInput, float greenInput, float blueInput) {
        this(redInput, greenInput, blueInput, 0.0f);
    }

    public float getRed() {
        return red;
    }

    public float getGreen() {
        return green;
    }

    public float getBlue() {
        return blue;
    }

    public float getAlpha() {
        return alpha;
    }
}