package com.dg.jmge.model.entity;

import com.dg.jmge.model.Color;
import com.dg.jmge.model.math.Vector3D;

public class Axes extends AbstractEntity {
    private Line x = null;
    private Line y = null;
    private Line z = null;

    private Color xc = null;
    private Color yc = null;
    private Color zc = null;

    public Axes(int size) {
        super(new Color(0.0f, 0.0f, 0.0f));
        xc = new Color(1.0f, 0.0f, 0.0f);
        Vector3D beginx = Vector3D.createVector(size, 0.0f, 0.0f);
        Vector3D endx = Vector3D.createVector(-size, 0.0f, 0.0f);
        yc = new Color(0.0f, 1.0f, 0.0f);
        Vector3D beginy = Vector3D.createVector(0.0f, size, 0.0f);
        Vector3D endy = Vector3D.createVector(0.0f, -size, 0.0f);
        zc = new Color(0.0f, 0.0f, 1.0f);
        Vector3D beginz = Vector3D.createVector(0.0f, 0.0f, size);
        Vector3D endz = Vector3D.createVector(0.0f, 0.0f, -size);

        x = new Line(beginx, endx, xc);
        y = new Line(beginy, endy, yc);
        z = new Line(beginz, endz, zc);
    }

    public Line getXAxis() {
        return x;
    }

    public Line getYAxis() {
        return y;
    }

    public Line getZAxis() {
        return z;
    }
}