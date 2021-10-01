package com.notes.app.listeners;

import com.notes.app.entities.Note;

public interface NotesListener {
    void onNoteClicked(Note note, int position);
}
