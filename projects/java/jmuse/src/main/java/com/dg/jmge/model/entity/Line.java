package com.dg.jmge.model.entity;

import com.dg.jmge.model.Color;
import com.dg.jmge.model.math.Vector3D;

public class Line extends AbstractEntity {
    private Vector3D begin = null;
    private Vector3D end = null;

    public Line(Vector3D beginInput, Vector3D endInput, Color colorInput) {
        super(colorInput);
        begin = beginInput;
        end = endInput;
    }

    public Vector3D getBegin() {
        return begin;
    }

    public Vector3D getEnd() {
        return end;
    }
}