package com.notes.app.Activity.DeleteActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.MenuItem;
import android.widget.LinearLayout;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.StaggeredGridLayoutManager;

import java.util.ArrayList;
import java.util.List;

import com.notes.app.Activity.MainActivity;
import com.notes.app.Activity.Note.RestoreNoteActivity;
import com.notes.app.Methods.Methods;
import com.notes.app.R;
import com.notes.app.SharedPref.Setting;
import com.notes.app.adapters.NoteAdapter;
import com.notes.app.database.DeleteDatabase;
import com.notes.app.entities.Note;
import com.notes.app.listeners.InterAdListener;
import com.notes.app.listeners.NotesListener;

public class DeleteActivity extends AppCompatActivity {


    private Methods methods;
    private Toolbar toolbar;
    public  static  final int REQUEST_CODE_ADD_NOTE = 1;
    public  static  final int REQUEST_CODE_UPDATE_NOTE = 2;
    private static final int REQUST_CODE_SHOW_NOTES = 3;
    private RecyclerView notesRecyclerView;
    private List<Note> noteList;
    private NoteAdapter noteAdapter;
    private int noteClickedPostion = -1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (Setting.Dark_Mode) {
            setTheme(R.style.AppTheme2);
        } else {
            setTheme(R.style.AppTheme);
        }
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_delete);

        methods = new Methods(this);

        methods = new Methods(this, new InterAdListener() {
            @Override
            public void onClick(int position, Note note, String type) {
                noteClickedPostion = position;
                Intent intent = new Intent(getApplicationContext(), RestoreNoteActivity.class);
                intent.putExtra("isViemOrUpdate", true);
                intent.putExtra("note", note);
                startActivityForResult(intent, REQUEST_CODE_UPDATE_NOTE);
            }

        });

        toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        setTitle(R.string.recycle_bin);

        getSupportActionBar().setDisplayHomeAsUpEnabled(true);

        notesRecyclerView = findViewById(R.id.deleteRecyclerView);
        notesRecyclerView.setLayoutManager(new StaggeredGridLayoutManager(2, StaggeredGridLayoutManager.VERTICAL));

        noteList = new ArrayList<>();
        noteAdapter = new NoteAdapter(this, noteList, new NotesListener() {
            @Override
            public void onNoteClicked(Note note, int position) {
                methods.showInter(position, note, "");
            }
        });
        notesRecyclerView.setAdapter(noteAdapter);
        getNotes(REQUST_CODE_SHOW_NOTES, false);


        LinearLayout adView = findViewById(R.id.adView_delete);
        methods.showBannerAd(adView);

    }
    private void getNotes(final int resultCode, final  boolean isNoteDeleted){

        @SuppressLint("StaticFieldLeak")
        class GetNotesTask extends AsyncTask<Void, Void, List<Note>> {
            @Override
            protected List<Note> doInBackground(Void... voids) {
                return DeleteDatabase
                        .getNotesDatabase(getApplicationContext())
                        .noteDao().getAllNotes();
            }

            @Override
            protected void onPostExecute(List<Note> notes) {
                super.onPostExecute(notes);
                if (resultCode == REQUST_CODE_SHOW_NOTES){
                    noteList.addAll(notes);
                    noteAdapter.notifyDataSetChanged();
                }else if (resultCode == REQUEST_CODE_ADD_NOTE){
                    noteList.add(0, notes.get(0));
                    noteAdapter.notifyItemInserted(0);
                    notesRecyclerView.smoothScrollToPosition(0);
                }else if (resultCode == REQUEST_CODE_UPDATE_NOTE){
                    noteList.remove(noteClickedPostion);
                    if (isNoteDeleted){
                        noteAdapter.notifyItemRemoved(noteClickedPostion);
                    }else {
                        noteList.add(noteClickedPostion, notes.get(noteClickedPostion));
                        noteAdapter.notifyItemChanged(noteClickedPostion);
                    }
                }
            }
        }
        new GetNotesTask().execute();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem menuItem) {
        switch (menuItem.getItemId()) {
            case android.R.id.home:
                overridePendingTransition(0, 0);
                overridePendingTransition(0, 0);
                startActivity(new Intent(DeleteActivity.this, MainActivity.class));
                finish();
                break;

            default:
                return super.onOptionsItemSelected(menuItem);
        }
        return true;
    }

    @Override
    public void onBackPressed() {
        overridePendingTransition(0, 0);
        overridePendingTransition(0, 0);
        startActivity(new Intent(DeleteActivity.this, MainActivity.class));
        finish();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_CODE_UPDATE_NOTE && resultCode == RESULT_OK){
            if (data != null){
                getNotes(REQUEST_CODE_UPDATE_NOTE,data.getBooleanExtra("isNoteDeleted",true));
            }
        }
    }



}