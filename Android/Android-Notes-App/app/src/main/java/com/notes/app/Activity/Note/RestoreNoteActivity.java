package com.notes.app.Activity.Note;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.GradientDrawable;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.text.Html;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.makeramen.roundedimageview.RoundedImageView;

import java.io.InputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

import com.notes.app.Methods.Methods;
import com.notes.app.R;
import com.notes.app.SharedPref.Setting;
import com.notes.app.database.DeleteDatabase;
import com.notes.app.database.NotesDatabase;
import com.notes.app.entities.Note;

public class RestoreNoteActivity extends AppCompatActivity {

    private Methods methods;
    private TextView inpuNoteTitle, inpuNoteSubtitle, inpuNoteText, textDeteTime, textWebURL;
    private RoundedImageView imageNote;
    private String setectedNoteColor;
    private View viewSubtitleIndicator;
    private LinearLayout layoutWebURL;
    private String  setectedImagePath;
    private static final int REQUST_CODE_STORAGE_PERMISSION = 1;
    private static final int REQUST_CODE_SELECT_IMAGE = 2;
    private AlertDialog dialogDeletNote;
    private Note alreadyAvailableNote;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (Setting.Dark_Mode ) {
            setTheme(R.style.AppTheme2);
        } else {
            setTheme(R.style.AppTheme);
        }
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_reatore_note);

        methods = new Methods(this);

        Toolbar toolbar = (Toolbar) findViewById(R.id.reatore_toolbar_note);
        setSupportActionBar(toolbar);
        setTitle(R.string.app_name);

        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        if (Setting.Dark_Mode) {
            getSupportActionBar().setHomeAsUpIndicator(R.drawable.ic_keyboard_backspace_black_24dp);
        } else {
            getSupportActionBar().setHomeAsUpIndicator(R.drawable.ic_keyboard_backspace_black_24dp2);
        }
        toolbar.setNavigationOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onBackPressed();
            }
        });

        inpuNoteTitle = findViewById(R.id.reatore_inputNoteTitle);
        inpuNoteSubtitle = findViewById(R.id.reatore_inputNoteSubtitle);
        inpuNoteText = findViewById(R.id.reatore_inputNote);
        textDeteTime = findViewById(R.id.reatore_textDeteTime);
        viewSubtitleIndicator = findViewById(R.id.reatore_viewSubtitleIndicator);
        imageNote = findViewById(R.id.reatore_imageNote);
        textWebURL = findViewById(R.id.reatore_textWebURL);
        layoutWebURL = findViewById(R.id.reatore_layoutWebURL);

        textDeteTime.setText(
                new SimpleDateFormat("EEEE , dd MMMM yyyy HH:mm a", Locale.getDefault())
                .format(new Date())
        );

        setectedNoteColor = "#333333";
        setectedImagePath = "";

        if (getIntent().getBooleanExtra("isViemOrUpdate",false)){
            alreadyAvailableNote = (Note) getIntent().getSerializableExtra("note");
            setViewOrUpdateNote();
        }

        setSubtitleIndicatorColor();

        LinearLayout adView = findViewById(R.id.adView_reatore);
        methods.showBannerAd(adView);

    }

    private void setViewOrUpdateNote() {
        inpuNoteTitle.setText(alreadyAvailableNote.getTitle());
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.N) {
            inpuNoteText.setText(Html.fromHtml(alreadyAvailableNote.getNoteText(), Html.FROM_HTML_MODE_COMPACT));
        } else {
            inpuNoteText.setText(Html.fromHtml(alreadyAvailableNote.getNoteText()));
        }

        inpuNoteSubtitle.setText(alreadyAvailableNote.getSubtitle());

        textDeteTime.setText(alreadyAvailableNote.getDateTime());

        setectedNoteColor = alreadyAvailableNote.getColor();

        if (alreadyAvailableNote.getImagePath() != null && !alreadyAvailableNote.getImagePath().trim().isEmpty()){
            imageNote.setImageBitmap(BitmapFactory.decodeFile(alreadyAvailableNote.getImagePath()));
            imageNote.setVisibility(View.VISIBLE);
            findViewById(R.id.reatore_imageRemoveImage).setVisibility(View.VISIBLE);
            setectedImagePath = alreadyAvailableNote.getImagePath();
        }

        if (alreadyAvailableNote.getWebLink() != null && !alreadyAvailableNote.getWebLink().trim().isEmpty()){
            textWebURL.setText(alreadyAvailableNote.getWebLink());
            layoutWebURL.setVisibility(View.VISIBLE);
        }


    }

    private void saveNote() {

        final Note note = new  Note();
        note.setTitle(alreadyAvailableNote.getTitle());
        note.setSubtitle(alreadyAvailableNote.getSubtitle());
        note.setNoteText(alreadyAvailableNote.getNoteText());
        note.setDateTime(alreadyAvailableNote.getDateTime());
        note.setColor(setectedNoteColor);
        note.setImagePath(setectedImagePath);

        if (layoutWebURL.getVisibility() == View.VISIBLE){
            note.setWebLink(textWebURL.getText().toString());
        }

        @SuppressLint("StaticFieldLeak")
        class  SaveNoteTask extends AsyncTask<Void, Void, Void> {

            @Override
            protected Void doInBackground(Void... voids) {
                NotesDatabase.getNotesDatabase(getApplicationContext()).noteDao().insertNote(note);
                DeleteDatabase.getNotesDatabase(getApplicationContext()).noteDao().deletNote(alreadyAvailableNote);
                return null;
            }

            @Override
            protected void onPostExecute(Void aVoid) {
                super.onPostExecute(aVoid);
                Intent intent = new Intent();
                intent.putExtra("isNoteDeleted",true);
                setResult(RESULT_OK, intent);
                finish();
            }
        }
        new SaveNoteTask().execute();
    }

    private void setSubtitleIndicatorColor(){
        GradientDrawable gradientDrawable = (GradientDrawable) viewSubtitleIndicator.getBackground();
        gradientDrawable.setColor(Color.parseColor(setectedNoteColor));
    }

    private void selectImage() {
        Intent intent = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        if (intent.resolveActivity(getPackageManager()) != null){
            startActivityForResult(intent, REQUST_CODE_SELECT_IMAGE);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == REQUST_CODE_STORAGE_PERMISSION && grantResults.length > 0){
            if (grantResults[0] == PackageManager.PERMISSION_GRANTED){
                selectImage();
            }else {
                Toast.makeText(this,"Permissions Denied!",Toast.LENGTH_SHORT).show();
            }
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUST_CODE_SELECT_IMAGE && resultCode == RESULT_OK) {
            if (data != null){
                Uri selectedImageUri = data.getData();
                if (selectedImageUri != null){
                    try {

                        InputStream inputStream = getContentResolver().openInputStream(selectedImageUri);
                        Bitmap bitmap = BitmapFactory.decodeStream(inputStream);
                        imageNote.setImageBitmap(bitmap);
                        imageNote.setVisibility(View.VISIBLE);
                        findViewById(R.id.reatore_imageRemoveImage).setVisibility(View.VISIBLE);

                        setectedImagePath = getPathFromUri(selectedImageUri);

                    } catch (Exception e) {
                        e.printStackTrace();
                        Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();

                    }
                }
            }
        }
    }

    private String getPathFromUri(Uri contenUri) {
        String filePath;
        Cursor cursor = getContentResolver()
                .query(contenUri, null, null, null, null);

        if (cursor == null){
            filePath = contenUri.getPath();
        }else {
            cursor.moveToFirst();
            int index = cursor.getColumnIndex("_data");
            filePath =cursor.getString(index);
            cursor.close();
        }
        return  filePath;
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_restore, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(final MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        switch (id){
            case R.id.nav_restore :
                saveNote();
                break;
            case R.id.nav_delete :
                showDeletNoteDialog();
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    private void showDeletNoteDialog() {
        if (dialogDeletNote == null) {
            AlertDialog.Builder builder = new AlertDialog.Builder(RestoreNoteActivity.this);
            View view = LayoutInflater.from(this).inflate(
                    R.layout.layout_delete_note, (ViewGroup) findViewById(R.id.layoutDeleteNoteContainer)
            );
            builder.setView(view);
            dialogDeletNote = builder.create();
            if (dialogDeletNote.getWindow() != null){
                dialogDeletNote.getWindow().setBackgroundDrawable(new ColorDrawable(0));
            }
            view.findViewById(R.id.textDeleteNote).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    @SuppressLint("StaticFieldLeak")
                    class DeleteNoteTask extends AsyncTask<Void, Void, Void>{

                        @Override
                        protected void onPreExecute() {
                            super.onPreExecute();
                        }

                        @Override
                        protected Void doInBackground(Void... voids) {
                            DeleteDatabase.getNotesDatabase(getApplicationContext()).noteDao()
                                    .deletNote(alreadyAvailableNote);
                            return null;
                        }

                        @Override
                        protected void onPostExecute(Void aVoid) {
                            super.onPostExecute(aVoid);
                            Intent intent = new Intent();
                            intent.putExtra("isNoteDeleted",true);
                            setResult(RESULT_OK, intent);
                            dialogDeletNote.dismiss();
                            finish();
                        }
                    }

                    new DeleteNoteTask().execute();
                }
            });

            view.findViewById(R.id.textCancel).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    dialogDeletNote.dismiss();
                }
            });
        }

        dialogDeletNote.show();
    }

}