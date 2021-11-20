package com.hllwrld.nativebitmap;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;

import com.hllwrld.nativebitmap.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'nativebitmap' library on application startup.
    static {
        System.loadLibrary("nativebitmap");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        BitmapFactory.Options options = new BitmapFactory.Options();

        options.inMutable = true;

        options.inPreferredConfig = Bitmap.Config.ARGB_8888;
        Bitmap src = BitmapFactory.decodeResource(getResources(), R.drawable.a, options);
        Log.d("stxTest", src.getByteCount() / 1024 +"");




        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        BitmapUtils.grey(src);
        binding.image1.setImageBitmap(src);

       // binding.image2.setImageBitmap(src);


    }

}