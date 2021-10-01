package com.notes.app.adapters;

import android.content.Context;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.os.Handler;
import android.os.Looper;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RelativeLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.makeramen.roundedimageview.RoundedImageView;

import java.util.ArrayList;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

import com.notes.app.R;
import com.notes.app.SharedPref.Setting;
import com.notes.app.entities.Note;
import com.notes.app.listeners.NotesListener;

public class NoteAdapter extends RecyclerView.Adapter<NoteAdapter.NoteViewHolder> {

    private Context context;
    private List<Note> notes;
    private NotesListener notesListener;
    private Timer timer;
    private List<Note> noteSource;

    public NoteAdapter(Context context,List<Note> notes, NotesListener notesListener) {
        this.context = context;
        this.notes = notes;
        this.notesListener = notesListener;
        this.noteSource = notes;
    }

    @NonNull
    @Override
    public NoteViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_note, parent, false);
        return new NoteViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(@NonNull NoteViewHolder holder, int position) {
        final Note note = notes.get(position);
        holder.layoutNote.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                notesListener.onNoteClicked(notes.get(position), position);
            }
        });
        int step = 1;
        int final_step = 1;
        for (int i = 1; i < position + 1; i++) {
            if (i == position + 1) {
                final_step = step;
            }
            step++;
        }

        switch (step) {
            case 1:
                holder.item_new.setVisibility(View.VISIBLE);
                break;
            default:
                holder.item_new.setVisibility(View.GONE);
                break;

        }

        holder.textTitle.setText(note.getTitle());
        if (note.getSubtitle().trim().isEmpty()){
            holder.textSubtitle.setVisibility(View.GONE);
        }else {
            holder.textSubtitle.setText(note.getSubtitle());
        }
        holder.textDateTime.setText(note.getDateTime());

        GradientDrawable gradientDrawable = (GradientDrawable) holder.layoutNote.getBackground();
        if (note.getColor() != null){
            switch (note.getColor()){
                case "#333333":
                    if (Setting.Dark_Mode){
                        gradientDrawable.setColor(Color.parseColor("#ECECEC"));
                        holder.textTitle.setTextColor(Color.parseColor("#161616"));
                        holder.textSubtitle.setTextColor(Color.parseColor("#6D6D6D"));
                        holder.textDateTime.setTextColor(Color.parseColor("#6D6D6D"));
                    }else {
                        gradientDrawable.setColor(Color.parseColor("#121212"));
                        holder.textTitle.setTextColor(Color.parseColor("#DBDBDB"));
                        holder.textSubtitle.setTextColor(Color.parseColor("#E9A0A0A0"));
                        holder.textDateTime.setTextColor(Color.parseColor("#E9A0A0A0"));
                    }
                    break;
                default:
                    gradientDrawable.setColor(Color.parseColor(note.getColor()));
                    break;
            }
        }else {
            if (Setting.Dark_Mode){
                gradientDrawable.setColor(Color.parseColor("#ECECEC"));
                holder.textTitle.setTextColor(Color.parseColor("#161616"));
                holder.textSubtitle.setTextColor(Color.parseColor("#6D6D6D"));
                holder.textDateTime.setTextColor(Color.parseColor("#6D6D6D"));
            }else {
                gradientDrawable.setColor(Color.parseColor("#121212"));
                holder.textTitle.setTextColor(Color.parseColor("#DBDBDB"));
                holder.textSubtitle.setTextColor(Color.parseColor("#E9A0A0A0"));
                holder.textDateTime.setTextColor(Color.parseColor("#E9A0A0A0"));
            }
        }

        if (note.getImagePath() != null){
            holder.imageNote.setImageBitmap(BitmapFactory.decodeFile(note.getImagePath()));
            holder.imageNote.setVisibility(View.VISIBLE);
        }else {
            holder.imageNote.setVisibility(View.GONE);
        }
    }

    @Override
    public int getItemCount() {
        return notes.size();
    }

    @Override
    public int getItemViewType(int position) {
        return position;
    }

    static class  NoteViewHolder extends RecyclerView.ViewHolder{

        TextView textTitle, textSubtitle, textDateTime, item_new;
        RelativeLayout layoutNote;
        RoundedImageView imageNote;


        public NoteViewHolder(@NonNull View itemView) {
            super(itemView);

            item_new = itemView.findViewById(R.id.item_new);
            textTitle  = itemView.findViewById(R.id.item_textTitlem);
            textSubtitle  = itemView.findViewById(R.id.item_textSubTitle);
            textDateTime  = itemView.findViewById(R.id.item_textDateTime);
            layoutNote  = itemView.findViewById(R.id.item_layoutNote);
            imageNote  = itemView.findViewById(R.id.item_imageNote);
        }

    }

    public void searchNote(final  String searchKeyword) {
        timer = new Timer();
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                if (searchKeyword.trim().isEmpty()) {
                    notes = noteSource;
                }else {
                    ArrayList<Note> temp = new ArrayList<>();
                    for (Note note : noteSource) {
                        if (note.getTitle().toLowerCase().contains(searchKeyword.toLowerCase())
                                || note.getSubtitle().toLowerCase().contains(searchKeyword.toLowerCase())
                                || note.getNoteText().toLowerCase().contains(searchKeyword.toLowerCase())){
                            temp.add(note);
                        }
                    }
                    notes = temp;
                }

                new Handler(Looper.getMainLooper()).post(new Runnable() {
                    @Override
                    public void run() {
                        notifyDataSetChanged();
                    }
                });
            }
        },500);
    }

    public void cancelTimer() {
        if (timer != null){
            timer.cancel();
        }
    }

}
