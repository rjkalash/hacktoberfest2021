package com.notes.app.Activity.Note;

import android.Manifest;
import android.annotation.SuppressLint;
import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.GradientDrawable;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.DocumentsContract;
import android.provider.MediaStore;
import android.text.Html;
import android.util.Log;
import android.util.Patterns;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import com.google.android.material.bottomsheet.BottomSheetBehavior;
import com.makeramen.roundedimageview.RoundedImageView;
import com.notes.app.view.NemosoftsText.NemosoftsEditText;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.Random;

import com.notes.app.Methods.Methods;
import com.notes.app.R;
import com.notes.app.SharedPref.Setting;
import com.notes.app.database.DeleteDatabase;
import com.notes.app.database.NotesDatabase;
import com.notes.app.entities.Note;

public class CreateNoteActivity extends AppCompatActivity {


    private Methods methods;
    private EditText inpuNoteTitle, inpuNoteSubtitle;
    private TextView textDeteTime, textWebURL;
    private RoundedImageView imageNote;
    private String setectedNoteColor;
    private View viewSubtitleIndicator;
    private LinearLayout layoutWebURL;
    private String  setectedImagePath;
    private static final int REQUST_CODE_STORAGE_PERMISSION = 1;
    private static final int REQUST_CODE_SELECT_IMAGE = 2;
    private AlertDialog dialogAddURL;
    private AlertDialog dialogDeletNote;
    private AlertDialog dialogExport;

    private Note alreadyAvailableNote;
    private NemosoftsEditText nemosoftsEditText;
    private ImageButton bold, italic, underline, strikethrough, bullet, quote, clear;
    private int generator;
    private LinearLayout llScroll;

    private LinearLayout linearMiscellaneous;
    private BottomSheetBehavior<LinearLayout> bottomSheetBehavior;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (Setting.Dark_Mode ) {
            setTheme(R.style.AppTheme2);
        } else {
            setTheme(R.style.AppTheme);
        }
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_note);

        methods = new Methods(this);

        Toolbar toolbar = findViewById(R.id.create_toolbar_note);
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

        llScroll = findViewById(R.id.llScroll);
        linearMiscellaneous = findViewById(R.id.layoutMiscellaneous);
        bottomSheetBehavior = BottomSheetBehavior.from(linearMiscellaneous);


        inpuNoteTitle = findViewById(R.id.create_inputNoteTitle);
        inpuNoteSubtitle = findViewById(R.id.create_inputNoteSubtitle);
        textDeteTime = findViewById(R.id.create_textDeteTime);
        viewSubtitleIndicator = findViewById(R.id.create_viewSubtitleIndicator);
        imageNote = findViewById(R.id.create_imageNote);
        textWebURL = findViewById(R.id.create_textWebURL);
        layoutWebURL = findViewById(R.id.create_layoutWebURL);



        nemosoftsEditText = (NemosoftsEditText) findViewById(R.id.create_inputNote);
        bold = (ImageButton) findViewById(R.id.bold);
        italic = (ImageButton) findViewById(R.id.italic);
        underline = (ImageButton) findViewById(R.id.underline);
        strikethrough = (ImageButton) findViewById(R.id.strikethrough);
        bullet = (ImageButton) findViewById(R.id.bullet);
        quote = (ImageButton) findViewById(R.id.quote);
        clear = (ImageButton) findViewById(R.id.clear);

        nemosoftsEditText.setSelection(nemosoftsEditText.getEditableText().length());

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

        findViewById(R.id.create_imageRemoveWebURL).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                textWebURL.setText(null);
                layoutWebURL.setVisibility(View.GONE);
            }
        });

        findViewById(R.id.create_imageRemoveImage).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                imageNote.setImageBitmap(null);
                imageNote.setVisibility(View.GONE);
                findViewById(R.id.create_imageRemoveImage).setVisibility(View.GONE);
                setectedImagePath = "";
            }
        });

        initMiscellaneous();
        setSubtitleIndicatorColor();

        LinearLayout adView = findViewById(R.id.adView_create);
        methods.showBannerAd(adView);

        bold.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nemosoftsEditText.bold(!nemosoftsEditText.contains(NemosoftsEditText.FORMAT_BOLD));
            }
        });
        bold.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                Toast.makeText(CreateNoteActivity.this, R.string.toast_bold, Toast.LENGTH_SHORT).show();
                return true;
            }
        });

        italic.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nemosoftsEditText.italic(!nemosoftsEditText.contains(NemosoftsEditText.FORMAT_ITALIC));
            }
        });

        italic.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                Toast.makeText(CreateNoteActivity.this, R.string.toast_italic, Toast.LENGTH_SHORT).show();
                return true;
            }
        });
        underline.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nemosoftsEditText.underline(!nemosoftsEditText.contains(NemosoftsEditText.FORMAT_UNDERLINED));
            }
        });
        underline.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                Toast.makeText(CreateNoteActivity.this, R.string.toast_underline, Toast.LENGTH_SHORT).show();
                return true;
            }
        });
        strikethrough.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nemosoftsEditText.strikethrough(!nemosoftsEditText.contains(NemosoftsEditText.FORMAT_STRIKETHROUGH));
            }
        });
        strikethrough.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                Toast.makeText(CreateNoteActivity.this, R.string.toast_strikethrough, Toast.LENGTH_SHORT).show();
                return true;
            }
        });

        bullet.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nemosoftsEditText.bullet(!nemosoftsEditText.contains(NemosoftsEditText.FORMAT_BULLET));
            }
        });
        bullet.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                Toast.makeText(CreateNoteActivity.this, R.string.toast_bullet, Toast.LENGTH_SHORT).show();
                return true;
            }
        });


        quote.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nemosoftsEditText.quote(!nemosoftsEditText.contains(NemosoftsEditText.FORMAT_QUOTE));
            }
        });

        quote.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                Toast.makeText(CreateNoteActivity.this, R.string.toast_quote, Toast.LENGTH_SHORT).show();
                return true;
            }
        });

        clear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nemosoftsEditText.clearFormats();
            }
        });

        clear.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                Toast.makeText(CreateNoteActivity.this, R.string.toast_format_clear, Toast.LENGTH_SHORT).show();
                return true;
            }
        });


    }

    private void setViewOrUpdateNote() {
        inpuNoteTitle.setText(alreadyAvailableNote.getTitle());
        inpuNoteSubtitle.setText(alreadyAvailableNote.getSubtitle());
        nemosoftsEditText.fromHtml(alreadyAvailableNote.getNoteText());
        textDeteTime.setText(alreadyAvailableNote.getDateTime());

        if (alreadyAvailableNote.getImagePath() != null && !alreadyAvailableNote.getImagePath().trim().isEmpty()){
            imageNote.setImageBitmap(BitmapFactory.decodeFile(alreadyAvailableNote.getImagePath()));
            imageNote.setVisibility(View.VISIBLE);
            findViewById(R.id.create_imageRemoveImage).setVisibility(View.VISIBLE);
            setectedImagePath = alreadyAvailableNote.getImagePath();
        }

        if (alreadyAvailableNote.getWebLink() != null && !alreadyAvailableNote.getWebLink().trim().isEmpty()){
            textWebURL.setText(alreadyAvailableNote.getWebLink());
            layoutWebURL.setVisibility(View.VISIBLE);
        }
    }

    private void saveNote() {
        if (inpuNoteTitle.getText().toString().trim().isEmpty()){
            methods.showSnackBar("Note title can't be empty!","error");
            return;
        }else  if (inpuNoteSubtitle.getText().toString().trim().isEmpty()){
            methods.showSnackBar("Note Subtitle can't be empty!","error");
            return;
        }else if (nemosoftsEditText.getText().toString().trim().isEmpty()){
            methods.showSnackBar("Note can't be empty!","error");
            return;
        }

        final Note note = new  Note();
        note.setTitle(inpuNoteTitle.getText().toString());
        note.setSubtitle(inpuNoteSubtitle.getText().toString());
        note.setNoteText(nemosoftsEditText.toHtml());
        note.setDateTime(textDeteTime.getText().toString());
        note.setColor(setectedNoteColor);
        note.setImagePath(setectedImagePath);

        if (layoutWebURL.getVisibility() == View.VISIBLE){
            note.setWebLink(textWebURL.getText().toString());
        }

        if (alreadyAvailableNote != null){
            note.setId(alreadyAvailableNote.getId());
        }

        @SuppressLint("StaticFieldLeak")
        class  SaveNoteTask extends AsyncTask<Void, Void, Void> {

            @Override
            protected Void doInBackground(Void... voids) {
                NotesDatabase.getNotesDatabase(getApplicationContext()).noteDao().insertNote(note);
                return null;
            }

            @Override
            protected void onPostExecute(Void aVoid) {
                super.onPostExecute(aVoid);
                Intent intent = new Intent();
                setResult(RESULT_OK, intent);
                finish();
            }
        }
        new SaveNoteTask().execute();
    }

    private void initMiscellaneous() {
        linearMiscellaneous.findViewById(R.id.textMiscellaneous).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (bottomSheetBehavior.getState() != BottomSheetBehavior.STATE_EXPANDED){
                    bottomSheetBehavior.setState(BottomSheetBehavior.STATE_EXPANDED);
                }else {
                    bottomSheetBehavior.setState(BottomSheetBehavior.STATE_COLLAPSED);
                }
            }
        });

        final ImageView imageView1 = linearMiscellaneous.findViewById(R.id.imageColor1);
        final ImageView imageView2 = linearMiscellaneous.findViewById(R.id.imageColor2);
        final ImageView imageView3 = linearMiscellaneous.findViewById(R.id.imageColor3);
        final ImageView imageView4 = linearMiscellaneous.findViewById(R.id.imageColor4);
        final ImageView imageView5 = linearMiscellaneous.findViewById(R.id.imageColor5);
        final ImageView imageView6 = linearMiscellaneous.findViewById(R.id.imageColor6);
        final ImageView imageView7 = linearMiscellaneous.findViewById(R.id.imageColor7);

        linearMiscellaneous.findViewById(R.id.imageColor1).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setectedNoteColor = "#333333";
                imageView1.setImageResource(R.drawable.ic_done);
                imageView2.setImageResource(0);
                imageView3.setImageResource(0);
                imageView4.setImageResource(0);
                imageView5.setImageResource(0);
                imageView6.setImageResource(0);
                imageView7.setImageResource(0);
                setSubtitleIndicatorColor();
            }
        });

        linearMiscellaneous.findViewById(R.id.imageColor2).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setectedNoteColor = "#fdbe3b";
                imageView1.setImageResource(0);
                imageView2.setImageResource(R.drawable.ic_done);
                imageView3.setImageResource(0);
                imageView4.setImageResource(0);
                imageView5.setImageResource(0);
                imageView6.setImageResource(0);
                imageView7.setImageResource(0);
                setSubtitleIndicatorColor();
            }
        });

        linearMiscellaneous.findViewById(R.id.imageColor3).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setectedNoteColor = "#E040FB";
                imageView1.setImageResource(0);
                imageView2.setImageResource(0);
                imageView3.setImageResource(R.drawable.ic_done);
                imageView4.setImageResource(0);
                imageView5.setImageResource(0);
                imageView6.setImageResource(0);
                imageView7.setImageResource(0);
                setSubtitleIndicatorColor();
            }
        });

        linearMiscellaneous.findViewById(R.id.imageColor4).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setectedNoteColor = "#3a52fc";
                imageView1.setImageResource(0);
                imageView2.setImageResource(0);
                imageView3.setImageResource(0);
                imageView4.setImageResource(R.drawable.ic_done);
                imageView5.setImageResource(0);
                imageView6.setImageResource(0);
                imageView7.setImageResource(0);
                setSubtitleIndicatorColor();
            }
        });

        linearMiscellaneous.findViewById(R.id.imageColor5).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setectedNoteColor = "#F50057";
                imageView1.setImageResource(0);
                imageView2.setImageResource(0);
                imageView3.setImageResource(0);
                imageView4.setImageResource(0);
                imageView5.setImageResource(R.drawable.ic_done);
                imageView6.setImageResource(0);
                imageView7.setImageResource(0);
                setSubtitleIndicatorColor();
            }
        });

        linearMiscellaneous.findViewById(R.id.imageColor6).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setectedNoteColor = "#00E676";
                imageView1.setImageResource(0);
                imageView2.setImageResource(0);
                imageView3.setImageResource(0);
                imageView4.setImageResource(0);
                imageView5.setImageResource(0);
                imageView6.setImageResource(R.drawable.ic_done);
                imageView7.setImageResource(0);
                setSubtitleIndicatorColor();
            }
        });

        linearMiscellaneous.findViewById(R.id.imageColor7).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setectedNoteColor = "#FF3D00";
                imageView1.setImageResource(0);
                imageView2.setImageResource(0);
                imageView3.setImageResource(0);
                imageView4.setImageResource(0);
                imageView5.setImageResource(0);
                imageView6.setImageResource(0);
                imageView7.setImageResource(R.drawable.ic_done);
                setSubtitleIndicatorColor();
            }
        });

        if (alreadyAvailableNote != null && alreadyAvailableNote.getColor() != null && !alreadyAvailableNote.getColor().trim().isEmpty()){
            switch (alreadyAvailableNote.getColor()){
                case "#333333":
                    setectedNoteColor = "#333333";
                    imageView1.setImageResource(R.drawable.ic_done);
                    imageView2.setImageResource(0);
                    imageView3.setImageResource(0);
                    imageView4.setImageResource(0);
                    imageView5.setImageResource(0);
                    imageView6.setImageResource(0);
                    imageView7.setImageResource(0);
                    setSubtitleIndicatorColor();
                    break;
                case "#fdbe3b":
                    setectedNoteColor = "#fdbe3b";
                    imageView1.setImageResource(0);
                    imageView2.setImageResource(R.drawable.ic_done);
                    imageView3.setImageResource(0);
                    imageView4.setImageResource(0);
                    imageView5.setImageResource(0);
                    imageView6.setImageResource(0);
                    imageView7.setImageResource(0);
                    setSubtitleIndicatorColor();
                    break;
                case "#E040FB":
                    setectedNoteColor = "#E040FB";
                    imageView1.setImageResource(0);
                    imageView2.setImageResource(0);
                    imageView3.setImageResource(R.drawable.ic_done);
                    imageView4.setImageResource(0);
                    imageView5.setImageResource(0);
                    imageView6.setImageResource(0);
                    imageView7.setImageResource(0);
                    setSubtitleIndicatorColor();
                    break;
                case "#3a52fc":
                    setectedNoteColor = "#3a52fc";
                    imageView1.setImageResource(0);
                    imageView2.setImageResource(0);
                    imageView3.setImageResource(0);
                    imageView4.setImageResource(R.drawable.ic_done);
                    imageView5.setImageResource(0);
                    imageView6.setImageResource(0);
                    imageView7.setImageResource(0);
                    setSubtitleIndicatorColor();
                    break;
                case "#F50057":
                    setectedNoteColor = "#F50057";
                    imageView1.setImageResource(0);
                    imageView2.setImageResource(0);
                    imageView3.setImageResource(0);
                    imageView4.setImageResource(0);
                    imageView5.setImageResource(R.drawable.ic_done);
                    imageView6.setImageResource(0);
                    imageView7.setImageResource(0);
                    setSubtitleIndicatorColor();
                    break;
                case "#00E676":
                    setectedNoteColor = "#00E676";
                    imageView1.setImageResource(0);
                    imageView2.setImageResource(0);
                    imageView3.setImageResource(0);
                    imageView4.setImageResource(0);
                    imageView5.setImageResource(0);
                    imageView6.setImageResource(R.drawable.ic_done);
                    imageView7.setImageResource(0);
                    setSubtitleIndicatorColor();
                    break;
                case "#FF3D00":
                    setectedNoteColor = "#FF3D00";
                    imageView1.setImageResource(0);
                    imageView2.setImageResource(0);
                    imageView3.setImageResource(0);
                    imageView4.setImageResource(0);
                    imageView5.setImageResource(0);
                    imageView6.setImageResource(0);
                    imageView7.setImageResource(R.drawable.ic_done);
                    setSubtitleIndicatorColor();
                    break;
            }
        }

        linearMiscellaneous.findViewById(R.id.layoutAddImage).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bottomSheetBehavior.setState(BottomSheetBehavior.STATE_COLLAPSED);
                if (ContextCompat.checkSelfPermission(
                        getApplicationContext(), Manifest.permission.READ_EXTERNAL_STORAGE
                ) != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(
                            CreateNoteActivity.this,
                            new String[]{Manifest.permission.READ_EXTERNAL_STORAGE},
                            REQUST_CODE_STORAGE_PERMISSION
                    );
                }else {
                    selectImage();
                }
            }
        });

        linearMiscellaneous.findViewById(R.id.layoutAddUrl).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bottomSheetBehavior.setState(BottomSheetBehavior.STATE_COLLAPSED);
                showAddURLDialog();
            }
        });

        linearMiscellaneous.findViewById(R.id.layoutExport).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bottomSheetBehavior.setState(BottomSheetBehavior.STATE_COLLAPSED);
                if (ContextCompat.checkSelfPermission(
                        getApplicationContext(), Manifest.permission.WRITE_EXTERNAL_STORAGE
                ) != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(
                            CreateNoteActivity.this,
                            new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},
                            REQUST_CODE_STORAGE_PERMISSION
                    );
                }else {
                    showExportDialog();
                }
            }
        });

        linearMiscellaneous.findViewById(R.id.layoutShareNote).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bottomSheetBehavior.setState(BottomSheetBehavior.STATE_COLLAPSED);
                if (inpuNoteTitle.getText().toString().trim().isEmpty()){
                    methods.showSnackBar("Note title can't be empty!","error");
                }else  if (inpuNoteSubtitle.getText().toString().trim().isEmpty()){
                    methods.showSnackBar("Note can't be empty!","error");
                }else {
                    Intent sendIntent = new Intent();
                    sendIntent.setAction(Intent.ACTION_SEND);
                    sendIntent.putExtra(Intent.EXTRA_TEXT,
                            inpuNoteTitle.getText().toString() + "\n\n" +
                                    textDeteTime.getText().toString() + "\n\n" +
                                    inpuNoteSubtitle.getText().toString() + "\n\n" +
                                    Html.fromHtml(nemosoftsEditText.toHtml()) + "\n" +
                                    "https://play.google.com/store/apps/details?id=" + getPackageName()
                    );
                    sendIntent.setType("text/plain");
                    startActivity(sendIntent);
                }
            }
        });

        if (alreadyAvailableNote != null){
            linearMiscellaneous.findViewById(R.id.layoutDeleteNote).setVisibility(View.VISIBLE);
            linearMiscellaneous.findViewById(R.id.layoutDeleteNote).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    bottomSheetBehavior.setState(BottomSheetBehavior.STATE_COLLAPSED);
                    showDeletNoteDialog();
                }
            });
        }
    }

    private void showExportDialog() {
        if (dialogExport == null) {
            AlertDialog.Builder builder = new AlertDialog.Builder(CreateNoteActivity.this);
            View view = LayoutInflater.from(this).inflate(
                    R.layout.layout_export_file, (ViewGroup) findViewById(R.id.ll_layoutExport)
            );
            builder.setView(view);
            dialogExport = builder.create();
            if (dialogExport.getWindow() != null){
                dialogExport.getWindow().setBackgroundDrawable(new ColorDrawable(0));
            }
            view.findViewById(R.id.ll_export_image_file).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    dialogExport.dismiss();
                    saveImage();
                }
            });

            view.findViewById(R.id.ll_export_txt_file).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    dialogExport.dismiss();
                    saveResults();
                }
            });

            view.findViewById(R.id.textCancel).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    dialogExport.dismiss();
                }
            });
        }

        dialogExport.show();
    }

    private void saveImage() {
        Bitmap bitmap;
        bitmap= viewToBitmap(llScroll);
        saveImageToExternalStorage(bitmap);
    }

    public Bitmap viewToBitmap(View view) {
        Bitmap bitmap = Bitmap.createBitmap(view.getWidth(), view.getHeight(), Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(bitmap);
        view.draw(canvas);
        return bitmap;
    }

    private void saveImageToExternalStorage(Bitmap finalBitmap) {
        String iconsStoragePath = Environment.getExternalStorageDirectory() + "/" + getString(R.string.app_name);
        File sdIconStorageDir = new File(iconsStoragePath);
        if (!sdIconStorageDir.exists()) {
            sdIconStorageDir.mkdir();
        }
        generator = generatorNumber();
        String fname = "Image_" + generator + ".jpg";
        File file = new File(sdIconStorageDir, fname);

        try {
            FileOutputStream out = new FileOutputStream(file);
            finalBitmap.compress(Bitmap.CompressFormat.JPEG, 100, out);
            out.flush();
            out.close();
            Toast.makeText(this, "Image is created!!!", Toast.LENGTH_SHORT).show();
        } catch (Exception e) {
            e.printStackTrace();
            Toast.makeText(this, "Something wrong: " + e.toString(), Toast.LENGTH_LONG).show();
        }

        // Tell the media scanner about the new file so that it is
        // immediately available to the user.
        MediaScannerConnection.scanFile(this, new String[] { file.toString() }, null,
                new MediaScannerConnection.OnScanCompletedListener() {
                    public void onScanCompleted(String path, Uri uri) {
                        Log.i("ExternalStorage", "Scanned " + path + ":");
                        Log.i("ExternalStorage", "-> uri=" + uri);
                    }
                });

        openGeneratedJPG();
    }

    private void openGeneratedJPG(){
        String iconsStoragePath = Environment.getExternalStorageDirectory() + "/" + getString(R.string.app_name);
        File sdIconStorageDir = new File(iconsStoragePath);
        if (sdIconStorageDir.exists()) {
            String fname = "Image_" + generator + ".jpg";
            File file = new File(sdIconStorageDir, fname);
            Intent intent=new Intent(Intent.ACTION_VIEW);
            Uri uri = Uri.fromFile(file);
            intent.setDataAndType(uri, "image/*");
            intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
            try {
                startActivity(intent);
            } catch(ActivityNotFoundException e) {
                Toast.makeText(CreateNoteActivity.this, "No Application available to view JPG", Toast.LENGTH_LONG).show();
            }
        }
    }

    private int generatorNumber() {
        Random generator = new Random();
        int n = 10000;
        n = generator.nextInt(n);
        return n;
    }


    private void showDeletNoteDialog() {
        if (dialogDeletNote == null) {
            AlertDialog.Builder builder = new AlertDialog.Builder(CreateNoteActivity.this);
            View view = LayoutInflater.from(this).inflate(
                    R.layout.layout_delete_note_move, (ViewGroup) findViewById(R.id.layoutDeleteNoteContainer)
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
                            deleteSaveNote();
                        }

                        @Override
                        protected Void doInBackground(Void... voids) {
                            NotesDatabase.getNotesDatabase(getApplicationContext()).noteDao()
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

    private void setSubtitleIndicatorColor(){
        GradientDrawable gradientDrawable = (GradientDrawable) viewSubtitleIndicator.getBackground();
        switch (setectedNoteColor){
            case "#333333":
                if (Setting.Dark_Mode){
                    gradientDrawable.setColor(Color.parseColor("#ECECEC"));
                }else {
                    gradientDrawable.setColor(Color.parseColor("#121212"));
                }
                break;
            default:
                gradientDrawable.setColor(Color.parseColor(setectedNoteColor));
                break;
        }
    }

    private void selectImage() {
        Intent intent = new Intent();
        intent.setType("image/*");
        intent.setAction(Intent.ACTION_GET_CONTENT);
        startActivityForResult(Intent.createChooser(intent, getResources().getString(R.string.select_image)), REQUST_CODE_SELECT_IMAGE);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == REQUST_CODE_STORAGE_PERMISSION && grantResults.length > 0){
            if (grantResults[0] == PackageManager.PERMISSION_GRANTED){
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
                        findViewById(R.id.create_imageRemoveImage).setVisibility(View.VISIBLE);
                        setectedImagePath = getPathFromUri(selectedImageUri);
                    } catch (Exception e) {
                        e.printStackTrace();
                        Toast.makeText(this, e.getMessage(), Toast.LENGTH_SHORT).show();
                    }
                }
            }
        }
    }

    public String getPathFromUri(Uri uri) {
        try {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT) {
                String filePath = "";
                String wholeID = DocumentsContract.getDocumentId(uri);

                String id = wholeID.split(":")[1];
                String[] column = {MediaStore.Images.Media.DATA};
                String sel = MediaStore.Images.Media._ID + "=?";

                Cursor cursor = getContentResolver().query(MediaStore.Images.Media.EXTERNAL_CONTENT_URI,
                        column, sel, new String[]{id}, null);

                int columnIndex = cursor.getColumnIndex(column[0]);
                if (cursor.moveToFirst()) {
                    filePath = cursor.getString(columnIndex);
                }
                cursor.close();
                return filePath;
            } else {

                if (uri == null) {
                    return null;
                }
                String[] projection = {MediaStore.Images.Media.DATA};
                Cursor cursor = getContentResolver().query(uri, projection, null, null, null);
                if (cursor != null) {
                    int column_index = cursor
                            .getColumnIndexOrThrow(MediaStore.Images.Media.DATA);
                    cursor.moveToFirst();
                    String retunn = cursor.getString(column_index);
                    cursor.close();
                    return retunn;
                }
                return uri.getPath();
            }
        } catch (Exception e) {
            e.printStackTrace();
            if (uri == null) {
                return null;
            }
            String[] projection = {MediaStore.Images.Media.DATA};
            Cursor cursor = getContentResolver().query(uri, projection, null, null, null);
            if (cursor != null) {
                int column_index = cursor
                        .getColumnIndexOrThrow(MediaStore.Images.Media.DATA);
                cursor.moveToFirst();
                String returnn = cursor.getString(column_index);
                cursor.close();
                return returnn;
            }
            return uri.getPath();
        }
    }


    private void showAddURLDialog(){
        if (dialogAddURL == null){
            AlertDialog.Builder builder = new AlertDialog.Builder(CreateNoteActivity.this);
            View view = LayoutInflater.from(this).inflate(
                    R.layout.layout_add_url,
                    (ViewGroup) findViewById(R.id.layoutAddUrlContiner)
            );
            builder.setView(view);

            dialogAddURL = builder.create();
            if (dialogAddURL.getWindow() != null){
                dialogAddURL.getWindow().setBackgroundDrawable(new ColorDrawable(0));
            }

            final EditText inputURL = view.findViewById(R.id.inputUrl);
            inputURL.requestFocus();

            view.findViewById(R.id.textAdd).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    if (inputURL.getText().toString().trim().isEmpty()){
                        Toast.makeText(CreateNoteActivity.this,"Enter URL", Toast.LENGTH_SHORT).show();
                    }else if (!Patterns.WEB_URL.matcher(inputURL.getText().toString()).matches()){
                        Toast.makeText(CreateNoteActivity.this,"Enter Valid URL", Toast.LENGTH_SHORT).show();
                    }else {
                        textWebURL.setText(inputURL.getText().toString());
                        layoutWebURL.setVisibility(View.VISIBLE);
                        dialogAddURL.dismiss();
                    }
                }
            });

            view.findViewById(R.id.textCancel).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    dialogAddURL.dismiss();
                }
            });
        }
        dialogAddURL.show();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_seve, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(final MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        switch (id){
            case R.id.imageSeve :
                saveNote();
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    private void deleteSaveNote() {
        if (inpuNoteTitle.getText().toString().trim().isEmpty()){
            methods.showSnackBar("Note title can't be empty!","error");
            return;
        }else  if (inpuNoteSubtitle.getText().toString().trim().isEmpty()){
            methods.showSnackBar("Note Subtitle can't be empty!","error");
            return;
        }else if (nemosoftsEditText.getText().toString().trim().isEmpty()){
            methods.showSnackBar("Note can't be empty!","error");
            return;
        }

        final Note note = new  Note();
        note.setTitle(inpuNoteTitle.getText().toString());
        note.setSubtitle(inpuNoteSubtitle.getText().toString());
        note.setNoteText(nemosoftsEditText.toHtml());
        note.setDateTime(textDeteTime.getText().toString());
        note.setColor(setectedNoteColor);
        note.setImagePath(setectedImagePath);

        if (layoutWebURL.getVisibility() == View.VISIBLE){
            note.setWebLink(textWebURL.getText().toString());
        }

        if (alreadyAvailableNote != null){
            note.setId(alreadyAvailableNote.getId());
        }

        @SuppressLint("StaticFieldLeak")
        class  DeleteSaveNoteTask extends AsyncTask<Void, Void, Void> {

            @Override
            protected Void doInBackground(Void... voids) {
                DeleteDatabase.getNotesDatabase(getApplicationContext()).noteDao().insertNote(note);
                return null;
            }

            @Override
            protected void onPostExecute(Void aVoid) {
                super.onPostExecute(aVoid);

            }
        }
        new DeleteSaveNoteTask().execute();
    }

    @Override
    public void onBackPressed() {
        if (bottomSheetBehavior!=null && bottomSheetBehavior.getState() != BottomSheetBehavior.STATE_COLLAPSED) {
            bottomSheetBehavior.setState(BottomSheetBehavior.STATE_COLLAPSED);
        } else if (alreadyAvailableNote == null){
            if (inpuNoteTitle.getText().toString().trim().isEmpty()){
                super.onBackPressed();
            }else  if (inpuNoteSubtitle.getText().toString().trim().isEmpty()){
                super.onBackPressed();
            }else if (nemosoftsEditText.getText().toString().trim().isEmpty()){
                super.onBackPressed();
            }else {
                saveNoteOnBackPressed();
            }
        }else {
            super.onBackPressed();
        }
    }

    private void saveNoteOnBackPressed() {
        final Note note = new  Note();
        note.setTitle(inpuNoteTitle.getText().toString());
        note.setSubtitle(inpuNoteSubtitle.getText().toString());
        note.setNoteText(nemosoftsEditText.toHtml());
        note.setDateTime(textDeteTime.getText().toString());
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
                return null;
            }

            @Override
            protected void onPostExecute(Void aVoid) {
                super.onPostExecute(aVoid);
                Intent intent = new Intent();
                setResult(RESULT_OK, intent);
                finish();
            }
        }
        new SaveNoteTask().execute();
    }

    public void saveResults() {
        String textNote = " ";
        String textTitle = " ";
        String textSubtitle =" ";

        if (!nemosoftsEditText.getText().toString().isEmpty()){
            textNote = nemosoftsEditText.getText().toString();
        }
        if (!inpuNoteTitle.getText().toString().isEmpty()){
            textTitle = inpuNoteTitle.getText().toString();
        }
        if (!inpuNoteSubtitle.getText().toString().isEmpty()){
            textSubtitle = inpuNoteSubtitle.getText().toString();
        }

        String text = textTitle+ "\n"
                +"\n"
                +textSubtitle +"\n"
                +"\n"
                +textNote;

        String iconsStoragePath = Environment.getExternalStorageDirectory() + "/" + getString(R.string.app_name);
        File sdIconStorageDir = new File(iconsStoragePath);
        if (!sdIconStorageDir.exists()) {
            sdIconStorageDir.mkdir();
        }
        generator = generatorNumber();
        String fname = "notes_" + generator + ".txt";
        File file = new File(sdIconStorageDir, fname);

        try {
            FileOutputStream out = new FileOutputStream(file);
            out.write(text.getBytes());
            nemosoftsEditText.getText().clear();
            out.flush();
            out.close();
            Toast.makeText(this, "txt is created!!!", Toast.LENGTH_SHORT).show();
        } catch (Exception e) {
            e.printStackTrace();
            Toast.makeText(this, "Something wrong: " + e.toString(), Toast.LENGTH_LONG).show();
        }

    }
}