package com.dg.jmge.model.window;

public class WindowConfiguration {
    private String title = null;
    private int width = 0;
    private int height = 0;
    private boolean visible = false;

    public WindowConfiguration(String titleInput, int widthInput, int heightInput, boolean visibleInput) {
        title = titleInput;
        width = widthInput;
        height = heightInput;
        visible = visibleInput;
    }

    public String getTitle() {
        return title;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public boolean isVisible() {
        return visible;
    }
}