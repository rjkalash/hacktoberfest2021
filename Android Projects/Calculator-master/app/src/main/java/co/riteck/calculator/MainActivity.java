package co.riteck.calculator;

import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    Button btn0,btn1,btn2,btn3,btn4,btn5,btn6,btn7,btn8,btn9,btndot;
    Button btnorien;
    Button btnclearall,btnbackspace,btnpercent,btndivide,btnplus,btnmultiply,btnminus,btnequal;
    TextView tvcalc;
    String tmp;
    String result;
    String operator;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initControl();
        initControlListener();
    }



    private void initControlListener() {
        btn0.setOnClickListener(v -> onNumberButtonClicked("0"));
        btn1.setOnClickListener(v -> onNumberButtonClicked("1"));
        btn2.setOnClickListener(v -> onNumberButtonClicked("2"));
        btn3.setOnClickListener(v -> onNumberButtonClicked("3"));
        btn4.setOnClickListener(v -> onNumberButtonClicked("4"));
        btn5.setOnClickListener(v -> onNumberButtonClicked("5"));
        btn6.setOnClickListener(v -> onNumberButtonClicked("6"));
        btn7.setOnClickListener(v -> onNumberButtonClicked("7"));
        btn8.setOnClickListener(v -> onNumberButtonClicked("8"));
        btn9.setOnClickListener(v -> onNumberButtonClicked("9"));
        btndot.setOnClickListener(v -> onNumberButtonClicked("."));


        btnclearall.setOnClickListener(v -> onClearButtonClicked());
        btnminus.setOnClickListener(v -> onOperatorButtonClicked("-"));
        btnplus.setOnClickListener(v -> onOperatorButtonClicked("+"));
        btnmultiply.setOnClickListener(v -> onOperatorButtonClicked("*"));
        btndivide.setOnClickListener(v -> onOperatorButtonClicked("/"));
        btnpercent.setOnClickListener(v -> onOperatorButtonClicked("%"));
        btnbackspace.setOnClickListener(v -> onBackspaceButtonClicked());

        btnequal.setOnClickListener(v -> onEqualButtonClicked());

    }

    private void onEqualButtonClicked() {
        double res = 0;
        try {
            double number = Double.parseDouble(tmp);
            double number2 = Double.parseDouble(tvcalc.getText().toString());
            switch (operator) {
                case "+":
                    res = number + number2;
                    break;
                case "/":
                    res = number / number2;
                    break;
                case "-":
                    res = number - number2;
                    break;
                case "*":
                    res = number * number2;
                    break;
                case "%":
                    res =number % number2 ;
                    break;


            }
            result = String.valueOf(res);
            tvcalc.setText(result);
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void onOperatorButtonClicked(String operator) {
        tmp = tvcalc.getText().toString();
        onClearButtonClicked();
        this.operator = operator;
    }

    private void onClearButtonClicked() {
        result = "";
        tvcalc.setText("");
    }

    private void onNumberButtonClicked(String pos) {
        result = tvcalc.getText().toString();
        result = result + pos;
        tvcalc.setText(result);
    }




    private void initControl() {
        btn0 = findViewById(R.id.btn0);
        btn1 = findViewById(R.id.btn1);
        btn2 = findViewById(R.id.btn2);
        btn3 = findViewById(R.id.btn3);
        btn4 = findViewById(R.id.btn4);
        btn5 = findViewById(R.id.btn5);
        btn6 = findViewById(R.id.btn6);
        btn7 = findViewById(R.id.btn7);
        btn8 = findViewById(R.id.btn8);
        btn9 = findViewById(R.id.btn9);
        btnbackspace= findViewById(R.id.btnbackspace);
        btnpercent= findViewById(R.id.btnpercent);
        btndot= findViewById(R.id.btndot);
        btnplus = findViewById(R.id.btnplus);
        btnclearall = findViewById(R.id.btnclearall);
        btnminus = findViewById(R.id.btnminus);
        btnmultiply = findViewById(R.id.btnmultiply);
        btndivide = findViewById(R.id.btndivide);
        btnequal = findViewById(R.id.btnequal);
        tvcalc = findViewById(R.id.tvcalc);
        btnorien= findViewById(R.id.btnorien);
    }

    private void onBackspaceButtonClicked() {
            String str=tvcalc.getText().toString();
            if (str.length() >=1 ) {
                str = str.substring(0, str.length() - 1);
                tvcalc.setText(str);
            } else {
                tvcalc.setText("0");
            }
        }


}
