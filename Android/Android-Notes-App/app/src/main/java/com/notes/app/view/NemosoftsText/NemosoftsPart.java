package com.notes.app.view.NemosoftsText;

public class NemosoftsPart {
    private int start;
    private int end;

    public NemosoftsPart(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public int getStart() {
        return start;
    }

    public int getEnd() {
        return end;
    }

    public boolean isValid() {
        return start < end;
    }
}
